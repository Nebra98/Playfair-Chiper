# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/135/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/135/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nebra/Desktop/Programming/C/PlayfairChiper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PlayfairChiper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PlayfairChiper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlayfairChiper.dir/flags.make

CMakeFiles/PlayfairChiper.dir/main.c.o: CMakeFiles/PlayfairChiper.dir/flags.make
CMakeFiles/PlayfairChiper.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PlayfairChiper.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PlayfairChiper.dir/main.c.o   -c /home/nebra/Desktop/Programming/C/PlayfairChiper/main.c

CMakeFiles/PlayfairChiper.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PlayfairChiper.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nebra/Desktop/Programming/C/PlayfairChiper/main.c > CMakeFiles/PlayfairChiper.dir/main.c.i

CMakeFiles/PlayfairChiper.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PlayfairChiper.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nebra/Desktop/Programming/C/PlayfairChiper/main.c -o CMakeFiles/PlayfairChiper.dir/main.c.s

# Object files for target PlayfairChiper
PlayfairChiper_OBJECTS = \
"CMakeFiles/PlayfairChiper.dir/main.c.o"

# External object files for target PlayfairChiper
PlayfairChiper_EXTERNAL_OBJECTS =

PlayfairChiper: CMakeFiles/PlayfairChiper.dir/main.c.o
PlayfairChiper: CMakeFiles/PlayfairChiper.dir/build.make
PlayfairChiper: CMakeFiles/PlayfairChiper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PlayfairChiper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlayfairChiper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlayfairChiper.dir/build: PlayfairChiper

.PHONY : CMakeFiles/PlayfairChiper.dir/build

CMakeFiles/PlayfairChiper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PlayfairChiper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PlayfairChiper.dir/clean

CMakeFiles/PlayfairChiper.dir/depend:
	cd /home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nebra/Desktop/Programming/C/PlayfairChiper /home/nebra/Desktop/Programming/C/PlayfairChiper /home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug /home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug /home/nebra/Desktop/Programming/C/PlayfairChiper/cmake-build-debug/CMakeFiles/PlayfairChiper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PlayfairChiper.dir/depend

