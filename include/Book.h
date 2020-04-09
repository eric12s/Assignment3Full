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

    string getName();

    string getGenre();

    string getPrevOwner();

    bool isAvailable1();

    void setPrevOwner(string prevOwner);

    void setIsAvailable(bool _isAvailable);
};


#endif //BOOST_ECHO_CLIENT_BOOK_H
