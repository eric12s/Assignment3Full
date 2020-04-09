//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_SERVERLISTENER_H
#define BOOST_ECHO_CLIENT_SERVERLISTENER_H

#include <StompFrame.h>
#include <boost/thread.hpp>
#include "MessagingProtocol.h"
#include <queue>

using namespace std;

class ServerListener {
public:

    //ServerListener(boost::function<void(StompFrame)>, ConnectionHandler* handler);
    ServerListener(UserDatabase* user, ConnectionHandler& _handler, MessagingProtocol* _protocol);
    void startListen();
    bool isTerminated;
    void operator()();
    bool getError();


private:
    //function<void(string)> callback;
    UserDatabase* user;
    ConnectionHandler& handler;
    MessagingProtocol* protocol;
    queue<StompFrame> sendQueue;
    //boost::thread t1;
    bool error;
};


#endif //BOOST_ECHO_CLIENT_SERVERLISTENER_H
