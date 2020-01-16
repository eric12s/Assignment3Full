//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_STOMPCLIENT_H
#define BOOST_ECHO_CLIENT_STOMPCLIENT_H

#include <string>
#include <iostream>

using std::string;

class StompClient {
public:
string login(string userName, string passcode);
string join(string genre,string id, string receipt);
string exit(string genre, string id, string receipt);
string add(string genre,string userName ,string bookName);
string borrow(string genre,string userName, string bookName);
string return2(string genre,string userName, string bookName);
string status(string genre);
string logout(string receipt);
};


#endif //BOOST_ECHO_CLIENT_STOMPCLIENT_H
