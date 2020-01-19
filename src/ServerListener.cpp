//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include <ConnectionHandler.h>
#include <boost/thread.hpp>
#include "ServerListener.h"

/*ServerListener::ServerListener(boost::function<void(StompFrame)> _callback, ConnectionHandler* ch) :
                        t1(new boost::thread(boost::bind(&ServerListener::startListen, this))){
    callback = _callback;
    handler = ch;
    isTerminated = false;

}*/

/*ServerListener::ServerListener(boost::function<void(StompFrame)> _callback, ConnectionHandler* ch){
    callback = _callback;
    handler = ch;
    isTerminated = false;
}*/

/*void ServerListener::startListen() {
    while(!isTerminated) {
        string answer;
        handler->getFrameAscii(answer, '\0');
        callback(answer);
    }
}*/

ServerListener::ServerListener(UserDatabase* _user, ConnectionHandler& _handler, MessagingProtocol* _protocol): handler(_handler){
    user = _user;
    isTerminated = false;
    protocol = _protocol;
}

void ServerListener::operator()() {
    while(!isTerminated) {
        string answer = "";
        handler.getLine(answer);
        cout<< "New message: " + answer << endl;
        StompFrame* frame = new StompFrame(answer);
        protocol->process(frame);
        if(user->getActionByReceipt(frame->getHeader("receipt-id")) == "Disconnect")
            isTerminated = true;
    }
}