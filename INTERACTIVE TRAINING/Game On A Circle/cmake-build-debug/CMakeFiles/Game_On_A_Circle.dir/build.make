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
CMAKE_SOURCE_DIR = "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Game_On_A_Circle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game_On_A_Circle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_On_A_Circle.dir/flags.make

CMakeFiles/Game_On_A_Circle.dir/main.cpp.obj: CMakeFiles/Game_On_A_Circle.dir/flags.make
CMakeFiles/Game_On_A_Circle.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_On_A_Circle.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Game_On_A_Circle.dir\main.cpp.obj -c "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\main.cpp"

CMakeFiles/Game_On_A_Circle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_On_A_Circle.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\main.cpp" > CMakeFiles\Game_On_A_Circle.dir\main.cpp.i

CMakeFiles/Game_On_A_Circle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_On_A_Circle.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\main.cpp" -o CMakeFiles\Game_On_A_Circle.dir\main.cpp.s

# Object files for target Game_On_A_Circle
Game_On_A_Circle_OBJECTS = \
"CMakeFiles/Game_On_A_Circle.dir/main.cpp.obj"

# External object files for target Game_On_A_Circle
Game_On_A_Circle_EXTERNAL_OBJECTS =

Game_On_A_Circle.exe: CMakeFiles/Game_On_A_Circle.dir/main.cpp.obj
Game_On_A_Circle.exe: CMakeFiles/Game_On_A_Circle.dir/build.make
Game_On_A_Circle.exe: CMakeFiles/Game_On_A_Circle.dir/linklibs.rsp
Game_On_A_Circle.exe: CMakeFiles/Game_On_A_Circle.dir/objects1.rsp
Game_On_A_Circle.exe: CMakeFiles/Game_On_A_Circle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Game_On_A_Circle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Game_On_A_Circle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_On_A_Circle.dir/build: Game_On_A_Circle.exe

.PHONY : CMakeFiles/Game_On_A_Circle.dir/build

CMakeFiles/Game_On_A_Circle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Game_On_A_Circle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Game_On_A_Circle.dir/clean

CMakeFiles/Game_On_A_Circle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle" "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle" "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\Game On A Circle\cmake-build-debug\CMakeFiles\Game_On_A_Circle.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Game_On_A_Circle.dir/depend
