//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "MessagingProtocol.h"


MessagingProtocol:: MessagingProtocol(ConnectionHandler& _connectionHandler): connectionHandler(_connectionHandler), userDatabase(
        nullptr), ioListener(nullptr){
}

void MessagingProtocol:: setUserDatabase (UserDatabase * _userDatabase){
    userDatabase = _userDatabase;
}

void MessagingProtocol:: process(StompFrame *stompFrame) {
    if (stompFrame->getCommand() == "CONNECTED") {
        userDatabase->setConnectAnswer(true);
        userDatabase->connect();
    } else if (stompFrame->getCommand() == "ERROR") {
        userDatabase->disconnect();
        connectionHandler.close();
        if (stompFrame->getHeaders().find("login") != stompFrame->getHeaders().end()) {
            if (stompFrame->getHeader("login") == "User already logged in") {
                cout << "User already logged in" << endl;
            } else {
                cout << "Wrong password" << endl;
            }
        }
        if(stompFrame->getHeaders().find("message") != stompFrame->getHeaders().end()){
            if( stompFrame->getHeader("message") == "malformed frame received")
                cout << "malformed frame sent" << endl;
        }
    }
    else if (stompFrame->getCommand() == "RECEIPT") {
        string input = stompFrame->getHeader("receipt-id");
        if( userDatabase->getActionByReceipt(input).find("joined") != std::string::npos){
            cout << userDatabase->getActionByReceipt(input) << endl;
        }
        if(userDatabase->getActionByReceipt(input).find("exited") != std::string::npos){
            cout << userDatabase->getActionByReceipt(input) << endl;
        }
        if(userDatabase->getActionByReceipt(input).find("disconnected") != std::string::npos){
            userDatabase->disconnect();
            cout << "diconnected" << endl;
        }
    }
    else if (stompFrame->getCommand() == "MESSAGE"){
        string body =stompFrame->getBody();
        string genre;
        if(stompFrame->getHeaders().find("destination") != stompFrame->getHeaders().end()){
            genre = stompFrame->getHeader("destination");
        }
        /*for (pair<string,string> head : stompFrame->getHeaders())
        {
            if(head.first.find("destination")!= std::string::npos)
                genre = head.first.substr(head.first.find(':') + 1);
        }*/
        if(body.find("wish to borrow") != string::npos){
            int index= body.find("borrow");
            string temp = body.substr(index);
            int index2 = body.find(" ");
            string book = temp.substr(7);
            if (userDatabase->checkBook(genre, book)) {
                StompFrame addBook;
                string s = "destination";
                pair<string,string> *p = new pair<string,string>(s,genre);
                addBook.setCommand("SEND");
                addBook.addHeader(*p);
                addBook.setBody(userDatabase->getName() + " has " + book);
                string output = addBook.toString();
                //connectionHandler.sendFrameAscii(output, '\0');
                ioListener->gotMessage(&addBook);
            }
         }

        if (body.find("has") != string::npos && body.find("added") == string::npos) {
            string owner = body.substr(2, body.find(' ') - 2);
            body = body.substr(body.find(' ') + 1);
            string book = body.substr(body.find(' ') + 1);
            if(userDatabase->isInWishL(book)){
                userDatabase->removeFromWishL(book);
                string destination = stompFrame->getHeader("destination");
                userDatabase->add(destination, book, owner);

                //send message to announce that he takes the book
                StompFrame addBook;
                addBook.setCommand("SEND");
                addBook.addHeader(make_pair("destination",destination));
                addBook.setBody("Taking " + book + " from " + owner);
                //string output = addBook.toString();
                //connectionHandler.sendLine(output);
                ioListener->gotMessage(&addBook);
            }
        }

        if (body.find("Taking") != string::npos) {
            body = body.substr(body.find(' ') + 1);
            string book = body.substr(0, body.find(' '));
            body = body.substr(body.find(' ') + 1);
            string name = body.substr(body.find(' ') + 1);

            if(name == userDatabase->getName()){
                userDatabase->removeBookAvil(book);
            }
        }

//        if (body.find("has added the book") != string::npos) {
//            string s = userDatabase->getName();
//            if (body.substr(0, body.find(' ')) == s) {
//                string temp = body.substr(body.find("book"));
//                string book = temp.substr(body.find(" ")+1);
//                userDatabase->add(genre, book, "");
//            }
//            cout << stompFrame->getBody() << endl;
//        }

        if (body.find("Returning") != string::npos) {
            body = body.substr(body.find(' ') + 1);
            string book = body.substr(0, body.find(' '));
            body = body.substr(body.find(' ') + 1);
            body = body.substr(body.find(' ') + 1);
            string name = body.substr(0, body.find(' '));
            if(name == userDatabase->getName()){
                userDatabase->returnBook(book);
            }
        }

        if(body.find("status") != string::npos){
            StompFrame status;
            status.setCommand("SEND");
            string genre = stompFrame->getHeader("destination");
            status.addHeader(make_pair("destination", genre));
            string body = userDatabase->getName() + ":" + userDatabase->getStatus();
            status.setBody(body);
            ioListener->gotMessage(&status);
        }
    }
}

void MessagingProtocol::setIOListener(IOListener *_ioListener) {
    ioListener = _ioListener;
}
