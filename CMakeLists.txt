cmake_minimum_required(VERSION 3.15)
project(Boost_Echo_Client)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/lib -pthread -g -Wall -Weffc++ -std=c++11")

link_libraries("-lboost_system")
include_directories(include)

add_executable(Boost_Echo_Client
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/echoClient.cpp src/StompFrame.cpp include/StompFrame.h src/encoderDecoder.cpp include/encoderDecoder.h src/UserDatabase.cpp include/UserDatabase.h src/IOListener.cpp include/IOListener.h src/MessagingProtocol.cpp include/MessagingProtocol.h src/ServerListener.cpp include/ServerListener.h src/StompClient.cpp include/StompClient.h)
