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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/jojo/CLionProjects/jojo_webserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jojo_webserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jojo_webserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jojo_webserver.dir/flags.make

CMakeFiles/jojo_webserver.dir/main.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jojo_webserver.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/main.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/main.cpp

CMakeFiles/jojo_webserver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/main.cpp > CMakeFiles/jojo_webserver.dir/main.cpp.i

CMakeFiles/jojo_webserver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/main.cpp -o CMakeFiles/jojo_webserver.dir/main.cpp.s

CMakeFiles/jojo_webserver.dir/Util.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/Util.cpp.o: ../Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/jojo_webserver.dir/Util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/Util.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/Util.cpp

CMakeFiles/jojo_webserver.dir/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/Util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/Util.cpp > CMakeFiles/jojo_webserver.dir/Util.cpp.i

CMakeFiles/jojo_webserver.dir/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/Util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/Util.cpp -o CMakeFiles/jojo_webserver.dir/Util.cpp.s

CMakeFiles/jojo_webserver.dir/Server.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/jojo_webserver.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/Server.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/Server.cpp

CMakeFiles/jojo_webserver.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/Server.cpp > CMakeFiles/jojo_webserver.dir/Server.cpp.i

CMakeFiles/jojo_webserver.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/Server.cpp -o CMakeFiles/jojo_webserver.dir/Server.cpp.s

CMakeFiles/jojo_webserver.dir/Timer.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/Timer.cpp.o: ../Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/jojo_webserver.dir/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/Timer.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/Timer.cpp

CMakeFiles/jojo_webserver.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/Timer.cpp > CMakeFiles/jojo_webserver.dir/Timer.cpp.i

CMakeFiles/jojo_webserver.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/Timer.cpp -o CMakeFiles/jojo_webserver.dir/Timer.cpp.s

CMakeFiles/jojo_webserver.dir/Epoll.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/Epoll.cpp.o: ../Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/jojo_webserver.dir/Epoll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/Epoll.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/Epoll.cpp

CMakeFiles/jojo_webserver.dir/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/Epoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/Epoll.cpp > CMakeFiles/jojo_webserver.dir/Epoll.cpp.i

CMakeFiles/jojo_webserver.dir/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/Epoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/Epoll.cpp -o CMakeFiles/jojo_webserver.dir/Epoll.cpp.s

CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o: ../HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/HttpRequest.cpp

CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/HttpRequest.cpp > CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.i

CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/HttpRequest.cpp -o CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.s

CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o: ../HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/HttpResponse.cpp

CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/HttpResponse.cpp > CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.i

CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/HttpResponse.cpp -o CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.s

CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o: ../ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/ThreadPool.cpp

CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/ThreadPool.cpp > CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.i

CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/ThreadPool.cpp -o CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.s

CMakeFiles/jojo_webserver.dir/Buffer.cpp.o: CMakeFiles/jojo_webserver.dir/flags.make
CMakeFiles/jojo_webserver.dir/Buffer.cpp.o: ../Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/jojo_webserver.dir/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jojo_webserver.dir/Buffer.cpp.o -c /usr/jojo/CLionProjects/jojo_webserver/Buffer.cpp

CMakeFiles/jojo_webserver.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jojo_webserver.dir/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/jojo_webserver/Buffer.cpp > CMakeFiles/jojo_webserver.dir/Buffer.cpp.i

CMakeFiles/jojo_webserver.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jojo_webserver.dir/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/jojo_webserver/Buffer.cpp -o CMakeFiles/jojo_webserver.dir/Buffer.cpp.s

# Object files for target jojo_webserver
jojo_webserver_OBJECTS = \
"CMakeFiles/jojo_webserver.dir/main.cpp.o" \
"CMakeFiles/jojo_webserver.dir/Util.cpp.o" \
"CMakeFiles/jojo_webserver.dir/Server.cpp.o" \
"CMakeFiles/jojo_webserver.dir/Timer.cpp.o" \
"CMakeFiles/jojo_webserver.dir/Epoll.cpp.o" \
"CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o" \
"CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o" \
"CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o" \
"CMakeFiles/jojo_webserver.dir/Buffer.cpp.o"

# External object files for target jojo_webserver
jojo_webserver_EXTERNAL_OBJECTS =

jojo_webserver: CMakeFiles/jojo_webserver.dir/main.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/Util.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/Server.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/Timer.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/Epoll.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/HttpRequest.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/HttpResponse.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/ThreadPool.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/Buffer.cpp.o
jojo_webserver: CMakeFiles/jojo_webserver.dir/build.make
jojo_webserver: CMakeFiles/jojo_webserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable jojo_webserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jojo_webserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jojo_webserver.dir/build: jojo_webserver

.PHONY : CMakeFiles/jojo_webserver.dir/build

CMakeFiles/jojo_webserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jojo_webserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jojo_webserver.dir/clean

CMakeFiles/jojo_webserver.dir/depend:
	cd /usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/jojo/CLionProjects/jojo_webserver /usr/jojo/CLionProjects/jojo_webserver /usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug /usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug /usr/jojo/CLionProjects/jojo_webserver/cmake-build-debug/CMakeFiles/jojo_webserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jojo_webserver.dir/depend

