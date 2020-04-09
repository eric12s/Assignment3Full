package bgu.spl.net.impl.stomp;

import bgu.spl.net.srv.Connections;
import bgu.spl.net.srv.ConnectionsImpl;

import java.util.Iterator;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class UsersDatabase {
    ConcurrentHashMap<String, User> usersMap;
    private final ReentrantReadWriteLock usersMapLock = new ReentrantReadWriteLock();
    private final Lock usersMapRead = usersMapLock.readLock();
    private final Lock usersMapWrite = usersMapLock.writeLock();

    private static class UserDatabaseHolder {
        private static UsersDatabase instance = new UsersDatabase();
    }

    private UsersDatabase() {
        usersMap = new ConcurrentHashMap();
    }


    public static UsersDatabase getInstance(){
        return UserDatabaseHolder.instance;
    }

    public User getUser(int connectionId) {
        User user = null;
        usersMapRead.lock();
        for(User tmp : usersMap.values()){
            if(tmp.getConnectionId() == connectionId)
                user = tmp;
        }
        usersMapRead.unlock();
        return user;
    }

    public User getUser(String name){
        usersMapRead.lock();
        User user = usersMap.get(name);
        usersMapRead.unlock();
        return usersMap.get(name);
    }

    public void addUser(User user){
        usersMap.putIfAbsent(user.getName(), user);
    }

    public User removeUser(User user){
        usersMapWrite.lock();
        User tmp = usersMap.remove(user.getName());
        usersMapWrite.unlock();
        return tmp;
    }

    public boolean isExist(String name){
        usersMapRead.lock();
        boolean b = usersMap.containsKey(name);
        usersMapRead.unlock();
        return b;
    }
}
