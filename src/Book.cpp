//
// Created by nirvash@wincs.cs.bgu.ac.il on 19/01/2020.
//


#include <string>
#include <Book.h>

Book::Book(string _name, string _genre):name(_name), genre(_genre), prevOwner(""), isAvailable(true){}

const std::__cxx11::basic_string<char> &Book::getName() const {
    return name;
}

const std::__cxx11::basic_string<char> &Book::getGenre() const {
    return genre;
}

const std::__cxx11::basic_string<char> &Book::getPrevOwner() const {
    return prevOwner;
}

bool Book::isAvailable1() const {
    return isAvailable;
}

void Book::setPrevOwner(const string &prevOwner) {
    Book::prevOwner = prevOwner;
}

void Book::setIsAvailable(bool isAvailable) {
    Book::isAvailable = isAvailable;
}
