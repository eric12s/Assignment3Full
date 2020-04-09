//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_IOLISTENER_H
#define BOOST_ECHO_CLIENT_IOLISTENER_H


#include "ConnectionHandler.h"
#include "StompFrame.h"
#include "UserDatabase.h"
#include "MessagingProtocol.h"

class IOListener {
private:
    bool shouldTerminate;
    ConnectionHandler &connectionHandler;
    UserDatabase *user;
    int id;
    int receiptId;


public:
    IOListener(ConnectionHandler &_connectionHandler, UserDatabase* _user);
    void operator()();
    //string translateInput(string input);
    void gotMessage(StompFrame *frame);
};


#endif //BOOST_ECHO_CLIENT_IOLISTENER_H
