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
CMAKE_SOURCE_DIR = /home/fang/work/template/0223

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fang/work/template/0223/build

# Include any dependencies generated for this target.
include test/CMakeFiles/epollsev.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/epollsev.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/epollsev.dir/flags.make

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o: test/CMakeFiles/epollsev.dir/flags.make
test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o: ../test/epollsev_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epollsev.dir/epollsev_test.cpp.o -c /home/fang/work/template/0223/test/epollsev_test.cpp

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epollsev.dir/epollsev_test.cpp.i"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/test/epollsev_test.cpp > CMakeFiles/epollsev.dir/epollsev_test.cpp.i

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epollsev.dir/epollsev_test.cpp.s"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/test/epollsev_test.cpp -o CMakeFiles/epollsev.dir/epollsev_test.cpp.s

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.requires:

.PHONY : test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.requires

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.provides: test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/epollsev.dir/build.make test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.provides

test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.provides.build: test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o


test/CMakeFiles/epollsev.dir/__/src/log.cpp.o: test/CMakeFiles/epollsev.dir/flags.make
test/CMakeFiles/epollsev.dir/__/src/log.cpp.o: ../src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/epollsev.dir/__/src/log.cpp.o"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epollsev.dir/__/src/log.cpp.o -c /home/fang/work/template/0223/src/log.cpp

test/CMakeFiles/epollsev.dir/__/src/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epollsev.dir/__/src/log.cpp.i"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/log.cpp > CMakeFiles/epollsev.dir/__/src/log.cpp.i

test/CMakeFiles/epollsev.dir/__/src/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epollsev.dir/__/src/log.cpp.s"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/log.cpp -o CMakeFiles/epollsev.dir/__/src/log.cpp.s

test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.requires:

.PHONY : test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.requires

test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.provides: test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/epollsev.dir/build.make test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.provides.build
.PHONY : test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.provides

test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.provides.build: test/CMakeFiles/epollsev.dir/__/src/log.cpp.o


test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o: test/CMakeFiles/epollsev.dir/flags.make
test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o: ../src/epollsev.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o -c /home/fang/work/template/0223/src/epollsev.cpp

test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epollsev.dir/__/src/epollsev.cpp.i"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/epollsev.cpp > CMakeFiles/epollsev.dir/__/src/epollsev.cpp.i

test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epollsev.dir/__/src/epollsev.cpp.s"
	cd /home/fang/work/template/0223/build/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/epollsev.cpp -o CMakeFiles/epollsev.dir/__/src/epollsev.cpp.s

test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.requires:

.PHONY : test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.requires

test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.provides: test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/epollsev.dir/build.make test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.provides.build
.PHONY : test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.provides

test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.provides.build: test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o


# Object files for target epollsev
epollsev_OBJECTS = \
"CMakeFiles/epollsev.dir/epollsev_test.cpp.o" \
"CMakeFiles/epollsev.dir/__/src/log.cpp.o" \
"CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o"

# External object files for target epollsev
epollsev_EXTERNAL_OBJECTS =

../bin/epollsev: test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o
../bin/epollsev: test/CMakeFiles/epollsev.dir/__/src/log.cpp.o
../bin/epollsev: test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o
../bin/epollsev: test/CMakeFiles/epollsev.dir/build.make
../bin/epollsev: test/CMakeFiles/epollsev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/epollsev"
	cd /home/fang/work/template/0223/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epollsev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/epollsev.dir/build: ../bin/epollsev

.PHONY : test/CMakeFiles/epollsev.dir/build

test/CMakeFiles/epollsev.dir/requires: test/CMakeFiles/epollsev.dir/epollsev_test.cpp.o.requires
test/CMakeFiles/epollsev.dir/requires: test/CMakeFiles/epollsev.dir/__/src/log.cpp.o.requires
test/CMakeFiles/epollsev.dir/requires: test/CMakeFiles/epollsev.dir/__/src/epollsev.cpp.o.requires

.PHONY : test/CMakeFiles/epollsev.dir/requires

test/CMakeFiles/epollsev.dir/clean:
	cd /home/fang/work/template/0223/build/test && $(CMAKE_COMMAND) -P CMakeFiles/epollsev.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/epollsev.dir/clean

test/CMakeFiles/epollsev.dir/depend:
	cd /home/fang/work/template/0223/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fang/work/template/0223 /home/fang/work/template/0223/test /home/fang/work/template/0223/build /home/fang/work/template/0223/build/test /home/fang/work/template/0223/build/test/CMakeFiles/epollsev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/epollsev.dir/depend

