# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hayden/code/cpp/datastructure/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hayden/code/cpp/datastructure/test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/main.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hayden/code/cpp/datastructure/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test.dir/main.c.o   -c /Users/hayden/code/cpp/datastructure/test/main.c

CMakeFiles/test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hayden/code/cpp/datastructure/test/main.c > CMakeFiles/test.dir/main.c.i

CMakeFiles/test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hayden/code/cpp/datastructure/test/main.c -o CMakeFiles/test.dir/main.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/main.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/main.c.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hayden/code/cpp/datastructure/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /Users/hayden/code/cpp/datastructure/test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hayden/code/cpp/datastructure/test /Users/hayden/code/cpp/datastructure/test /Users/hayden/code/cpp/datastructure/test/cmake-build-debug /Users/hayden/code/cpp/datastructure/test/cmake-build-debug /Users/hayden/code/cpp/datastructure/test/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

