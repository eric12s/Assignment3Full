package bgu.spl.net.impl.stomp;
import bgu.spl.net.api.StompMessagingProtocol;
import bgu.spl.net.srv.Connections;
import bgu.spl.net.srv.ConnectionsImpl;

import java.util.HashMap;
import java.util.concurrent.ConcurrentLinkedQueue;

public class StompMessagingProtocolImpl implements StompMessagingProtocol<StompFrame> {
    private boolean shouldTerminate = false;
    private int connectionId;
    private ConnectionsImpl<StompFrame> connections;
    private UsersDatabase db;

    public StompMessagingProtocolImpl(UsersDatabase _db){
        db = _db;
    }

    public void start(int connectionId, Connections<StompFrame> connections) {
        this.connectionId = connectionId;
        this.connections = (ConnectionsImpl)connections;
    }

    public void process(StompFrame message) {
        String command = message.getCommand();
        shouldTerminate = command.equals("DISCONNECT");
        String receiptId = message.getHeader("receipt");

        if("CONNECT".equals(command)) {
            String name = message.getHeader("login");
            String passcode = message.getHeader("passcode");
            if (!db.isExist(name)) {//new user
                db.addUser(new User(name, passcode));
                db.getUser(name).login(connectionId);
                HashMap<String, String> map = new HashMap<>();
                map.put("version", message.getHeader("accept-version"));
                StompFrame msg = new StompFrame("CONNECTED", map, "Login successful!");
                connections.send(connectionId, msg);
            } else {
                String substring = message.toString().substring(0, message.toString().length() - 1);
                if (db.getUser(name).isConnected()) {//already logged in
                    HashMap<String, String> map = new HashMap<>();
                    map.put("message", "Login failed");
                    if (message.getHeader("receipt") != null) {
                        map.put("receipt-id", message.getHeader("receipt"));
                    }
                    StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                            '\n' + substring + "-----" + '\n' + "User already logged in" + '\n' + '\0');
                    connections.send(connectionId, msg);
                    connections.disconnect(connectionId);//TODO:CHECK THIS
                } else if (!passcode.equals(db.getUser(name).getPasscode())) {//Wrong passcode
                    HashMap<String, String> map = new HashMap<>();
                    map.put("message", "Login failed");
                    if (message.getHeader("receipt") != null) {
                        map.put("receipt-id", message.getHeader("receipt"));
                    }
                    StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                            '\n' + substring + "-----" + '\n' + "Wrong password" + '\n' + '\0');
                    connections.send(connectionId, msg);
                    connections.disconnect(connectionId);
                }else {//succeed
                    HashMap<String, String> map = new HashMap<>();
                    map.put("version", message.getHeader("accept-version"));
                    StompFrame msg = new StompFrame("CONNECTED", map, "Login successful!");
                    db.getUser(name).login(connectionId);
                    connections.send(connectionId, msg);
                }
            }
        }
        else if ("SUBSCRIBE".equals(command)) {
            String substring = message.toString().substring(0, message.toString().length() - 1);
            User user = db.getUser(connectionId);
            if (user.isConnected()){
                String dest = message.getHeader("destination");
                String id = message.getHeader("id");
                user.setSubscribe(dest, Integer.parseInt(id));
                connections.addToChannel(dest, connectionId);

                //Send receipt if needed
                if (receiptId != null) {
                    HashMap<String, String> map = new HashMap<>();
                    map.put("receipt-id", message.getHeader("receipt"));
                    StompFrame msg = new StompFrame("receipt", map, "");
                    connections.send(connectionId, msg);
                }
            } else {
                HashMap<String, String> map = new HashMap<>();
                map.put("message", "Can't subscribe");
                if (message.getHeader("receipt") != null) {
                    map.put("receipt-id", message.getHeader("receipt"));
                }
                StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                        '\n' + substring + "-----" + '\n' + "You are not logged in!" + '\n' + '\0');
                connections.send(connectionId, msg);
                connections.disconnect(connectionId);
            }
        }
        else if ("UNSUBSCRIBE".equals(command)) {
            String substring = message.toString().substring(0, message.toString().length() - 1);
            User user = db.getUser(connectionId);
            if(user.isConnected()) {
                user.removeSubscribe(Integer.parseInt(message.getHeader("id")));
                String genre = user.getSubscribe(Integer.parseInt(message.getHeader("id")));
                if (genre != null)
                    connections.removeFromChannel(genre, Integer.parseInt(message.getHeader("id")));

                //Send receipt if needed
                if (receiptId != null) {
                    HashMap<String, String> map = new HashMap<>();
                    map.put("receipt-id", receiptId);
                    StompFrame receipt = new StompFrame("RECEIPT", map, "");
                    connections.send(connectionId, receipt);
                }
            }
            else{
                HashMap<String, String> map = new HashMap<>();
                map.put("message", "Can't unsubscribe");
                if (message.getHeader("receipt") != null) {
                    map.put("receipt-id", message.getHeader("receipt"));
                }
                StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                        '\n' + substring + "-----" + '\n' + "You are not logged in!" + '\n' + '\0');
                connections.send(connectionId, msg);
                connections.disconnect(connectionId);
            }
        }
        else if ("SEND".equals(command)) {
            String substring = message.toString().substring(0, message.toString().length() - 1);
            User user = db.getUser(connectionId);
            if(user.isConnected()) {
                String genre = message.getHeader("destination");
                HashMap<String, String> map = new HashMap<>();
                map.put("subscription", String.valueOf(connectionId));
                map.put("Message-id", connections.useMessageId().toString());
                map.put("destination", genre);
                StompFrame msg = new StompFrame("MESSAGE", map, message.getBody().substring(0, message.getBody().length() - 1));
                connections.send(genre, msg);
                //Send receipt if needed
                if (receiptId != null) {
                    HashMap<String, String> map2 = new HashMap<>();
                    map2.put("receipt-id", receiptId);
                    StompFrame receipt = new StompFrame("RECEIPT", map2, "");
                    connections.send(connectionId, receipt);
                }
            }
            else{
                HashMap<String, String> map = new HashMap<>();
                map.put("message", "Can't send");
                if (message.getHeader("receipt") != null) {
                    map.put("receipt-id", message.getHeader("receipt"));
                }
                StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                        '\n' + substring + "-----" + '\n' + "You are not logged in!" + '\n' + '\0');
                connections.send(connectionId, msg);
                connections.disconnect(connectionId);
            }
        }
        else if ("DISCONNECT".equals(command)) {
            String substring = message.toString().substring(0, message.toString().length() - 1);
            User user = db.getUser(connectionId);
            if(user.isConnected()) {
                user.disconnect();
                if (receiptId != null) {
                    HashMap<String, String> map2 = new HashMap<>();
                    map2.put("receipt-id", receiptId);
                    StompFrame receipt = new StompFrame("RECEIPT", map2, "");
                    connections.send(connectionId, receipt);
                }
                connections.disconnect(connectionId);
            }
            else{
                HashMap<String, String> map = new HashMap<>();
                map.put("message", "Can't disconnect");
                if (message.getHeader("receipt") != null) {
                    map.put("receipt-id", message.getHeader("receipt"));
                }
                StompFrame msg = new StompFrame("ERROR", map, "The message:" + '\n' + "-----" +
                        '\n' + substring + "-----" + '\n' + "You are not logged in!" + '\n' + '\0');
                connections.send(connectionId, msg);
                connections.disconnect(connectionId);
            }
        }
    }

    public boolean shouldTerminate() {
        return shouldTerminate;
    }
}
