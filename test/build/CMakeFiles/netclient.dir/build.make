# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fang/work/template/0223/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fang/work/template/0223/test/build

# Include any dependencies generated for this target.
include CMakeFiles/netclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/netclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/netclient.dir/flags.make

CMakeFiles/netclient.dir/client.cpp.o: CMakeFiles/netclient.dir/flags.make
CMakeFiles/netclient.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/netclient.dir/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netclient.dir/client.cpp.o -c /home/fang/work/template/0223/test/client.cpp

CMakeFiles/netclient.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netclient.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/test/client.cpp > CMakeFiles/netclient.dir/client.cpp.i

CMakeFiles/netclient.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netclient.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/test/client.cpp -o CMakeFiles/netclient.dir/client.cpp.s

CMakeFiles/netclient.dir/client.cpp.o.requires:

.PHONY : CMakeFiles/netclient.dir/client.cpp.o.requires

CMakeFiles/netclient.dir/client.cpp.o.provides: CMakeFiles/netclient.dir/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/netclient.dir/build.make CMakeFiles/netclient.dir/client.cpp.o.provides.build
.PHONY : CMakeFiles/netclient.dir/client.cpp.o.provides

CMakeFiles/netclient.dir/client.cpp.o.provides.build: CMakeFiles/netclient.dir/client.cpp.o


# Object files for target netclient
netclient_OBJECTS = \
"CMakeFiles/netclient.dir/client.cpp.o"

# External object files for target netclient
netclient_EXTERNAL_OBJECTS =

netclient: CMakeFiles/netclient.dir/client.cpp.o
netclient: CMakeFiles/netclient.dir/build.make
netclient: CMakeFiles/netclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fang/work/template/0223/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable netclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/netclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/netclient.dir/build: netclient

.PHONY : CMakeFiles/netclient.dir/build

CMakeFiles/netclient.dir/requires: CMakeFiles/netclient.dir/client.cpp.o.requires

.PHONY : CMakeFiles/netclient.dir/requires

CMakeFiles/netclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/netclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/netclient.dir/clean

CMakeFiles/netclient.dir/depend:
	cd /home/fang/work/template/0223/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fang/work/template/0223/test /home/fang/work/template/0223/test /home/fang/work/template/0223/test/build /home/fang/work/template/0223/test/build /home/fang/work/template/0223/test/build/CMakeFiles/netclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/netclient.dir/depend
