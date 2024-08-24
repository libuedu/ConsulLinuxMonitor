#*************************
# 声明cmake最低的版本号
#************************
# cmake_minimum_required(VERSION 3.16)

#*************************
# 项目名称
#************************
project(common)

#*************************
# 设置编译类型
#************************
# set(DEFAULT_BUILD_TYPE "Release")
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "Release")
# endif()

#*************************
# 指定C++标准 
#************************
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保编译器支持所选标准

#************************
# 设置优化等级
#************************
# set(CMAKE_CXX_FLAGS "-w")# 忽略警告信息
# set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb ${CMAKE_CXX_FLAGS}")# 设置DEBUG模式的编译选项
# set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")# 设置RELEASE模式的编译选项

message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#*************************
# 生成动态库
#************************
add_library(${PROJECT_NAME} SHARED common.cpp myLog.cpp)
target_link_libraries(${PROJECT_NAME} glog)


#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}_test main_common_test.cpp)

target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} )
