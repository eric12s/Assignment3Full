# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /users/studs/bsc/2020/nirvash/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /users/studs/bsc/2020/nirvash/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Boost_Echo_Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Boost_Echo_Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Boost_Echo_Client.dir/flags.make

CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o: ../src/ConnectionHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ConnectionHandler.cpp

CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ConnectionHandler.cpp > CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ConnectionHandler.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o: ../src/echoClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/echoClient.cpp

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/echoClient.cpp > CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/echoClient.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o: ../src/StompFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompFrame.cpp

CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompFrame.cpp > CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompFrame.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o: ../src/encoderDecoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/encoderDecoder.cpp

CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/encoderDecoder.cpp > CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/encoderDecoder.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o: ../src/UserDatabase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/UserDatabase.cpp

CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/UserDatabase.cpp > CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/UserDatabase.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o: ../src/IOListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/IOListener.cpp

CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/IOListener.cpp > CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/IOListener.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o: ../src/MessagingProtocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/MessagingProtocol.cpp

CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/MessagingProtocol.cpp > CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/MessagingProtocol.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o: ../src/ServerListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ServerListener.cpp

CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ServerListener.cpp > CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/ServerListener.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o: ../src/StompTranslator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompTranslator.cpp

CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompTranslator.cpp > CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/StompTranslator.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o: ../src/Book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o -c /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/Book.cpp

CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/Book.cpp > CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/src/Book.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.s

# Object files for target Boost_Echo_Client
Boost_Echo_Client_OBJECTS = \
"CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o"

# External object files for target Boost_Echo_Client
Boost_Echo_Client_EXTERNAL_OBJECTS =

Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/ConnectionHandler.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/StompFrame.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/encoderDecoder.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/UserDatabase.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/IOListener.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/MessagingProtocol.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/ServerListener.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/StompTranslator.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/Book.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/build.make
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Boost_Echo_Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Boost_Echo_Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Boost_Echo_Client.dir/build: Boost_Echo_Client

.PHONY : CMakeFiles/Boost_Echo_Client.dir/build

CMakeFiles/Boost_Echo_Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Boost_Echo_Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Boost_Echo_Client.dir/clean

CMakeFiles/Boost_Echo_Client.dir/depend:
	cd /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug /users/studs/bsc/2020/nirvash/Downloads/assignment3/Boost_Echo_Client/cmake-build-debug/CMakeFiles/Boost_Echo_Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Boost_Echo_Client.dir/depend

