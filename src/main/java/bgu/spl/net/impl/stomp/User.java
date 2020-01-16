package bgu.spl.net.impl.stomp;

import java.util.HashMap;

public class User {
    private String name;
    private String passcode;
    private int connectionId;
    private HashMap<String, Integer> sub;
    private boolean isConnected;

    public User(String _name, String _passcode) {
        name = _name;
        passcode = _passcode;
        connectionId = -1;
        sub = new HashMap<>();
        isConnected = false;
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPasscode() {
        return passcode;
    }

    public void setPasscode(String passcode) {
        this.passcode = passcode;
    }

    public int getConnectionId() {
        return connectionId;
    }

    public void setConnectionId(int connectionId) {
        this.connectionId = connectionId;
    }

    public HashMap<String, Integer> getSub() {
        return sub;
    }

    public void setSubscribe(String genre, Integer i) {
        sub.putIfAbsent(genre, i);
    }

    public String getSubscribe(Integer i) {
        for (String genre : sub.keySet()) {
            if (sub.get(genre) == i)
                return genre;
        }
        return null;
    }

    public void removeSubscribe(Integer i) {
        sub.remove(i);
    }

    public void login(int id) {
        connectionId = id;
        isConnected = true;
    }

    public void disconnect() {
        isConnected = false;
    }

    public boolean isConnected() {
        return isConnected;
    }


}
