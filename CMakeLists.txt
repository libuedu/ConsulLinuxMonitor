#*************************
# 声明cmake最低的版本号
#************************
cmake_minimum_required(VERSION 3.16)
#*************************
# 项目名称
#************************
project(Linux_Monitor LANGUAGES CXX)
#*************************
# 设置编译类型
#************************
# set(DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
#*************************
# 指定C++标准 
#************************
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保编译器支持所选标准
#************************
# 设置优化等级
#************************
set(CMAKE_CXX_FLAGS "-w")# 忽略警告信息
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb ${CMAKE_CXX_FLAGS}")# 设置DEBUG模式的编译选项
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")# 设置RELEASE模式的编译选项
#*************************
# 设置输出目录
#************************
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) # 设置可执行文件输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # 设置共享库输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # 设置静态库输出目录
set(MY_CMAKE_INSTALL_DIRECTORY ${PROJECT_SOURCE_DIR}/install) # 设置安装目录
#*************************
# 添加头文件
#************************
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/Linux_Monitor/include/monitor)
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/Linux_Monitor/include/utils)
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/rpc_manager/client)
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/rpc_manager/server)
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/display_monitor)
include_directories(${PROJECT_SOURCE_DIR}/src/linux_Monitor/common)
#*************************
# 套娃添加
#************************
add_subdirectory(src)