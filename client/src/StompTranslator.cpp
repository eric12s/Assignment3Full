//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include <UserDatabase.h>
#include "StompTranslator.h"

using std::string;

string StompTranslator:: login(string userName, string passcode){
    string s = "CONNECT\naccept-version:1.2\nhost:stomp.cs.bgu.ac.il\nlogin:" + userName + "\npasscode:" + passcode +"\n\n\n";
    return s;
}
string StompTranslator:: join(string genre, string id, string receipt){
    //TODO:Check if there is space after the id:
    string s = "SUBSCRIBE\ndestination:" + genre + "\nid:" + id + "\nreceipt:" + receipt + "\n\n\n";
    return s;
}
string StompTranslator:: exit(string genre, string id, string receipt){
    string s = "UNSUBSCRIBE\ndestination:" + genre + "\nid:" + id + "\nreceipt:" + receipt+ "\n\n\n";
    return s;
}
string StompTranslator:: add(string genre , string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n" + userName + " has added the book " + bookName +"\n";
    return s;
}
string StompTranslator:: borrow(string genre, string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n" + userName + " wish to borrow " + bookName + "\n";
    return s;
}
string StompTranslator:: return2(string genre, string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n" + "Returning " + bookName + " to " + userName +"\n";
    return s;
}
string StompTranslator:: status(string genre){
    string s = "SEND\ndestination:" + genre + "\n\n" + "book status\n";
    return s;
}
string StompTranslator:: logout(string receipt){
    string s = "DISCONNECT\nreceipt:" + receipt +"\n\n\n";
    return s;
}