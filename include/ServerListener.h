//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_SERVERLISTENER_H
#define BOOST_ECHO_CLIENT_SERVERLISTENER_H

#include <StompFrame.h>
#include <boost/thread.hpp>
#include "MessagingProtocol.h"

using namespace std;

class ServerListener {
public:

    //ServerListener(boost::function<void(StompFrame)>, ConnectionHandler* handler);
    ServerListener(ConnectionHandler* handler, MessagingProtocol* _protocol);
    void startListen();
    bool isTerminated;
    void operator()();


private:
    function<void(string)> callback;
    ConnectionHandler* handler;
    MessagingProtocol* protocol;
    //boost::thread t1;

};


#endif //BOOST_ECHO_CLIENT_SERVERLISTENER_H
