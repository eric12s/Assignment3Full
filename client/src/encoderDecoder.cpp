/*//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#include "encoderDecoder.h"

StompFrame* encoderDecoder::decodeNextByte(unsigned char nextByte) {
    if(nextByte == '\0')
        return popStomp(bytes);

    pushByte(nextByte);
    StompFrame* nullFrame = new StompFrame();
    return nullFrame;
}

vector<unsigned char> encoderDecoder::encode(StompFrame message) {
    string str = message.toString();
    return str;
}

void encoderDecoder::pushByte(unsigned char nextByte) {

}

StompFrame *encoderDecoder::popStomp(vector<unsigned char> data) {
    return ;
}*/
