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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linus/Documents/c++/checkers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linus/Documents/c++/checkers/build

# Include any dependencies generated for this target.
include CMakeFiles/checkers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checkers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkers.dir/flags.make

CMakeFiles/checkers.dir/main.cpp.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/checkers.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers.dir/main.cpp.o -c /home/linus/Documents/c++/checkers/main.cpp

CMakeFiles/checkers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linus/Documents/c++/checkers/main.cpp > CMakeFiles/checkers.dir/main.cpp.i

CMakeFiles/checkers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linus/Documents/c++/checkers/main.cpp -o CMakeFiles/checkers.dir/main.cpp.s

CMakeFiles/checkers.dir/checkers.cpp.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/checkers.cpp.o: ../checkers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/checkers.dir/checkers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers.dir/checkers.cpp.o -c /home/linus/Documents/c++/checkers/checkers.cpp

CMakeFiles/checkers.dir/checkers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers.dir/checkers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linus/Documents/c++/checkers/checkers.cpp > CMakeFiles/checkers.dir/checkers.cpp.i

CMakeFiles/checkers.dir/checkers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers.dir/checkers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linus/Documents/c++/checkers/checkers.cpp -o CMakeFiles/checkers.dir/checkers.cpp.s

CMakeFiles/checkers.dir/bitboard.cpp.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/bitboard.cpp.o: ../bitboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/checkers.dir/bitboard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers.dir/bitboard.cpp.o -c /home/linus/Documents/c++/checkers/bitboard.cpp

CMakeFiles/checkers.dir/bitboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers.dir/bitboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linus/Documents/c++/checkers/bitboard.cpp > CMakeFiles/checkers.dir/bitboard.cpp.i

CMakeFiles/checkers.dir/bitboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers.dir/bitboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linus/Documents/c++/checkers/bitboard.cpp -o CMakeFiles/checkers.dir/bitboard.cpp.s

CMakeFiles/checkers.dir/pos.cpp.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/pos.cpp.o: ../pos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/checkers.dir/pos.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers.dir/pos.cpp.o -c /home/linus/Documents/c++/checkers/pos.cpp

CMakeFiles/checkers.dir/pos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers.dir/pos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linus/Documents/c++/checkers/pos.cpp > CMakeFiles/checkers.dir/pos.cpp.i

CMakeFiles/checkers.dir/pos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers.dir/pos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linus/Documents/c++/checkers/pos.cpp -o CMakeFiles/checkers.dir/pos.cpp.s

CMakeFiles/checkers.dir/search.cpp.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/search.cpp.o: ../search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/checkers.dir/search.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers.dir/search.cpp.o -c /home/linus/Documents/c++/checkers/search.cpp

CMakeFiles/checkers.dir/search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers.dir/search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linus/Documents/c++/checkers/search.cpp > CMakeFiles/checkers.dir/search.cpp.i

CMakeFiles/checkers.dir/search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers.dir/search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linus/Documents/c++/checkers/search.cpp -o CMakeFiles/checkers.dir/search.cpp.s

# Object files for target checkers
checkers_OBJECTS = \
"CMakeFiles/checkers.dir/main.cpp.o" \
"CMakeFiles/checkers.dir/checkers.cpp.o" \
"CMakeFiles/checkers.dir/bitboard.cpp.o" \
"CMakeFiles/checkers.dir/pos.cpp.o" \
"CMakeFiles/checkers.dir/search.cpp.o"

# External object files for target checkers
checkers_EXTERNAL_OBJECTS =

checkers: CMakeFiles/checkers.dir/main.cpp.o
checkers: CMakeFiles/checkers.dir/checkers.cpp.o
checkers: CMakeFiles/checkers.dir/bitboard.cpp.o
checkers: CMakeFiles/checkers.dir/pos.cpp.o
checkers: CMakeFiles/checkers.dir/search.cpp.o
checkers: CMakeFiles/checkers.dir/build.make
checkers: CMakeFiles/checkers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linus/Documents/c++/checkers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable checkers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkers.dir/build: checkers

.PHONY : CMakeFiles/checkers.dir/build

CMakeFiles/checkers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkers.dir/clean

CMakeFiles/checkers.dir/depend:
	cd /home/linus/Documents/c++/checkers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linus/Documents/c++/checkers /home/linus/Documents/c++/checkers /home/linus/Documents/c++/checkers/build /home/linus/Documents/c++/checkers/build /home/linus/Documents/c++/checkers/build/CMakeFiles/checkers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checkers.dir/depend

