//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H
#define BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H

#include "UserDatabase.h"
#include "StompFrame.h"
#include "ConnectionHandler.h"
#include "IOListener.h"
class IOListener;
class ServerListener;
class MessagingProtocol {
private:
    ConnectionHandler& connectionHandler;
    UserDatabase* userDatabase;
    IOListener *ioListener;

public:
    MessagingProtocol(ConnectionHandler& _connectionHandler);
    void setUserDatabase(UserDatabase * _userDatabase);
    void process(StompFrame *stompFrame);
    void setIOListener(IOListener *_ioListener);
};



#endif //BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H
