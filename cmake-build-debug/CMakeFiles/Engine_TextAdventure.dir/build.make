# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/sharktallica/Downloads/CLion-2018.3.3/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sharktallica/Downloads/CLion-2018.3.3/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sharktallica/Repos/Engine-TextAdventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Engine_TextAdventure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Engine_TextAdventure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine_TextAdventure.dir/flags.make

CMakeFiles/Engine_TextAdventure.dir/main.cpp.o: CMakeFiles/Engine_TextAdventure.dir/flags.make
CMakeFiles/Engine_TextAdventure.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Engine_TextAdventure.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine_TextAdventure.dir/main.cpp.o -c /home/sharktallica/Repos/Engine-TextAdventure/main.cpp

CMakeFiles/Engine_TextAdventure.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine_TextAdventure.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sharktallica/Repos/Engine-TextAdventure/main.cpp > CMakeFiles/Engine_TextAdventure.dir/main.cpp.i

CMakeFiles/Engine_TextAdventure.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine_TextAdventure.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sharktallica/Repos/Engine-TextAdventure/main.cpp -o CMakeFiles/Engine_TextAdventure.dir/main.cpp.s

# Object files for target Engine_TextAdventure
Engine_TextAdventure_OBJECTS = \
"CMakeFiles/Engine_TextAdventure.dir/main.cpp.o"

# External object files for target Engine_TextAdventure
Engine_TextAdventure_EXTERNAL_OBJECTS =

Engine_TextAdventure: CMakeFiles/Engine_TextAdventure.dir/main.cpp.o
Engine_TextAdventure: CMakeFiles/Engine_TextAdventure.dir/build.make
Engine_TextAdventure: CMakeFiles/Engine_TextAdventure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Engine_TextAdventure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine_TextAdventure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine_TextAdventure.dir/build: Engine_TextAdventure

.PHONY : CMakeFiles/Engine_TextAdventure.dir/build

CMakeFiles/Engine_TextAdventure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine_TextAdventure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine_TextAdventure.dir/clean

CMakeFiles/Engine_TextAdventure.dir/depend:
	cd /home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sharktallica/Repos/Engine-TextAdventure /home/sharktallica/Repos/Engine-TextAdventure /home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug /home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug /home/sharktallica/Repos/Engine-TextAdventure/cmake-build-debug/CMakeFiles/Engine_TextAdventure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Engine_TextAdventure.dir/depend

