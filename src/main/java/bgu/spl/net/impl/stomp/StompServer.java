package bgu.spl.net.impl.stomp;

import bgu.spl.net.srv.Server;

public class StompServer {

    public static void main(String[] args) {
        UsersDatabase database = UsersDatabase.getInstance();

        if (args[1].equals("tpc")) {
            Server.threadPerClient(
                    Integer.parseInt(args[0]), //port
                    () -> new StompMessagingProtocolImpl(database), //protocol factory
                    () -> new StompMessageEncoderDecoderImpl() //message encoder decoder factory
            ).serve();
        }

        if(args[1].equals("reactor")){
            Server.reactor(
                    Runtime.getRuntime().availableProcessors(),
                    Integer.parseInt(args[0]),
                    () -> new StompMessagingProtocolImpl(database),
                    StompMessageEncoderDecoderImpl::new
            ).serve();
        }

    }


}
