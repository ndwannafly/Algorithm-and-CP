# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\ALGO\INTERACTIVE TRAINING\Limited Moves"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Limited_Moves.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Limited_Moves.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Limited_Moves.dir/flags.make

CMakeFiles/Limited_Moves.dir/main.cpp.obj: CMakeFiles/Limited_Moves.dir/flags.make
CMakeFiles/Limited_Moves.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Limited_Moves.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Limited_Moves.dir\main.cpp.obj -c "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\main.cpp"

CMakeFiles/Limited_Moves.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Limited_Moves.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\main.cpp" > CMakeFiles\Limited_Moves.dir\main.cpp.i

CMakeFiles/Limited_Moves.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Limited_Moves.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\main.cpp" -o CMakeFiles\Limited_Moves.dir\main.cpp.s

# Object files for target Limited_Moves
Limited_Moves_OBJECTS = \
"CMakeFiles/Limited_Moves.dir/main.cpp.obj"

# External object files for target Limited_Moves
Limited_Moves_EXTERNAL_OBJECTS =

Limited_Moves.exe: CMakeFiles/Limited_Moves.dir/main.cpp.obj
Limited_Moves.exe: CMakeFiles/Limited_Moves.dir/build.make
Limited_Moves.exe: CMakeFiles/Limited_Moves.dir/linklibs.rsp
Limited_Moves.exe: CMakeFiles/Limited_Moves.dir/objects1.rsp
Limited_Moves.exe: CMakeFiles/Limited_Moves.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Limited_Moves.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Limited_Moves.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Limited_Moves.dir/build: Limited_Moves.exe

.PHONY : CMakeFiles/Limited_Moves.dir/build

CMakeFiles/Limited_Moves.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Limited_Moves.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Limited_Moves.dir/clean

CMakeFiles/Limited_Moves.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ALGO\INTERACTIVE TRAINING\Limited Moves" "D:\ALGO\INTERACTIVE TRAINING\Limited Moves" "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\Limited Moves\cmake-build-debug\CMakeFiles\Limited_Moves.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Limited_Moves.dir/depend
