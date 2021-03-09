cmake_minimum_required(VERSION 3.0.0)
project(client VERSION 0.1.0)

include(CTest)
enable_testing()


LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
# 查找指定目录下的所有.cpp与.h文件 并存放到指定变量名SC_FILES中
FILE(GLOB_RECURSE SC_FILES "src/*.cpp" "src/include/*.h")
#添加查找库的路径  -L
# link_directories("./lib")
# link_directories("./build/src")
# 查找指定目录下的链接库
# FILE(GLOB_RECURSE LIB "./lib/*.so" "./src/*.a")
# 设置头文件目录
# include_directories("./lib/include/")
# include_directories("./src/include/")
# # 设置md5代码文件的路径
# set(MD5_FILE "./common/md5/md5.cpp" "./common/md5/md5.h")

# # 对md5的源码分组到md5组里
# source_group(md5 FILES ${MD5_FILE})
# link_libraries(${LIB})
# add_executable(${PROJECT_NAME} ${SC_FILES})
#-l
# target_link_libraries(${PROJECT_NAME} "libyaml-cpp.a")
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src/base)
add_subdirectory(src/net)
add_subdirectory(test)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
