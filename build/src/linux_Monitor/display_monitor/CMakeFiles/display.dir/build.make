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
include src/linux_Monitor/display_monitor/CMakeFiles/display.dir/depend.make

# Include the progress variables for this target.
include src/linux_Monitor/display_monitor/CMakeFiles/display.dir/progress.make

# Include the compile flags for this target's objects.
include src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o: src/linux_Monitor/display_monitor/display_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o -c /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor/display_autogen/mocs_compilation.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor/display_autogen/mocs_compilation.cpp > CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor/display_autogen/mocs_compilation.cpp -o CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.o: ../src/linux_Monitor/display_monitor/monitor_inter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/monitor_inter.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_inter.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/monitor_inter.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_inter.cpp > CMakeFiles/display.dir/monitor_inter.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/monitor_inter.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_inter.cpp -o CMakeFiles/display.dir/monitor_inter.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.o: ../src/linux_Monitor/display_monitor/cpu_softirq_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/cpu_softirq_model.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_softirq_model.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/cpu_softirq_model.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_softirq_model.cpp > CMakeFiles/display.dir/cpu_softirq_model.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/cpu_softirq_model.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_softirq_model.cpp -o CMakeFiles/display.dir/cpu_softirq_model.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.o: ../src/linux_Monitor/display_monitor/cpu_load_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/cpu_load_model.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_load_model.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/cpu_load_model.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_load_model.cpp > CMakeFiles/display.dir/cpu_load_model.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/cpu_load_model.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_load_model.cpp -o CMakeFiles/display.dir/cpu_load_model.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.o: ../src/linux_Monitor/display_monitor/monitor_widget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/monitor_widget.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_widget.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/monitor_widget.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_widget.cpp > CMakeFiles/display.dir/monitor_widget.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/monitor_widget.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/monitor_widget.cpp -o CMakeFiles/display.dir/monitor_widget.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.o: ../src/linux_Monitor/display_monitor/cpu_stat_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/cpu_stat_model.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_stat_model.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/cpu_stat_model.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_stat_model.cpp > CMakeFiles/display.dir/cpu_stat_model.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/cpu_stat_model.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/cpu_stat_model.cpp -o CMakeFiles/display.dir/cpu_stat_model.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.o: ../src/linux_Monitor/display_monitor/mem_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/mem_model.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/mem_model.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/mem_model.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/mem_model.cpp > CMakeFiles/display.dir/mem_model.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/mem_model.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/mem_model.cpp -o CMakeFiles/display.dir/mem_model.cpp.s

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.o: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/flags.make
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.o: ../src/linux_Monitor/display_monitor/net_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.o"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/display.dir/net_model.cpp.o -c /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/net_model.cpp

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display.dir/net_model.cpp.i"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/net_model.cpp > CMakeFiles/display.dir/net_model.cpp.i

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display.dir/net_model.cpp.s"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor/net_model.cpp -o CMakeFiles/display.dir/net_model.cpp.s

# Object files for target display
display_OBJECTS = \
"CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/display.dir/monitor_inter.cpp.o" \
"CMakeFiles/display.dir/cpu_softirq_model.cpp.o" \
"CMakeFiles/display.dir/cpu_load_model.cpp.o" \
"CMakeFiles/display.dir/monitor_widget.cpp.o" \
"CMakeFiles/display.dir/cpu_stat_model.cpp.o" \
"CMakeFiles/display.dir/mem_model.cpp.o" \
"CMakeFiles/display.dir/net_model.cpp.o"

# External object files for target display
display_EXTERNAL_OBJECTS =

../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/display_autogen/mocs_compilation.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_inter.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_softirq_model.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_load_model.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/monitor_widget.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/cpu_stat_model.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/mem_model.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/net_model.cpp.o
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/build.make
../lib/libdisplay.so: ../lib/librpc_manager.so
../lib/libdisplay.so: ../lib/librpc_client.so
../lib/libdisplay.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
../lib/libdisplay.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
../lib/libdisplay.so: ../lib/libmonitor_proto.so
../lib/libdisplay.so: /usr/lib/libgrpc++.so.1.30.3
../lib/libdisplay.so: /usr/lib/x86_64-linux-gnu/libprotobuf.so.3.12.2.0
../lib/libdisplay.so: /usr/lib/libgrpc.so.10.0.0
../lib/libdisplay.so: /usr/lib/libssl.so
../lib/libdisplay.so: /usr/lib/libcrypto.so
../lib/libdisplay.so: /usr/lib/libz.a
../lib/libdisplay.so: /usr/lib/libcares.a
../lib/libdisplay.so: /usr/lib/libabsl_bad_optional_access.so
../lib/libdisplay.so: /usr/lib/libaddress_sorting.so.10.0.0
../lib/libdisplay.so: /usr/lib/libupb.so.10.0.0
../lib/libdisplay.so: /usr/lib/libgpr.so.10.0.0
../lib/libdisplay.so: /usr/lib/libabsl_time.so
../lib/libdisplay.so: /usr/lib/libabsl_civil_time.so
../lib/libdisplay.so: /usr/lib/libabsl_time_zone.so
../lib/libdisplay.so: /usr/lib/libabsl_str_format_internal.so
../lib/libdisplay.so: /usr/lib/libabsl_strings.so
../lib/libdisplay.so: /usr/lib/libabsl_strings_internal.so
../lib/libdisplay.so: /usr/lib/libabsl_base.so
../lib/libdisplay.so: /usr/lib/libabsl_dynamic_annotations.so
../lib/libdisplay.so: /usr/lib/libabsl_spinlock_wait.so
../lib/libdisplay.so: /usr/lib/libabsl_int128.so
../lib/libdisplay.so: /usr/lib/libabsl_throw_delegate.so
../lib/libdisplay.so: /usr/lib/libabsl_raw_logging_internal.so
../lib/libdisplay.so: /usr/lib/libabsl_log_severity.so
../lib/libdisplay.so: /usr/local/lib/libcpr.so
../lib/libdisplay.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
../lib/libdisplay.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
../lib/libdisplay.so: src/linux_Monitor/display_monitor/CMakeFiles/display.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/u/Desktop/myNewRpcProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../../lib/libdisplay.so"
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/display.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/linux_Monitor/display_monitor/CMakeFiles/display.dir/build: ../lib/libdisplay.so

.PHONY : src/linux_Monitor/display_monitor/CMakeFiles/display.dir/build

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/clean:
	cd /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor && $(CMAKE_COMMAND) -P CMakeFiles/display.dir/cmake_clean.cmake
.PHONY : src/linux_Monitor/display_monitor/CMakeFiles/display.dir/clean

src/linux_Monitor/display_monitor/CMakeFiles/display.dir/depend:
	cd /home/u/Desktop/myNewRpcProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u/Desktop/myNewRpcProject /home/u/Desktop/myNewRpcProject/src/linux_Monitor/display_monitor /home/u/Desktop/myNewRpcProject/build /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor /home/u/Desktop/myNewRpcProject/build/src/linux_Monitor/display_monitor/CMakeFiles/display.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/linux_Monitor/display_monitor/CMakeFiles/display.dir/depend

