cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(CXX_FLAGS
-g
-Wall
-Wextra
#-Werror
-std=c++11
)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#FILE(GLOB_RECURSE SC_FILES "/src/*.cpp" "../src/include/*.h" "../src/include/*hpp")

set(src "./多态.cpp")
add_executable(t ${src})
#-L
link_directories("./../lib")
link_directories("../build/src")
#-I
include_directories("../src/include")
include_directories("../lib/include")
# FILE(GLOB_RECURSE LIB "../lib/*.so" "../src/*.a")
#-l
# link_libraries(${LIB})
set(epollsrc "./epollsev_test.cpp" "../src/log.cpp" "../src/include/server.hpp" "../src/epollsev.cpp")
add_executable(epollsev ${epollsrc})
#-l
target_link_libraries(epollsev "libyaml-cpp.a" "libspdlog.a")

set(thread_test_src "./thread_test.cc")
add_executable(thread_test ${thread_test_src})
target_link_libraries(thread_test "libyaml-cpp.a" "libspdlog.a" "libbase.a" "pthread")

set(exception_test_src "./exception_test.cpp")
add_executable(exception_test ${exception_test_src})
target_link_libraries(exception_test "libyaml-cpp.a" "libspdlog.a" "libbase.a" "pthread")

set(mutex_test_src "./mutex_test.cpp")
add_executable(mutex_test ${mutex_test_src})
target_link_libraries(mutex_test "libyaml-cpp.a" "libspdlog.a" "libbase.a" "pthread")

set(countDown_test_src "./countDown_test.cpp")
add_executable(countDown_test ${countDown_test_src})
target_link_libraries(countDown_test "libyaml-cpp.a" "libspdlog.a" "libbase.a" "pthread")

set(BlockingQueue_test_src "./BlockingQueue_test.cpp")
add_executable(BlockingQueue_test ${BlockingQueue_test_src})
target_link_libraries(BlockingQueue_test "libyaml-cpp.a" "libspdlog.a" "libbase.a" "pthread")

add_executable(netclient client.cpp)
