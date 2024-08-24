#*************************
#项目名称
#************************
project(rpc_manager)
message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#************************
# 添加源文件
#************************
set(SOURCES
    rpc_manager.cpp
)
#*************************
# 生成动态库
#************************
# 包含 CPR 头文件目录
include_directories(/usr/local/include)
find_library(CPR_LIBRARIES NAMES cpr PATHS /usr/local/lib)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    monitor_proto
    ${CPR_LIBRARIES}
)


#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}_test main_test.cpp)
target_link_libraries(${PROJECT_NAME}_test
    PUBLIC
    ${PROJECT_NAME}
)