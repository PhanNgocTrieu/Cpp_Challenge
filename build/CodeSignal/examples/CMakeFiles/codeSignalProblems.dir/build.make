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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /mnt/f/DocumentByMaking/Cpp_Challenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/f/DocumentByMaking/Cpp_Challenge/build

# Include any dependencies generated for this target.
include CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/depend.make

# Include the progress variables for this target.
include CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/progress.make

# Include the compile flags for this target's objects.
include CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/flags.make

CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.o: CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/flags.make
CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.o: ../CodeSignal/examples/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/DocumentByMaking/Cpp_Challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.o"
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codeSignalProblems.dir/main.cpp.o -c /mnt/f/DocumentByMaking/Cpp_Challenge/CodeSignal/examples/main.cpp

CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codeSignalProblems.dir/main.cpp.i"
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/DocumentByMaking/Cpp_Challenge/CodeSignal/examples/main.cpp > CMakeFiles/codeSignalProblems.dir/main.cpp.i

CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codeSignalProblems.dir/main.cpp.s"
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/DocumentByMaking/Cpp_Challenge/CodeSignal/examples/main.cpp -o CMakeFiles/codeSignalProblems.dir/main.cpp.s

# Object files for target codeSignalProblems
codeSignalProblems_OBJECTS = \
"CMakeFiles/codeSignalProblems.dir/main.cpp.o"

# External object files for target codeSignalProblems
codeSignalProblems_EXTERNAL_OBJECTS =

CodeSignal/examples/codeSignalProblems: CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/main.cpp.o
CodeSignal/examples/codeSignalProblems: CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/build.make
CodeSignal/examples/codeSignalProblems: DataStructure/libDTST.a
CodeSignal/examples/codeSignalProblems: CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/f/DocumentByMaking/Cpp_Challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codeSignalProblems"
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codeSignalProblems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/build: CodeSignal/examples/codeSignalProblems

.PHONY : CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/build

CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/clean:
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples && $(CMAKE_COMMAND) -P CMakeFiles/codeSignalProblems.dir/cmake_clean.cmake
.PHONY : CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/clean

CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/depend:
	cd /mnt/f/DocumentByMaking/Cpp_Challenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/f/DocumentByMaking/Cpp_Challenge /mnt/f/DocumentByMaking/Cpp_Challenge/CodeSignal/examples /mnt/f/DocumentByMaking/Cpp_Challenge/build /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples /mnt/f/DocumentByMaking/Cpp_Challenge/build/CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CodeSignal/examples/CMakeFiles/codeSignalProblems.dir/depend

