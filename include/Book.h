//
// Created by nirvash@wincs.cs.bgu.ac.il on 19/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_BOOK_H
#define BOOST_ECHO_CLIENT_BOOK_H

#include <string>

using namespace std;


class Book {
private:
    string name;
    string genre;
    string prevOwner;
    bool isAvailable;

public:
    Book(string name, string genre);

    const string &getName() const;

    const string &getGenre() const;

    const string &getPrevOwner() const;

    bool isAvailable1() const;

    void setPrevOwner(const string &prevOwner);

    void setIsAvailable(bool isAvailable);
};


#endif //BOOST_ECHO_CLIENT_BOOK_H
