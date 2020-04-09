//
// Created by nirvash@wincs.cs.bgu.ac.il on 15/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_STOMPFRAME_H
#define BOOST_ECHO_CLIENT_STOMPFRAME_H

#include <string>
#include <unordered_map>

using namespace std;

class StompFrame {
private:
    string command;
    unordered_map<string, string> headers;
    string body;

public:
    StompFrame(string input);
    StompFrame();
    StompFrame(string _command, unordered_map<string, string> _headers, string _body);
    virtual ~StompFrame();
    string getCommand();
    unordered_map<string, string>& getHeaders();
    string getBody();
    void setCommand(string _command);
    void setHeaders(unordered_map<string, string> _headers);
    void addHeader(pair<string, string> header);
    void setBody(string _body);
    string getHeader(string key);
    string getHeaderMap();
    string toString();


};

#endif //BOOST_ECHO_CLIENT_STOMPFRAME_H
