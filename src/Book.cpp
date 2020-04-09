//
// Created by nirvash@wincs.cs.bgu.ac.il on 19/01/2020.
//


#include <string>
#include <Book.h>

Book::Book(string _name, string _genre):name(_name), genre(_genre), prevOwner(""), isAvailable(true){}

string Book::getName(){
    return name;
}

string Book::getGenre(){
    return genre;
}

string Book::getPrevOwner(){
    return prevOwner;
}

bool Book::isAvailable1(){
    return isAvailable;
}

void Book::setPrevOwner(string prevOwner) {
    prevOwner = prevOwner;
}

void Book::setIsAvailable(bool _isAvailable) {
    isAvailable = _isAvailable;
}
