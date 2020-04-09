package bgu.spl.net.srv;


import java.io.IOException;
import java.util.Enumeration;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ConnectionsImpl<T> implements Connections<T> {

    private ConcurrentHashMap<String, ConcurrentLinkedQueue<Integer>> channels;
    private AtomicInteger id = new AtomicInteger(-1);
    private ConcurrentHashMap<Integer, ConnectionHandler<T>> connectionsMap;
    private AtomicInteger messageId = new AtomicInteger(0);
    private final ReentrantReadWriteLock connectionsMapLock = new ReentrantReadWriteLock();
    private final ReentrantReadWriteLock channelsLock = new ReentrantReadWriteLock();
    private final Lock connectionsMapRead = connectionsMapLock.readLock();
    private final Lock connectionsMapWrite = connectionsMapLock.writeLock();
    private final Lock channelsRead = channelsLock.readLock();
    private final Lock channelsWrite = channelsLock.writeLock();

    public ConnectionsImpl() {
        connectionsMap = new ConcurrentHashMap<>();
        channels = new ConcurrentHashMap<>();
    }

    @Override
    public boolean send(int connectionId, T msg) {
        connectionsMapRead.lock();
        ConnectionHandler temp = connectionsMap.get(connectionId);
        connectionsMapRead.unlock();
        if   (temp == null)
            return false;

        temp.send(msg);
        return true;
    }

    @Override
    public void send(String channel, T msg) {
        channelsWrite.lock();
        channels.putIfAbsent(channel, new ConcurrentLinkedQueue<>());
        for (Integer temp : channels.get(channel)) {
            ConnectionHandler tempCH = connectionsMap.get(temp);
            if (tempCH != null)
                tempCH.send(msg);
        }
        channelsWrite.unlock();

    }

    @Override
    public void disconnect(int connectionId) {
        connectionsMapRead.lock();
        ConnectionHandler tempCH = connectionsMap.get(connectionId);
        connectionsMapRead.unlock();
        try {
            tempCH.close();  // we close here the connectionHandler
        } catch (IOException e) {
        }
        connectionsMapWrite.lock();
        connectionsMap.remove(connectionId); // we delete here the user from the map
        connectionsMapWrite.unlock();
    }

    public void disconnect2(int connectionId) {
        disconnect(connectionId);
        channelsRead.lock();
        Enumeration e = channels.elements();
        channelsRead.unlock();
        String temp;
        while (e.hasMoreElements()) {
            temp = (String) e.nextElement();
            //TODO:Check this lock
            channelsWrite.lock();
            for (Integer a : channels.get(temp)) {
                if (a.equals(connectionId))
                    channels.get(temp).remove(a); //remove subscriber from the channel
            }
            if (channels.get(temp).isEmpty())  // if the channel is empty delete
                channels.remove(temp);
            channelsWrite.unlock();
        }
    }

    public int add(ConnectionHandler<T> ch) {
        int id2= id.incrementAndGet();
        connectionsMap.putIfAbsent(id2, ch);
        return id2;
    }

    public void addToChannel(String genre , Integer connectionId) {
        channelsRead.lock();
        ConcurrentLinkedQueue<Integer> temp = channels.get(genre);
        channelsRead.unlock();
        channelsWrite.lock();
        if (temp != null) {
            temp.add(connectionId);
        }
        else {
            //TODO: Check this lock
            temp = new ConcurrentLinkedQueue<>();
            channels.putIfAbsent(genre, temp);
            temp.add(connectionId);
        }
        channelsWrite.unlock();
    }

    public void removeFromChannel(String genre, Integer connectionId){
        channelsRead.lock();
        ConcurrentLinkedQueue<Integer> temp = channels.get(genre);
        channelsRead.unlock();
        channelsWrite.lock();
        if(temp != null){
            temp.remove(connectionId);
        }
        channelsWrite.unlock();
    }

    public Integer useMessageId() {
        return messageId.incrementAndGet();
    }

    public boolean isExist(int id){
        connectionsMapRead.lock();
        boolean b =  connectionsMap.contains(id);
        connectionsMapRead.unlock();
        return b;
    }
}
