# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/build

# Include any dependencies generated for this target.
include src/linux_Monitor/common/CMakeFiles/common_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/linux_Monitor/common/CMakeFiles/common_test.dir/compiler_depend.make

# Include the progress variables for this target.
include src/linux_Monitor/common/CMakeFiles/common_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/linux_Monitor/common/CMakeFiles/common_test.dir/flags.make

src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o: src/linux_Monitor/common/CMakeFiles/common_test.dir/flags.make
src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o: /work/src/linux_Monitor/common/main_common_test.cpp
src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o: src/linux_Monitor/common/CMakeFiles/common_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o"
	cd /work/build/src/linux_Monitor/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o -MF CMakeFiles/common_test.dir/main_common_test.cpp.o.d -o CMakeFiles/common_test.dir/main_common_test.cpp.o -c /work/src/linux_Monitor/common/main_common_test.cpp

src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common_test.dir/main_common_test.cpp.i"
	cd /work/build/src/linux_Monitor/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/src/linux_Monitor/common/main_common_test.cpp > CMakeFiles/common_test.dir/main_common_test.cpp.i

src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common_test.dir/main_common_test.cpp.s"
	cd /work/build/src/linux_Monitor/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/src/linux_Monitor/common/main_common_test.cpp -o CMakeFiles/common_test.dir/main_common_test.cpp.s

# Object files for target common_test
common_test_OBJECTS = \
"CMakeFiles/common_test.dir/main_common_test.cpp.o"

# External object files for target common_test
common_test_EXTERNAL_OBJECTS =

/work/bin/common_test: src/linux_Monitor/common/CMakeFiles/common_test.dir/main_common_test.cpp.o
/work/bin/common_test: src/linux_Monitor/common/CMakeFiles/common_test.dir/build.make
/work/bin/common_test: /work/lib/libcommon.so
/work/bin/common_test: src/linux_Monitor/common/CMakeFiles/common_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /work/bin/common_test"
	cd /work/build/src/linux_Monitor/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/linux_Monitor/common/CMakeFiles/common_test.dir/build: /work/bin/common_test
.PHONY : src/linux_Monitor/common/CMakeFiles/common_test.dir/build

src/linux_Monitor/common/CMakeFiles/common_test.dir/clean:
	cd /work/build/src/linux_Monitor/common && $(CMAKE_COMMAND) -P CMakeFiles/common_test.dir/cmake_clean.cmake
.PHONY : src/linux_Monitor/common/CMakeFiles/common_test.dir/clean

src/linux_Monitor/common/CMakeFiles/common_test.dir/depend:
	cd /work/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work /work/src/linux_Monitor/common /work/build /work/build/src/linux_Monitor/common /work/build/src/linux_Monitor/common/CMakeFiles/common_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/linux_Monitor/common/CMakeFiles/common_test.dir/depend

