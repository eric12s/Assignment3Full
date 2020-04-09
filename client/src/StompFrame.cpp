#include "StompFrame.h"

StompFrame::StompFrame() {}
StompFrame::StompFrame(string input) {
    int loc = input.find('\n');
    command = input.substr(0, loc);
    input = input.substr(loc + 1, input.length() - loc + 2);
    while(input.at(0) != '\n'){
        loc = input.find('\n');
        int loc2 = input.find(':');
        string tmp = input.substr(loc2, string::npos);
        headers.insert(make_pair(input.substr(0, loc2), tmp.substr(1 , tmp.find('\n') - 1)));
        input = input.substr(loc + 1);
    }
    input = input.substr(1);
    if(input.length() != 0 && input.at(input.length()-1) == '\n')
        input = input.substr(0, input.length() - 1);
    body = input;
}
StompFrame:: StompFrame(string _command, unordered_map<string, string> _headers, string _body): command(_command), headers(_headers), body(_body) {
}

StompFrame::~StompFrame() {

}

string StompFrame::getCommand() {
    return command;
}

unordered_map<string,string >& StompFrame:: getHeaders() {
    return headers;
}
string StompFrame:: getBody(){
    return body;
}
void StompFrame:: setBody(string _body) {
    body = _body;
}
void StompFrame:: setCommand(string _command){
    command = _command;
}
void StompFrame:: setHeaders(unordered_map<string, string> _headers){
    headers = _headers;
}
void StompFrame:: addHeader(pair<string, string> header){
    headers.insert(header);
}
string StompFrame:: getHeader(string key){
    return headers[key];
}

string StompFrame:: getHeaderMap(){
    string output = "";
    for(auto& key : headers){
        output += key.first + ":" + key.second + '\n';
    }
    output += '\n';
    return output;
}

string StompFrame:: toString(){
    string output = getCommand() + '\n';
    output += getHeaderMap() + '\n' + '\n';
    output += getBody() + '\n';
    return output;
}
