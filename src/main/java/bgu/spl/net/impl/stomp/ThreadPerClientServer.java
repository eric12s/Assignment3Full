package bgu.spl.net.impl.stomp;

import bgu.spl.net.api.MessageEncoderDecoder;
import bgu.spl.net.api.StompMessagingProtocol;
import bgu.spl.net.srv.*;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.function.Supplier;

public class ThreadPerClientServer<T> implements Server<T> {
    private final int port;
    private final Supplier<StompMessagingProtocol<T>> protocolFactory;
    private final Supplier<MessageEncoderDecoder<T>> encdecFactory;
    private ServerSocket sock;
    private Connections<T> connections;

    public ThreadPerClientServer(int port, Supplier<StompMessagingProtocol<T>> protocolFactory, Supplier<MessageEncoderDecoder<T>> encdecFactory) {
        this.port = port;
        this.protocolFactory = protocolFactory;
        this.encdecFactory = encdecFactory;
        this.sock = null;
        connections = new ConnectionsImpl<>();
    }

    protected void execute(BlockingConnectionHandler handler) {
        new Thread(handler).run();
    }

    /**
     * The main loop of the server, Starts listening and handling new clients.
     */
    @Override
    public void serve() {
        System.out.println("Server Is On Fire!");
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            this.sock = serverSocket;
            while (!Thread.currentThread().isInterrupted()) {
                System.out.println("Listening...");
                Socket clientSocket = serverSocket.accept();
                System.out.println("accepted connection from:" + clientSocket.getInetAddress() + ":" + clientSocket.getPort());
                StompMessagingProtocol protocol = protocolFactory.get();
                BlockingConnectionHandler<T> connectionHandler = new BlockingConnectionHandler<T>(clientSocket, encdecFactory.get(), protocol);
                int connectionId = connections.add(connectionHandler);
                protocol.start(connectionId, connections);

                execute(connectionHandler);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Server Is On Water!");
    }

    @Override
    public void close() throws IOException {
        if (sock != null)
            sock.close();
    }
}
