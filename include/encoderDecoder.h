//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_ENCODERDECODER_H
#define BOOST_ECHO_CLIENT_ENCODERDECODER_H

#include "StompFrame.h"
#include "vector"

using namespace std;

class encoderDecoder {
private:
    int len = 0;
    vector<unsigned char> bytes;

public:

    StompFrame *decodeNextByte(unsigned char nextByte);
    vector<unsigned char> encode(StompFrame message);
    void pushByte(unsigned char nextByte);
    StompFrame* popStomp(vector<unsigned char> data);
};




#endif //BOOST_ECHO_CLIENT_ENCODERDECODER_H
