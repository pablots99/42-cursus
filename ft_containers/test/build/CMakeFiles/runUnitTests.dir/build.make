# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pablo/Desktop/42-cursus/ft_containers/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pablo/Desktop/42-cursus/ft_containers/test/build

# Include any dependencies generated for this target.
include CMakeFiles/runUnitTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runUnitTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runUnitTests.dir/flags.make

CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o: CMakeFiles/runUnitTests.dir/flags.make
CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o: ../vector/vector_contructors.cpp
CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o: CMakeFiles/runUnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pablo/Desktop/42-cursus/ft_containers/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o -MF CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o.d -o CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o -c /Users/pablo/Desktop/42-cursus/ft_containers/test/vector/vector_contructors.cpp

CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pablo/Desktop/42-cursus/ft_containers/test/vector/vector_contructors.cpp > CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.i

CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pablo/Desktop/42-cursus/ft_containers/test/vector/vector_contructors.cpp -o CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.s

# Object files for target runUnitTests
runUnitTests_OBJECTS = \
"CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o"

# External object files for target runUnitTests
runUnitTests_EXTERNAL_OBJECTS =

runUnitTests: CMakeFiles/runUnitTests.dir/vector/vector_contructors.cpp.o
runUnitTests: CMakeFiles/runUnitTests.dir/build.make
runUnitTests: lib/libgtest.a
runUnitTests: lib/libgtest_main.a
runUnitTests: lib/libgtest.a
runUnitTests: CMakeFiles/runUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pablo/Desktop/42-cursus/ft_containers/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runUnitTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runUnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runUnitTests.dir/build: runUnitTests
.PHONY : CMakeFiles/runUnitTests.dir/build

CMakeFiles/runUnitTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runUnitTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runUnitTests.dir/clean

CMakeFiles/runUnitTests.dir/depend:
	cd /Users/pablo/Desktop/42-cursus/ft_containers/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pablo/Desktop/42-cursus/ft_containers/test /Users/pablo/Desktop/42-cursus/ft_containers/test /Users/pablo/Desktop/42-cursus/ft_containers/test/build /Users/pablo/Desktop/42-cursus/ft_containers/test/build /Users/pablo/Desktop/42-cursus/ft_containers/test/build/CMakeFiles/runUnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runUnitTests.dir/depend

