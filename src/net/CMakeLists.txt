cmake_minimum_required(VERSION 3.0.0)
project(net VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_VERBOSE_MAKEFILEON ON)

set(CXX_FLAGS
-g
-Wall
-Wextra
#-Werror
-std=c++11
)

# 查找指定目录下的所有.cpp与.h文件 并存放到指定变量名SC_FILES中
FILE(GLOB_RECURSE SC_FILES "*.cpp" "*.h")
FILE(GLOB_RECURSE INCLUDE_FILES  "../base/include/*.h")

# 查找指定目录下的链接库 -l
FILE(GLOB_RECURSE LIB "../../lib/*.so" "../../lib/*.a")
# 设置头文件目录 -I
include_directories("../../lib/include/")
include_directories("../base/include")

# # 设置md5代码文件的路径
# set(MD5_FILE "./common/md5/md5.cpp" "./common/md5/md5.h")

# # 对md5的源码分组到md5组里
# source_group(md5 FILES ${MD5_FILE})
#添加查找库的路径  -L
link_directories("../../lib")
link_libraries(${LIB})
add_library(net ${SC_FILES})
#-l
target_link_libraries(${PROJECT_NAME} libase.a)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
