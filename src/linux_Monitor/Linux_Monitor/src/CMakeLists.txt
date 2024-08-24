#*************************
#项目名称
#************************
project(Linux_Monitor)
message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#************************
# 添加源文件
#************************
set(SOURCES
   monitor/cpu_softirq_monitor.cpp
   monitor/cpu_load_monitor.cpp
   monitor/cpu_stat_monitor.cpp
   monitor/mem_monitor.cpp
   monitor/net_monitor.cpp
   utils/read_file.cpp
)

#*************************
# 生成动态库
#************************
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    monitor_proto
    common
    rpc_client
    boost_system
    boost_chrono
)

#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}_test main_test.cpp)
target_link_libraries(${PROJECT_NAME}_test
    PUBLIC
    ${PROJECT_NAME}
)