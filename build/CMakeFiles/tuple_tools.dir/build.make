# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = G:\buildtools\cmake-3.14.0-rc1-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = G:\buildtools\cmake-3.14.0-rc1-win64-x64\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\toys\c++\build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\toys\c++\build

# Include any dependencies generated for this target.
include CMakeFiles/tuple_tools.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tuple_tools.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tuple_tools.dir/flags.make

CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.obj: CMakeFiles/tuple_tools.dir/flags.make
CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.obj: H:/toys/c++/src/tuple_tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\toys\c++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tuple_tools.dir\H_\toys\c++\src\tuple_tools.cpp.obj -c H:\toys\c++\src\tuple_tools.cpp

CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\toys\c++\src\tuple_tools.cpp > CMakeFiles\tuple_tools.dir\H_\toys\c++\src\tuple_tools.cpp.i

CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\toys\c++\src\tuple_tools.cpp -o CMakeFiles\tuple_tools.dir\H_\toys\c++\src\tuple_tools.cpp.s

# Object files for target tuple_tools
tuple_tools_OBJECTS = \
"CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.obj"

# External object files for target tuple_tools
tuple_tools_EXTERNAL_OBJECTS =

bin/tuple_tools.exe: CMakeFiles/tuple_tools.dir/H_/toys/c++/src/tuple_tools.cpp.obj
bin/tuple_tools.exe: CMakeFiles/tuple_tools.dir/build.make
bin/tuple_tools.exe: CMakeFiles/tuple_tools.dir/linklibs.rsp
bin/tuple_tools.exe: CMakeFiles/tuple_tools.dir/objects1.rsp
bin/tuple_tools.exe: CMakeFiles/tuple_tools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\toys\c++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\tuple_tools.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tuple_tools.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tuple_tools.dir/build: bin/tuple_tools.exe

.PHONY : CMakeFiles/tuple_tools.dir/build

CMakeFiles/tuple_tools.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tuple_tools.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tuple_tools.dir/clean

CMakeFiles/tuple_tools.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\toys\c++\build H:\toys\c++\build H:\toys\c++\build H:\toys\c++\build H:\toys\c++\build\CMakeFiles\tuple_tools.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tuple_tools.dir/depend

