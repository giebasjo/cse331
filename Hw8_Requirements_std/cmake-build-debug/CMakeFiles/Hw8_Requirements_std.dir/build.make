# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/GIBZ/331/Hw8_Requirements_std

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hw8_Requirements_std.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hw8_Requirements_std.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hw8_Requirements_std.dir/flags.make

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o: CMakeFiles/Hw8_Requirements_std.dir/flags.make
CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o: ../BSTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o -c /Users/GIBZ/331/Hw8_Requirements_std/BSTree.cpp

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GIBZ/331/Hw8_Requirements_std/BSTree.cpp > CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.i

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GIBZ/331/Hw8_Requirements_std/BSTree.cpp -o CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.s

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.requires:

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.requires

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.provides: CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hw8_Requirements_std.dir/build.make CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.provides.build
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.provides

CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.provides.build: CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o


CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o: CMakeFiles/Hw8_Requirements_std.dir/flags.make
CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o: ../HashTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o -c /Users/GIBZ/331/Hw8_Requirements_std/HashTable.cpp

CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GIBZ/331/Hw8_Requirements_std/HashTable.cpp > CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.i

CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GIBZ/331/Hw8_Requirements_std/HashTable.cpp -o CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.s

CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.requires:

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.requires

CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.provides: CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hw8_Requirements_std.dir/build.make CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.provides.build
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.provides

CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.provides.build: CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o


CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o: CMakeFiles/Hw8_Requirements_std.dir/flags.make
CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o: ../login.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o -c /Users/GIBZ/331/Hw8_Requirements_std/login.cpp

CMakeFiles/Hw8_Requirements_std.dir/login.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hw8_Requirements_std.dir/login.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GIBZ/331/Hw8_Requirements_std/login.cpp > CMakeFiles/Hw8_Requirements_std.dir/login.cpp.i

CMakeFiles/Hw8_Requirements_std.dir/login.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hw8_Requirements_std.dir/login.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GIBZ/331/Hw8_Requirements_std/login.cpp -o CMakeFiles/Hw8_Requirements_std.dir/login.cpp.s

CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.requires:

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.requires

CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.provides: CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hw8_Requirements_std.dir/build.make CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.provides.build
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.provides

CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.provides.build: CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o


CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o: CMakeFiles/Hw8_Requirements_std.dir/flags.make
CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o -c /Users/GIBZ/331/Hw8_Requirements_std/main.cpp

CMakeFiles/Hw8_Requirements_std.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hw8_Requirements_std.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GIBZ/331/Hw8_Requirements_std/main.cpp > CMakeFiles/Hw8_Requirements_std.dir/main.cpp.i

CMakeFiles/Hw8_Requirements_std.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hw8_Requirements_std.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GIBZ/331/Hw8_Requirements_std/main.cpp -o CMakeFiles/Hw8_Requirements_std.dir/main.cpp.s

CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.requires

CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.provides: CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hw8_Requirements_std.dir/build.make CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.provides

CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.provides.build: CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o


CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o: CMakeFiles/Hw8_Requirements_std.dir/flags.make
CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o: ../test10.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o -c /Users/GIBZ/331/Hw8_Requirements_std/test10.cpp

CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/GIBZ/331/Hw8_Requirements_std/test10.cpp > CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.i

CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/GIBZ/331/Hw8_Requirements_std/test10.cpp -o CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.s

CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.requires:

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.requires

CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.provides: CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hw8_Requirements_std.dir/build.make CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.provides.build
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.provides

CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.provides.build: CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o


# Object files for target Hw8_Requirements_std
Hw8_Requirements_std_OBJECTS = \
"CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o" \
"CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o" \
"CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o" \
"CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o" \
"CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o"

# External object files for target Hw8_Requirements_std
Hw8_Requirements_std_EXTERNAL_OBJECTS =

Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/build.make
Hw8_Requirements_std: CMakeFiles/Hw8_Requirements_std.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Hw8_Requirements_std"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hw8_Requirements_std.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hw8_Requirements_std.dir/build: Hw8_Requirements_std

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/build

CMakeFiles/Hw8_Requirements_std.dir/requires: CMakeFiles/Hw8_Requirements_std.dir/BSTree.cpp.o.requires
CMakeFiles/Hw8_Requirements_std.dir/requires: CMakeFiles/Hw8_Requirements_std.dir/HashTable.cpp.o.requires
CMakeFiles/Hw8_Requirements_std.dir/requires: CMakeFiles/Hw8_Requirements_std.dir/login.cpp.o.requires
CMakeFiles/Hw8_Requirements_std.dir/requires: CMakeFiles/Hw8_Requirements_std.dir/main.cpp.o.requires
CMakeFiles/Hw8_Requirements_std.dir/requires: CMakeFiles/Hw8_Requirements_std.dir/test10.cpp.o.requires

.PHONY : CMakeFiles/Hw8_Requirements_std.dir/requires

CMakeFiles/Hw8_Requirements_std.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hw8_Requirements_std.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/clean

CMakeFiles/Hw8_Requirements_std.dir/depend:
	cd /Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/GIBZ/331/Hw8_Requirements_std /Users/GIBZ/331/Hw8_Requirements_std /Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug /Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug /Users/GIBZ/331/Hw8_Requirements_std/cmake-build-debug/CMakeFiles/Hw8_Requirements_std.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hw8_Requirements_std.dir/depend

