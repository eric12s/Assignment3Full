//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_USERDATABASE_H
#define BOOST_ECHO_CLIENT_USERDATABASE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Book.h"

using namespace std;

class UserDatabase {
private:
    string username;
    unordered_map<string,vector<string>> topicsAndBooks;
    unordered_map<string,string> ownersPerBook;
    vector<string> wishList;
    bool isActive;
    bool returnAnswer;
    unordered_map<string,string> receiptAndActions;
    vector<Book*> books;

public:
    UserDatabase();
    UserDatabase(string _username);

    unordered_map<string,vector<string>>& getBooksPerTopic();
    unordered_map<string,string>& getOwnersPerBook();
    vector<string>& getWishList();
    bool isInWishL(string name);
    void removeFromWishL(string name);
    string getOwners(string book);
    void addToWishList(string name);
    string getName();
    void connect();
    void disconnect();
    bool isConnected();
    void setUserName(string name);
    string getUserName();
    bool connectAnswer();
    void setConnectAnswer(bool answer);
    string getActionByReceipt(string rId);
    void setActionForReceipt(int receiptId, string action);
    bool checkBook(string topic, string bookName);
    void add(string topic, string bookName, string prevOwner);
    void setName(string _userName);
    void removeBookAvil(string name);
    void returnBook(string name);
    void removeBook(string name);
    string getPrevOwner(string name);
    string getStatus();
};


#endif //BOOST_ECHO_CLIENT_USERDATABASE_H
