cmake_minimum_required(VERSION 3.10)

#*************************
# 项目名称
#************************
project(display)

message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#*************************
# 设置Qt库
#************************
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#************************
# 添加源文件
#************************
set(SOURCES
    monitor_inter.cpp
    cpu_softirq_model.cpp
    cpu_load_model.cpp
    monitor_widget.cpp
    cpu_stat_model.cpp
    mem_model.cpp
    net_model.cpp
)

#*************************
# 生成动态库
#************************
add_library(${PROJECT_NAME} SHARED ${SOURCES})

#*************************
# 链接库
#************************h
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    monitor_proto
    rpc_manager
    rpc_client
    Qt5::Widgets
    Qt5::Core
    Qt5::Network
)

#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}_test main_test.cpp)

target_link_libraries(${PROJECT_NAME}_test
    PUBLIC
    ${PROJECT_NAME}
)

