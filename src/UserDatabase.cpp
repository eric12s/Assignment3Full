//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "UserDatabase.h"
UserDatabase:: UserDatabase() : username(""),topicsAndBooks(),ownersPerBook(),wishList(),isActive(false),returnAnswer(false), receiptAndActions(), books() {
}

UserDatabase::UserDatabase(const string username) : username(username), topicsAndBooks(),ownersPerBook(),wishList(),isActive(false),returnAnswer(false), receiptAndActions(), books() {}

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

void UserDatabase:: setActionForReceipt(int receiptId, string action){
    receiptAndActions.insert(make_pair(to_string(receiptId), action));
}

bool UserDatabase:: checkBook(string topic, string bookName){
//    bool temp = false;
//    for (string s : topicsAndBooks[topic]){
//        if(s == bookName)
//            temp=true;
//    }
//    return temp;
    for(Book book : books){
        if(book.getName() == bookName && book.isAvailable1())
            return true;
    }
    return false;
}

void UserDatabase:: setName(string _userName){
    username = _userName;
}
void UserDatabase:: add(string topic, string book, string preOwner){
//    bool temp = false;
//    for (pair<string,vector<string>> pair : topicsAndBooks)
//    {
//        if (topic == pair.first)
//        {
//            topicsAndBooks[topic].push_back(book);
//            temp = true;
//        }
//    }
//    if (!temp)
//    {
//        vector<string> *tempBooks = new vector<string>();
//        pair<string,vector<string>> *p = new pair<string,vector<string>>(topic,*tempBooks);
//        topicsAndBooks.insert(*p);
//        topicsAndBooks[topic].push_back(book);
//    }
    Book *book1 = new Book(book, topic);
    if(preOwner != "")
        book1->setPrevOwner(preOwner);

    books.push_back(*book1);
}

 vector<string>& UserDatabase:: getWishList(){
    return wishList;
}

void UserDatabase::addToWishList(string name){
    wishList.push_back(name);
}

bool UserDatabase::isInWishL(string name) {
    for(string book : wishList){
        if(book == name)
            return true;
    }
    return false;
}

void UserDatabase::removeFromWishL(string name) {
    int counter = 0;
    for (auto& book : wishList) {
        if(book == name)
            wishList.erase(wishList.begin()+counter);
        counter++;
    }
}

void UserDatabase::removeBookAvil(string name){
    for(Book book : books){
        if(book.getName() == name)
            book.setIsAvailable(false);
    }
}

void UserDatabase:: returnBook(string name){
    for(Book book : books){
        if(book.getName() == name)
            book.setIsAvailable(true);
    }
}

void UserDatabase:: removeBook(string name){
    int counter = 0;
    for (auto& book : books) {
        if(book.getName() == name)
            books.erase(books.begin()+counter);
        counter++;
    }
}

string UserDatabase::getPrevOwner(string name) {
    for(Book book : books){
        if(book.getName() == name)
            return book.getPrevOwner();
    }
    return "";
}
