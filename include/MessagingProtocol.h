//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H
#define BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H

#include "UserDatabase.h"
#include "StompFrame.h"
#include "ConnectionHandler.h"

class ServerListener;
class MessagingProtocol {
private:
    ConnectionHandler& connectionHandler;
    UserDatabase* userDatabase;


public:
    MessagingProtocol(ConnectionHandler& _connectionHandler);
    void setUserDatabase(UserDatabase * _userDatabase);
    void process(StompFrame *stompFrame);
};



#endif //BOOST_ECHO_CLIENT_MESSAGINGPROTOCOL_H
