//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include <UserDatabase.h>
#include "StompClient.h"

using std::string;

string StompClient:: login(string userName, string passcode){
    string s = "CONNECT\naccept-version:1.2\nhost:stomp.cs.bgu.ac.il\nlogin: " + userName + "/npasscode: " + passcode +"\n\n\n";
    return s;
}
string StompClient:: join(string genre,string id, string receipt){
    string s = "SUBSCRIBE\ndestination:" + genre + "\nid: " + id + "\nreceipt: " + receipt + "\n\n\n";
    return s;
}
string StompClient:: exit(string genre, string id, string receipt){
    string s = "SUBSCRIBE\ndestination:" + genre + "\nid:" + id + "\nreceipt:" + receipt+ "\n\n\n";
    return s;
}
string StompClient:: add(string genre ,string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n\n" +  + "has added the book " + bookName +"\n";
    return s;
}
string StompClient:: borrow(string genre,string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n\n" + userName + "wish to borrow " + bookName + "\n";
    return s;
}
string StompClient:: return2(string genre,string userName, string bookName){
    string s = "SEND\ndestination:" + genre + "\n\n\n" + "Returning " + bookName + " to " + " " + userName +"\n";
    return s;
}
string StompClient:: status(string genre){
    string s = "SEND\ndestination:" + genre + "\n\n\n" + "book status\n";
    return s;
}
string StompClient:: logout(string receipt){
    string s = "DISCONNECT\nreceipt:" + receipt +"\n\n\n";
    return s;
}
