# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/u/Desktop/myNewRpcProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u/Desktop/myNewRpcProject/build

# Include any dependencies generated for this target.
include src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/depend.make

# Include the progress variables for this target.
include src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/flags.make

src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.o: src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/flags.make
src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.o: ../src/linux_Monitor/rpc_manager/server/main_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc_manager_test.dir/main_test.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/rpc_manager/server/main_test.cpp

src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc_manager_test.dir/main_test.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/rpc_manager/server/main_test.cpp > CMakeFiles/rpc_manager_test.dir/main_test.cpp.i

src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc_manager_test.dir/main_test.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/rpc_manager/server/main_test.cpp -o CMakeFiles/rpc_manager_test.dir/main_test.cpp.s

# Object files for target rpc_manager_test
rpc_manager_test_OBJECTS = \
"CMakeFiles/rpc_manager_test.dir/main_test.cpp.o"

# External object files for target rpc_manager_test
rpc_manager_test_EXTERNAL_OBJECTS =

../bin/rpc_manager_test: src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/main_test.cpp.o
../bin/rpc_manager_test: src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/build.make
../bin/rpc_manager_test: ../lib/librpc_manager.so
../bin/rpc_manager_test: ../lib/libmonitor_proto.so
../bin/rpc_manager_test: /usr/lib/libgrpc++.so.1.30.3
../bin/rpc_manager_test: /usr/lib/x86_64-linux-gnu/libprotobuf.so.3.12.2.0
../bin/rpc_manager_test: /usr/lib/libgrpc.so.10.0.0
../bin/rpc_manager_test: /usr/lib/libssl.so
../bin/rpc_manager_test: /usr/lib/libcrypto.so
../bin/rpc_manager_test: /usr/lib/libz.a
../bin/rpc_manager_test: /usr/lib/libcares.a
../bin/rpc_manager_test: /usr/lib/libabsl_bad_optional_access.so
../bin/rpc_manager_test: /usr/lib/libaddress_sorting.so.10.0.0
../bin/rpc_manager_test: /usr/lib/libupb.so.10.0.0
../bin/rpc_manager_test: /usr/lib/libgpr.so.10.0.0
../bin/rpc_manager_test: /usr/lib/libabsl_time.so
../bin/rpc_manager_test: /usr/lib/libabsl_civil_time.so
../bin/rpc_manager_test: /usr/lib/libabsl_time_zone.so
../bin/rpc_manager_test: /usr/lib/libabsl_str_format_internal.so
../bin/rpc_manager_test: /usr/lib/libabsl_strings.so
../bin/rpc_manager_test: /usr/lib/libabsl_strings_internal.so
../bin/rpc_manager_test: /usr/lib/libabsl_base.so
../bin/rpc_manager_test: /usr/lib/libabsl_dynamic_annotations.so
../bin/rpc_manager_test: /usr/lib/libabsl_spinlock_wait.so
../bin/rpc_manager_test: /usr/lib/libabsl_int128.so
../bin/rpc_manager_test: /usr/lib/libabsl_throw_delegate.so
../bin/rpc_manager_test: /usr/lib/libabsl_raw_logging_internal.so
../bin/rpc_manager_test: /usr/lib/libabsl_log_severity.so
../bin/rpc_manager_test: /usr/local/lib/libcpr.so
../bin/rpc_manager_test: src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../bin/rpc_manager_test"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc_manager_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/build: ../bin/rpc_manager_test

.PHONY : src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/build

src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/clean:
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server && $(CMAKE_COMMAND) -P CMakeFiles/rpc_manager_test.dir/cmake_clean.cmake
.PHONY : src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/clean

src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/depend:
	cd /home/u/Desktop/myNewRpcProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u/Desktop/myNewRpcProject /home/u/Desktop/myNewRpcProject/src/linux_Monitor/rpc_manager/server /home/u/Desktop/myNewRpcProject/build /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/linux_Monitor/rpc_manager/server/CMakeFiles/rpc_manager_test.dir/depend

