//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "MessagingProtocol.h"


MessagingProtocol:: MessagingProtocol(ConnectionHandler& _connectionHandler): connectionHandler(_connectionHandler), userDatabase(
        nullptr){}


void MessagingProtocol:: setUserDatabase (UserDatabase * _userDatabase){
    userDatabase = _userDatabase;
}

void MessagingProtocol:: process(StompFrame stompFrame) {
    if (stompFrame.getCommand() == "CONNECTED") {
        cout << "Login successful" << endl;
        userDatabase->setConnectAnswer(true);
        userDatabase->connect();
        userDatabase->setName(stompFrame.getHeader("login"));
    } else if (stompFrame.getCommand() == "ERROR") {
        userDatabase->disconnect();
        connectionHandler.close();
        if (stompFrame.getHeaders().find("login") != stompFrame.getHeaders().end()) {
            if (stompFrame.getHeader("login") == "User already logged in") {
                cout << "User already logged in" << endl;
            } else {
                cout << "Wrong password" << endl;
            }
        }
        if(stompFrame.getHeaders().find("message") != stompFrame.getHeaders().end()){
            if( stompFrame.getHeader("message") == "malformed frame received")
                cout << "malformed frame send" << endl;
        }
    }
    else if (stompFrame.getCommand() == "RECEIPT") {
        string input = stompFrame.getHeaders()[0];
        if( userDatabase->getActionByReceipt(input).find("joined") != std::string::npos){
            cout << userDatabase->getActionByReceipt(input) << endl;
        }
        if(userDatabase->getActionByReceipt(input).find("exited") != std::string::npos){
            cout << userDatabase->getActionByReceipt(input) << endl;
        }
        if(userDatabase->getActionByReceipt(input).find("disconnected") != std::string::npos){
            userDatabase->disconnect();
        }
    }
    else if (stompFrame.getCommand() == "MESSAGE"){
        string body =stompFrame.getBody();
        string genre;
        for (pair<string,string> head : stompFrame.getHeaders())
        {
            if(head.first.find("destination")!= std::string::npos)
                genre = head.first.substr(head.first.find(':') + 1);
        }
        if(stompFrame.getBody() == "wish to borrow"){
            int index= body.find("borrow");
            string temp = body.substr(index);
            int index2 = body.find(" ");
            string book = body.substr(index2+1);
            if (userDatabase->checkBook(genre, book)) {
                StompFrame addBook;
                string s = "destination:";
                pair<string,string> *p = new pair<string,string>(s,genre);
                addBook.setCommand("SEND");
                addBook.addHeader(*p);
                addBook.setBody(userDatabase->getName() + "has" + book);
                string output = addBook.toString();
                connectionHandler.sendFrameAscii(output, '\0');
            }
         }
        if (body.compare("has added the book") == 0) {
            string s = userDatabase->getName();
            if (body.substr(0, body.find(' '))==s) {
                string temp = body.substr(body.find("book"));
                string book = temp.substr(body.find(" ")+1);
                userDatabase->add(genre, book);
            }
            cout << stompFrame.getBody() << endl;
        }

    }
}