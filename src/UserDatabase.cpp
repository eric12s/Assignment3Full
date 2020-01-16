//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "UserDatabase.h"
UserDatabase:: UserDatabase() : username(""),topicsAndBooks(),ownersPerBook(),wishList(),isActive(false),returnAnswer(false),receiptAndActions() {
}

UserDatabase::UserDatabase(const string username) : username(username), topicsAndBooks(),ownersPerBook(),wishList(),isActive(false),returnAnswer(false),receiptAndActions() {}

string UserDatabase:: getName(){
     return username;
}
void UserDatabase::connect(){
    isActive = true;
}
void UserDatabase:: disconnect(){
    isActive = false;
}
bool UserDatabase:: isConnected(){
    return isActive;
}
void UserDatabase:: setUserName(string name){
     username = name;
}
string UserDatabase:: getUserName(){
    return username;
}
bool UserDatabase:: connectAnswer(){
    return returnAnswer;
}
void UserDatabase:: setConnectAnswer(bool answer){
    returnAnswer = answer;
}
string UserDatabase:: getActionByReceipt(string rId){
    return receiptAndActions[rId];
}
bool UserDatabase:: checkBook(string topic, string bookName){
    bool temp = false;
    for (string s : topicsAndBooks[topic]){
        if(s == bookName)
            temp=true;
    }
    return temp;
}
void UserDatabase:: setName(string _userName){
    username = _userName;
}
void UserDatabase:: add(string topic, string book){
    bool temp = false;
    for (pair<string,vector<string>> pair : topicsAndBooks)
    {
        if (topic == pair.first)
        {
            topicsAndBooks[topic].push_back(book);
            temp = true;
        }
    }
    if (!temp)
    {
        vector<string> *tempBooks = new vector<string>();
        pair<string,vector<string>> *p = new pair<string,vector<string>>(topic,*tempBooks);
        topicsAndBooks.insert(*p);
        topicsAndBooks[topic].push_back(book);
    }
}
 vector<string>& UserDatabase:: getWishList(){
    return wishList;
}


