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
CMAKE_SOURCE_DIR = "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Median_Sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Median_Sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Median_Sort.dir/flags.make

CMakeFiles/Median_Sort.dir/main.cpp.obj: CMakeFiles/Median_Sort.dir/flags.make
CMakeFiles/Median_Sort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Median_Sort.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Median_Sort.dir\main.cpp.obj -c "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\main.cpp"

CMakeFiles/Median_Sort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Median_Sort.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\main.cpp" > CMakeFiles\Median_Sort.dir\main.cpp.i

CMakeFiles/Median_Sort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Median_Sort.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\main.cpp" -o CMakeFiles\Median_Sort.dir\main.cpp.s

# Object files for target Median_Sort
Median_Sort_OBJECTS = \
"CMakeFiles/Median_Sort.dir/main.cpp.obj"

# External object files for target Median_Sort
Median_Sort_EXTERNAL_OBJECTS =

Median_Sort.exe: CMakeFiles/Median_Sort.dir/main.cpp.obj
Median_Sort.exe: CMakeFiles/Median_Sort.dir/build.make
Median_Sort.exe: CMakeFiles/Median_Sort.dir/linklibs.rsp
Median_Sort.exe: CMakeFiles/Median_Sort.dir/objects1.rsp
Median_Sort.exe: CMakeFiles/Median_Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Median_Sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Median_Sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Median_Sort.dir/build: Median_Sort.exe

.PHONY : CMakeFiles/Median_Sort.dir/build

CMakeFiles/Median_Sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Median_Sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Median_Sort.dir/clean

CMakeFiles/Median_Sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort" "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort" "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug" "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug" "D:\ALGO\Google Code Jam\2021\Qualification Round\Median Sort\cmake-build-debug\CMakeFiles\Median_Sort.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Median_Sort.dir/depend

