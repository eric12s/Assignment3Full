#include <stdlib.h>
#include <ConnectionHandler.h>
#include <thread>
#include <IOListener.h>
#include <iostream>
#include <mutex>
#include <ServerListener.h>
#include <boost/lexical_cast.hpp>
#include <StompTranslator.h>

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/


int main (int argc, char *argv[]) {
    /*if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);*/

    string line;
    getline(cin, line);
    istringstream iss(line);
    string command;
    getline(iss, command, ' ');
    string host;
    string portS;
    getline(iss, host, ':');
    getline(iss, portS, ' ');
    string name;
    string password;
    getline(iss, name, ' ');
    getline(iss, password, ' ');
    short port = -1;
    bool shouldTerminate = (command == "bye");
    try {
        port = boost::lexical_cast<short>(portS);
    }
    catch (boost::bad_lexical_cast &) {
    }
    bool error = true;

    while (error) {
        try {
            port = boost::lexical_cast<short>(portS);
        }
        catch (boost::bad_lexical_cast &) {
        }

        while (host.empty() || port == -1 || command != "login") {
            if (command != "login")
                cout << "You must log in first!" << endl;
            else
                cout << "Wrong host or port!" << endl;

            line = "";
            getline(cin, line);
            istringstream iss(line);
            getline(iss, command, ' ');
            getline(iss, host, ':');
            getline(iss, portS, ' ');
            string name;
            string password;
            getline(iss, name, ' ');
            getline(iss, password, ' ');
            try {
                port = boost::lexical_cast<short>(portS);
            }
            catch (boost::bad_lexical_cast &) {
            }
        }


        ConnectionHandler connectionHandler(host, port);
        if (!connectionHandler.connect()) {
            std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
            connectionHandler.close();
            return 1;
        }


        UserDatabase *user = new UserDatabase(name);
        StompTranslator *stompClient = new StompTranslator();

        StompFrame *frame = new StompFrame(stompClient->login(name, password));
        connectionHandler.sendFrameAscii(frame->toString(), '\0');
        string answer = "";
        connectionHandler.getLine(answer);
        cout << "New message:\n" + answer << endl;
        delete frame;

        if (answer.find("CONNECTED") != string::npos)
            user->connect();

        error = false;

        if (answer.find("ERROR") != string::npos)
            error = true;

        if (!error) {
            IOListener iOListener(connectionHandler, user);
            MessagingProtocol *protocol = new MessagingProtocol(connectionHandler);
            protocol->setUserDatabase(user);
            protocol->setIOListener(&iOListener);
            ServerListener serverListener(user, connectionHandler, protocol);
            std::thread th1(std::ref(iOListener));
            std::thread th2(std::ref(serverListener));

            th1.join();
            th2.join();

            cout << "Theards are done" << endl;
            connectionHandler.close();
        } else {
            connectionHandler.close();
            string line;
            getline(cin, line);
            istringstream iss(line);
            getline(iss, command, ' ');
            //shouldTerminate = (command == "bye");
            host = "";
            portS = "";
            getline(iss, host, ':');
            getline(iss, portS, ' ');
            port = -1;
            getline(iss, name, ' ');
            getline(iss, password, ' ');
        }
    }


	//From here we will see the rest of the ehco client implementation:
   /* while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
		std::string line(buf);
		int len=line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
		// connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;


        // We can use one of three options to read data from the server:
        // 1. Read a fixed number of characters
        // 2. Read a line (up to the newline character using the getline() buffered reader
        // 3. Read up to the null character
        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }

		len=answer.length();
		// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
		// we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }*/
    return 0;
}
