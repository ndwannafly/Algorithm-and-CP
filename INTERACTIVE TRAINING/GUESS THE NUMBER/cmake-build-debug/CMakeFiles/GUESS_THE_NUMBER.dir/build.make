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
CMAKE_SOURCE_DIR = "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Guess_the_Number.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Guess_the_Number.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Guess_the_Number.dir/flags.make

CMakeFiles/Guess_the_Number.dir/main.cpp.obj: CMakeFiles/Guess_the_Number.dir/flags.make
CMakeFiles/Guess_the_Number.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Guess_the_Number.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Guess_the_Number.dir\main.cpp.obj -c "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\main.cpp"

CMakeFiles/Guess_the_Number.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Guess_the_Number.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\main.cpp" > CMakeFiles\Guess_the_Number.dir\main.cpp.i

CMakeFiles/Guess_the_Number.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Guess_the_Number.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\main.cpp" -o CMakeFiles\Guess_the_Number.dir\main.cpp.s

# Object files for target Guess_the_Number
Guess_the_Number_OBJECTS = \
"CMakeFiles/Guess_the_Number.dir/main.cpp.obj"

# External object files for target Guess_the_Number
Guess_the_Number_EXTERNAL_OBJECTS =

Guess_the_Number.exe: CMakeFiles/Guess_the_Number.dir/main.cpp.obj
Guess_the_Number.exe: CMakeFiles/Guess_the_Number.dir/build.make
Guess_the_Number.exe: CMakeFiles/Guess_the_Number.dir/linklibs.rsp
Guess_the_Number.exe: CMakeFiles/Guess_the_Number.dir/objects1.rsp
Guess_the_Number.exe: CMakeFiles/Guess_the_Number.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Guess_the_Number.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Guess_the_Number.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Guess_the_Number.dir/build: Guess_the_Number.exe

.PHONY : CMakeFiles/Guess_the_Number.dir/build

CMakeFiles/Guess_the_Number.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Guess_the_Number.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Guess_the_Number.dir/clean

CMakeFiles/Guess_the_Number.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER" "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER" "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug" "D:\ALGO\INTERACTIVE TRAINING\GUESS THE NUMBER\cmake-build-debug\CMakeFiles\GUESS_THE_NUMBER.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Guess_the_Number.dir/depend
