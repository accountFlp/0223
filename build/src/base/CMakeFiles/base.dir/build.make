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
include src/base/CMakeFiles/base.dir/depend.make

# Include the progress variables for this target.
include src/base/CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/CMakeFiles/base.dir/flags.make

src/base/CMakeFiles/base.dir/Exception.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/Exception.cpp.o: ../src/base/Exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/CMakeFiles/base.dir/Exception.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Exception.cpp.o -c /home/fang/work/template/0223/src/base/Exception.cpp

src/base/CMakeFiles/base.dir/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Exception.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/Exception.cpp > CMakeFiles/base.dir/Exception.cpp.i

src/base/CMakeFiles/base.dir/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Exception.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/Exception.cpp -o CMakeFiles/base.dir/Exception.cpp.s

src/base/CMakeFiles/base.dir/Exception.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/Exception.cpp.o.requires

src/base/CMakeFiles/base.dir/Exception.cpp.o.provides: src/base/CMakeFiles/base.dir/Exception.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/Exception.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/Exception.cpp.o.provides

src/base/CMakeFiles/base.dir/Exception.cpp.o.provides.build: src/base/CMakeFiles/base.dir/Exception.cpp.o


src/base/CMakeFiles/base.dir/Timestamp.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/Timestamp.cpp.o: ../src/base/Timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/CMakeFiles/base.dir/Timestamp.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Timestamp.cpp.o -c /home/fang/work/template/0223/src/base/Timestamp.cpp

src/base/CMakeFiles/base.dir/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Timestamp.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/Timestamp.cpp > CMakeFiles/base.dir/Timestamp.cpp.i

src/base/CMakeFiles/base.dir/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Timestamp.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/Timestamp.cpp -o CMakeFiles/base.dir/Timestamp.cpp.s

src/base/CMakeFiles/base.dir/Timestamp.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/Timestamp.cpp.o.requires

src/base/CMakeFiles/base.dir/Timestamp.cpp.o.provides: src/base/CMakeFiles/base.dir/Timestamp.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/Timestamp.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/Timestamp.cpp.o.provides

src/base/CMakeFiles/base.dir/Timestamp.cpp.o.provides.build: src/base/CMakeFiles/base.dir/Timestamp.cpp.o


src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: ../src/base/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o -c /home/fang/work/template/0223/src/base/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp

src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp > CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.i

src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp -o CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.s

src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.requires

src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.provides: src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.provides

src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.provides.build: src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o


src/base/CMakeFiles/base.dir/epollsev.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/epollsev.cpp.o: ../src/base/epollsev.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/base/CMakeFiles/base.dir/epollsev.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/epollsev.cpp.o -c /home/fang/work/template/0223/src/base/epollsev.cpp

src/base/CMakeFiles/base.dir/epollsev.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/epollsev.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/epollsev.cpp > CMakeFiles/base.dir/epollsev.cpp.i

src/base/CMakeFiles/base.dir/epollsev.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/epollsev.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/epollsev.cpp -o CMakeFiles/base.dir/epollsev.cpp.s

src/base/CMakeFiles/base.dir/epollsev.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/epollsev.cpp.o.requires

src/base/CMakeFiles/base.dir/epollsev.cpp.o.provides: src/base/CMakeFiles/base.dir/epollsev.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/epollsev.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/epollsev.cpp.o.provides

src/base/CMakeFiles/base.dir/epollsev.cpp.o.provides.build: src/base/CMakeFiles/base.dir/epollsev.cpp.o


src/base/CMakeFiles/base.dir/log.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/log.cpp.o: ../src/base/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/base/CMakeFiles/base.dir/log.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/log.cpp.o -c /home/fang/work/template/0223/src/base/log.cpp

src/base/CMakeFiles/base.dir/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/log.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/log.cpp > CMakeFiles/base.dir/log.cpp.i

src/base/CMakeFiles/base.dir/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/log.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/log.cpp -o CMakeFiles/base.dir/log.cpp.s

src/base/CMakeFiles/base.dir/log.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/log.cpp.o.requires

src/base/CMakeFiles/base.dir/log.cpp.o.provides: src/base/CMakeFiles/base.dir/log.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/log.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/log.cpp.o.provides

src/base/CMakeFiles/base.dir/log.cpp.o.provides.build: src/base/CMakeFiles/base.dir/log.cpp.o


src/base/CMakeFiles/base.dir/mCondition.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mCondition.cpp.o: ../src/base/mCondition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/base/CMakeFiles/base.dir/mCondition.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mCondition.cpp.o -c /home/fang/work/template/0223/src/base/mCondition.cpp

src/base/CMakeFiles/base.dir/mCondition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mCondition.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mCondition.cpp > CMakeFiles/base.dir/mCondition.cpp.i

src/base/CMakeFiles/base.dir/mCondition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mCondition.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mCondition.cpp -o CMakeFiles/base.dir/mCondition.cpp.s

src/base/CMakeFiles/base.dir/mCondition.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mCondition.cpp.o.requires

src/base/CMakeFiles/base.dir/mCondition.cpp.o.provides: src/base/CMakeFiles/base.dir/mCondition.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mCondition.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mCondition.cpp.o.provides

src/base/CMakeFiles/base.dir/mCondition.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mCondition.cpp.o


src/base/CMakeFiles/base.dir/mCountDown.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mCountDown.cpp.o: ../src/base/mCountDown.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/base/CMakeFiles/base.dir/mCountDown.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mCountDown.cpp.o -c /home/fang/work/template/0223/src/base/mCountDown.cpp

src/base/CMakeFiles/base.dir/mCountDown.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mCountDown.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mCountDown.cpp > CMakeFiles/base.dir/mCountDown.cpp.i

src/base/CMakeFiles/base.dir/mCountDown.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mCountDown.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mCountDown.cpp -o CMakeFiles/base.dir/mCountDown.cpp.s

src/base/CMakeFiles/base.dir/mCountDown.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mCountDown.cpp.o.requires

src/base/CMakeFiles/base.dir/mCountDown.cpp.o.provides: src/base/CMakeFiles/base.dir/mCountDown.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mCountDown.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mCountDown.cpp.o.provides

src/base/CMakeFiles/base.dir/mCountDown.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mCountDown.cpp.o


src/base/CMakeFiles/base.dir/mException.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mException.cpp.o: ../src/base/mException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/base/CMakeFiles/base.dir/mException.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mException.cpp.o -c /home/fang/work/template/0223/src/base/mException.cpp

src/base/CMakeFiles/base.dir/mException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mException.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mException.cpp > CMakeFiles/base.dir/mException.cpp.i

src/base/CMakeFiles/base.dir/mException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mException.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mException.cpp -o CMakeFiles/base.dir/mException.cpp.s

src/base/CMakeFiles/base.dir/mException.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mException.cpp.o.requires

src/base/CMakeFiles/base.dir/mException.cpp.o.provides: src/base/CMakeFiles/base.dir/mException.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mException.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mException.cpp.o.provides

src/base/CMakeFiles/base.dir/mException.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mException.cpp.o


src/base/CMakeFiles/base.dir/mMutex.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mMutex.cpp.o: ../src/base/mMutex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/base/CMakeFiles/base.dir/mMutex.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mMutex.cpp.o -c /home/fang/work/template/0223/src/base/mMutex.cpp

src/base/CMakeFiles/base.dir/mMutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mMutex.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mMutex.cpp > CMakeFiles/base.dir/mMutex.cpp.i

src/base/CMakeFiles/base.dir/mMutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mMutex.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mMutex.cpp -o CMakeFiles/base.dir/mMutex.cpp.s

src/base/CMakeFiles/base.dir/mMutex.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mMutex.cpp.o.requires

src/base/CMakeFiles/base.dir/mMutex.cpp.o.provides: src/base/CMakeFiles/base.dir/mMutex.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mMutex.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mMutex.cpp.o.provides

src/base/CMakeFiles/base.dir/mMutex.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mMutex.cpp.o


src/base/CMakeFiles/base.dir/mThreadPool.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mThreadPool.cpp.o: ../src/base/mThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/base/CMakeFiles/base.dir/mThreadPool.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mThreadPool.cpp.o -c /home/fang/work/template/0223/src/base/mThreadPool.cpp

src/base/CMakeFiles/base.dir/mThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mThreadPool.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mThreadPool.cpp > CMakeFiles/base.dir/mThreadPool.cpp.i

src/base/CMakeFiles/base.dir/mThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mThreadPool.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mThreadPool.cpp -o CMakeFiles/base.dir/mThreadPool.cpp.s

src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.requires

src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.provides: src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.provides

src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mThreadPool.cpp.o


src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o: ../src/base/mTimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/mTimeStamp.cpp.o -c /home/fang/work/template/0223/src/base/mTimeStamp.cpp

src/base/CMakeFiles/base.dir/mTimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/mTimeStamp.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/mTimeStamp.cpp > CMakeFiles/base.dir/mTimeStamp.cpp.i

src/base/CMakeFiles/base.dir/mTimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/mTimeStamp.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/mTimeStamp.cpp -o CMakeFiles/base.dir/mTimeStamp.cpp.s

src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.requires

src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.provides: src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.provides

src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.provides.build: src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o


src/base/CMakeFiles/base.dir/poll_server.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/poll_server.cpp.o: ../src/base/poll_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/base/CMakeFiles/base.dir/poll_server.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/poll_server.cpp.o -c /home/fang/work/template/0223/src/base/poll_server.cpp

src/base/CMakeFiles/base.dir/poll_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/poll_server.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/poll_server.cpp > CMakeFiles/base.dir/poll_server.cpp.i

src/base/CMakeFiles/base.dir/poll_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/poll_server.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/poll_server.cpp -o CMakeFiles/base.dir/poll_server.cpp.s

src/base/CMakeFiles/base.dir/poll_server.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/poll_server.cpp.o.requires

src/base/CMakeFiles/base.dir/poll_server.cpp.o.provides: src/base/CMakeFiles/base.dir/poll_server.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/poll_server.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/poll_server.cpp.o.provides

src/base/CMakeFiles/base.dir/poll_server.cpp.o.provides.build: src/base/CMakeFiles/base.dir/poll_server.cpp.o


src/base/CMakeFiles/base.dir/thread.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/thread.cpp.o: ../src/base/thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/base/CMakeFiles/base.dir/thread.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/thread.cpp.o -c /home/fang/work/template/0223/src/base/thread.cpp

src/base/CMakeFiles/base.dir/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/thread.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/thread.cpp > CMakeFiles/base.dir/thread.cpp.i

src/base/CMakeFiles/base.dir/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/thread.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/thread.cpp -o CMakeFiles/base.dir/thread.cpp.s

src/base/CMakeFiles/base.dir/thread.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/thread.cpp.o.requires

src/base/CMakeFiles/base.dir/thread.cpp.o.provides: src/base/CMakeFiles/base.dir/thread.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/thread.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/thread.cpp.o.provides

src/base/CMakeFiles/base.dir/thread.cpp.o.provides.build: src/base/CMakeFiles/base.dir/thread.cpp.o


src/base/CMakeFiles/base.dir/threadfb.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/threadfb.cpp.o: ../src/base/threadfb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/base/CMakeFiles/base.dir/threadfb.cpp.o"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/threadfb.cpp.o -c /home/fang/work/template/0223/src/base/threadfb.cpp

src/base/CMakeFiles/base.dir/threadfb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/threadfb.cpp.i"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fang/work/template/0223/src/base/threadfb.cpp > CMakeFiles/base.dir/threadfb.cpp.i

src/base/CMakeFiles/base.dir/threadfb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/threadfb.cpp.s"
	cd /home/fang/work/template/0223/build/src/base && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fang/work/template/0223/src/base/threadfb.cpp -o CMakeFiles/base.dir/threadfb.cpp.s

src/base/CMakeFiles/base.dir/threadfb.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/threadfb.cpp.o.requires

src/base/CMakeFiles/base.dir/threadfb.cpp.o.provides: src/base/CMakeFiles/base.dir/threadfb.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/threadfb.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/threadfb.cpp.o.provides

src/base/CMakeFiles/base.dir/threadfb.cpp.o.provides.build: src/base/CMakeFiles/base.dir/threadfb.cpp.o


# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/Exception.cpp.o" \
"CMakeFiles/base.dir/Timestamp.cpp.o" \
"CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o" \
"CMakeFiles/base.dir/epollsev.cpp.o" \
"CMakeFiles/base.dir/log.cpp.o" \
"CMakeFiles/base.dir/mCondition.cpp.o" \
"CMakeFiles/base.dir/mCountDown.cpp.o" \
"CMakeFiles/base.dir/mException.cpp.o" \
"CMakeFiles/base.dir/mMutex.cpp.o" \
"CMakeFiles/base.dir/mThreadPool.cpp.o" \
"CMakeFiles/base.dir/mTimeStamp.cpp.o" \
"CMakeFiles/base.dir/poll_server.cpp.o" \
"CMakeFiles/base.dir/thread.cpp.o" \
"CMakeFiles/base.dir/threadfb.cpp.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

../lib/libbase.a: src/base/CMakeFiles/base.dir/Exception.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/Timestamp.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/epollsev.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/log.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mCondition.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mCountDown.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mException.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mMutex.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mThreadPool.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/poll_server.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/thread.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/threadfb.cpp.o
../lib/libbase.a: src/base/CMakeFiles/base.dir/build.make
../lib/libbase.a: src/base/CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fang/work/template/0223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX static library ../../../lib/libbase.a"
	cd /home/fang/work/template/0223/build/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean_target.cmake
	cd /home/fang/work/template/0223/build/src/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/CMakeFiles/base.dir/build: ../lib/libbase.a

.PHONY : src/base/CMakeFiles/base.dir/build

src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/Exception.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/Timestamp.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/build/CMakeFiles/3.10.2/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/epollsev.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/log.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mCondition.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mCountDown.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mException.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mMutex.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mThreadPool.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/mTimeStamp.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/poll_server.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/thread.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/threadfb.cpp.o.requires

.PHONY : src/base/CMakeFiles/base.dir/requires

src/base/CMakeFiles/base.dir/clean:
	cd /home/fang/work/template/0223/build/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : src/base/CMakeFiles/base.dir/clean

src/base/CMakeFiles/base.dir/depend:
	cd /home/fang/work/template/0223/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fang/work/template/0223 /home/fang/work/template/0223/src/base /home/fang/work/template/0223/build /home/fang/work/template/0223/build/src/base /home/fang/work/template/0223/build/src/base/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/CMakeFiles/base.dir/depend

