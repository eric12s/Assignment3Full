//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "IOListener.h"
#include "ServerListener.h"
#include <boost/thread.hpp>
#include <thread>
#include <StompTranslator.h>

using namespace std;

/*void IOListener::gotMessage(StompFrame *frame) {
    protocol->process(*frame);
};*/


IOListener::IOListener(ConnectionHandler &_connectionHandler, UserDatabase *_user, MessagingProtocol *_protocol) :
        shouldTerminate(false), connectionHandler(_connectionHandler), user(_user), id(1), receiptId(1),
        protocol(_protocol) {

    //ServerListener serverListener(&IOListener::gotMessage, &_connectionHandler);
    //std::thread th1(std::ref(serverListener));
}

void IOListener::operator()() {
    /*while (!shouldTerminate) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string command;
        getline(iss, command, ' ');
        StompTranslator *stompClient = new StompTranslator;

        if (command == "login") {
            string host;
            string port;
            string username;
            string password;
            getline(iss, host, ':');
            getline(iss, port, ' ');
            getline(iss, username, ' ');
            getline(iss, password, ' ');

            //if(!host.empty() && !port.empty() && !username.empty() && !password.empty())
            StompFrame *frame = new StompFrame(stompClient->login(username, password));
            if (connectionHandler.connect()) {
                connectionHandler.sendFrameAscii(frame->toString(), '\0');
                *//*while(user.connectAnswer()){
                    //TODO:Busy wait, need to solve this

                }*//*
                delete frame;
            }
        } else {
            cout << "You must log in first!" << endl;
        }*/

    while (user->isConnected()) {
        string line;
        string command;
        getline(cin, line);
        istringstream iss(line);
        getline(iss, command, ' ');
        StompFrame *frame;
        StompTranslator *stompClient = new StompTranslator;
        if (command == "login") {
            if (!user->isConnected()) {
                string host;
                string port;
                string username;
                string password;
                getline(iss, host, ':');
                getline(iss, port, ' ');
                getline(iss, username, ' ');
                getline(iss, password, ' ');
                //if(!host.empty() && !port.empty() && !username.empty() && !password.empty())
                frame = new StompFrame(stompClient->login(username, password));
            }
            else{
                cout<<"ERROR User already logged in"<<endl;
            }
        } else if (command == "join") {
            string genre;
            getline(iss, genre, ' ');
            frame = new StompFrame(stompClient->join(genre, to_string(id), to_string(receiptId)));
            user->setActionForReceipt(receiptId, "Joined club " + genre);
            id++;
            receiptId++;
        } else if (command == "exit") {
            string genre;
            getline(iss, genre, ' ');
            frame = new StompFrame(stompClient->exit(genre, to_string(id), to_string(receiptId)));
            user->setActionForReceipt(receiptId, "Joined club " + genre);
            id++;
            receiptId++;
        } else if (command == "add") {
            string genre;
            string bookName;
            getline(iss, genre, ' ');
            getline(iss, bookName, ' ');
            user->add(genre, bookName, "");

            frame = new StompFrame(stompClient->add(genre, user->getName(), bookName));
        } else if (command == "borrow") {
            string genre;
            string bookName;
            getline(iss, genre, ' ');
            getline(iss, bookName, ' ');
            user->addToWishList(bookName);
            frame = new StompFrame(stompClient->borrow(genre, user->getName(), bookName));
        } else if (command == "return") {
            string genre;
            string bookName;
            getline(iss, genre, ' ');
            getline(iss, bookName, ' ');
            string owner = user->getPrevOwner(bookName);
            user->removeBook(bookName);
            frame = new StompFrame(stompClient->return2(genre, owner, bookName));
        } else if (command == "status") {
            string genre;
            getline(iss, genre, ' ');
            frame = new StompFrame(stompClient->status(genre));
        } else if (command == "logout") {
            frame = new StompFrame(stompClient->logout(to_string(receiptId)));
            user->setActionForReceipt(receiptId, "Disconnect");
            receiptId++;
            user->disconnect();
        }

        connectionHandler.sendFrameAscii(frame->toString(), '\0');
        delete frame;

    }
}

/*
string IOListener:: translateInput(string input){
    string translation;
    string first;
    if(input.find(" ") != string::npos)
        first = input.substr(0, input.find(" "));
    else
        first = input;
    input.erase(0, first.length() + 1);
    if(first == "login"){
        input = input.substr(0, input.find(" ") + 1);
        string userName = input.substr(0, input.find(" "));
        input = input.substr(input.find(" ") + 1, string::npos);
        if(input.length() < 1) {
            return "";//TODO:HOW TO MAKE SURE THE INPUT IS VALID
        }
        string passcode = input;
        translation =+ "CONNECT\naccept-version:1.2\nlogin:" + userName + "\npasscode:"+passcode + "\n\n\n\0";
        return translation;
    }
    else if(first == "join"){
        int id2 = id;
        id++;
        int receiptId2 = receiptId;
        receiptId++;
        return "SUBSCRIBE\ndestination:"+input+"\nid:"+to_string(id2)+"\nreceipt:"+to_string(receiptId2)+
        "\n\n\n\0";
    }
    else if(first == "exit"){
        int id2 = id;
        id++;
        int receipt2 = receiptId;
        receiptId++;
        string destination = input.substr(0, input.find(" "));
        return "SUBSCRIBE\ndestination:" + destination + "\nid:" + to_string(id2) + "\nreceipt:" + to_string(receipt2)
        + "\n\n\n\0";
    }
    else if(first == "add"){
        string genre = input.substr(0, input.find(" "));
        input.erase(0, input.length())

    }
}*/
