//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_USERDATABASE_H
#define BOOST_ECHO_CLIENT_USERDATABASE_H

#include <string>
#include <unordered_map>
#include <vector>

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

public:
    UserDatabase();
    UserDatabase(string _username);

    unordered_map<string,vector<string>>& getBooksPerTopic();
    unordered_map<string,string>& getOwnersPerBook();
    vector<string>& getWishList();
    string getOwners(string book);
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
    void add(string topic, string bookName);
    void setName(string _userName);
};


#endif //BOOST_ECHO_CLIENT_USERDATABASE_H
