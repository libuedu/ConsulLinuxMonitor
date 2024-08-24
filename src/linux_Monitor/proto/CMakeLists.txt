#*************************
# 项目名称
#************************
project(monitor_proto)
message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#************************
# 导入需要的库
#************************
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(c-ares CONFIG)
find_package(Threads)

#************************
# 添加proto文件
#************************
set(PROTO_FILES
    monitor_info.proto
    cpu_load.proto
    cpu_softirq.proto
    cpu_stat.proto
    mem_info.proto
    net_info.proto
    health.proto
)

#*************************
# 生成动态库
#************************
add_library(${PROJECT_NAME} SHARED ${PROTO_FILES})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        grpc++_reflection
)
target_include_directories(${PROJECT_NAME} PUBLIC
${PROTOBUF_INCLUDE_DIRS} 
${CMAKE_CURRENT_BINARY_DIR})

#*************************
# 在 mointor proto target 中编译 protobuf 和 grpc 文件到 cpp
#************************
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET monitor_proto LANGUAGE cpp)
protobuf_generate(TARGET monitor_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
