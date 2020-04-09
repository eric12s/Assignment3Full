package bgu.spl.net.impl.stomp;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class StompFrame {
    private String command;
    private Map<String, String> headerMap = new HashMap<>();
    private String body;

    public StompFrame() {
    }

    public StompFrame(String input) {
        int i = input.indexOf('\n');
        command = input.substring(0, i);
        input = input.substring(i + 1);
        while (input.charAt(0) != '\n') {
            i = input.indexOf('\n');
            int j = input.indexOf(':');
            headerMap.put(input.substring(0, j), input.substring(j + 1, i));
            input = input.substring(i + 1);
        }
        input = input.substring(1);
        if(input.length() != 0 && input.charAt(input.length()-1) == '\n')
            input = input.substring(0, input.length() - 1);
        body = input;
    }

    public StompFrame(String _command, HashMap<String, String> _headerMap, String _body){
        command = _command;
        headerMap = _headerMap;
        body = _body;
    }

    public String toString() {
        String output = getCommand() + '\n' + getHeaderMap() + getBody() + '\0';
        return output;
    }

    public String getCommand(){
        return command;
    }

    public String getHeaderMap() {
        String output = "";
        Set<String> keySet = headerMap.keySet();
        for (String key : keySet) {
            output = output + key + ":" + headerMap.get(key) + '\n';
        }
        output = output + '\n';
        return output;
    }

    public String getBody(){
        String output = body + '\n';
        return output;
    }

    public String getHeader(String key){
        return headerMap.get(key);
    }

    public void setCommand(String command) {
        this.command = command;
    }

    public void setHeaderMap(Map<String, String> headerMap) {
        this.headerMap = headerMap;
    }

    public void setHeader(String key, String value) {
        headerMap.put(key, value);
    }

    public void setBody(String body) {
        this.body = body;
    }

    /*public StompFrame connectedFrame(String header){
        StompFrame frame = new StompFrame();
        frame.setCommand("CONNECTED");
        HashMap<String, String> map = new HashMap<>();
        map.put("version", header);
        setHeaderMap(map);
        setBody("");
        return frame;
    }

    public StompFrame errorFrame(String error, StompFrame message, String explanation){
        StompFrame frame = new StompFrame();
        frame.setCommand("ERROR");
        HashMap<String,String> map = new HashMap<>();
        map.put("message", "error");
        if(message.getHeader("receipt") != null){
            map.put("receipt-id",message.getHeader("receipt"));
        }
        frame.setHeaderMap(map);
        frame.setBody("The message:" + '\n' + "-----" + message.toString().substring(0,message.toString().length()-1) +
                "-----" + '\n' + explanation + '\n' + '\0');
        return frame;
    }

    public StompFrame receiptFrame(StompFrame message){
        StompFrame frame = new StompFrame();
        frame.setCommand("RECEIPT");
        HashMap<String, String> map = new HashMap<>();
        map.put("receipt-id", message.getHeader("receipt"));
        frame.setHeaderMap(map);
        frame.setBody("");
        return frame;
    }

    public StompFrame messageFrame(String _body, Integer subscription, Integer id, Integer destination){
        StompFrame frame = new StompFrame();
        frame.setCommand("MESSAGE");
        HashMap<String, String> map = new HashMap<>();
        map.put("subscription", subscription.toString());
        map.put("Message-id", id.toString());
        map.put("destination", destination.toString());
        frame.setHeaderMap(map);
        frame.setBody(_body);
        return frame;
    }*/
}
