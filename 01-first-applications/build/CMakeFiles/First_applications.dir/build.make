# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohsenh/CODE/GTK_learn/01-first-applications

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohsenh/CODE/GTK_learn/01-first-applications/build

# Include any dependencies generated for this target.
include CMakeFiles/First_applications.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/First_applications.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/First_applications.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/First_applications.dir/flags.make

CMakeFiles/First_applications.dir/src/main.cpp.o: CMakeFiles/First_applications.dir/flags.make
CMakeFiles/First_applications.dir/src/main.cpp.o: /home/mohsenh/CODE/GTK_learn/01-first-applications/src/main.cpp
CMakeFiles/First_applications.dir/src/main.cpp.o: CMakeFiles/First_applications.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohsenh/CODE/GTK_learn/01-first-applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/First_applications.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/First_applications.dir/src/main.cpp.o -MF CMakeFiles/First_applications.dir/src/main.cpp.o.d -o CMakeFiles/First_applications.dir/src/main.cpp.o -c /home/mohsenh/CODE/GTK_learn/01-first-applications/src/main.cpp

CMakeFiles/First_applications.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/First_applications.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohsenh/CODE/GTK_learn/01-first-applications/src/main.cpp > CMakeFiles/First_applications.dir/src/main.cpp.i

CMakeFiles/First_applications.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/First_applications.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohsenh/CODE/GTK_learn/01-first-applications/src/main.cpp -o CMakeFiles/First_applications.dir/src/main.cpp.s

# Object files for target First_applications
First_applications_OBJECTS = \
"CMakeFiles/First_applications.dir/src/main.cpp.o"

# External object files for target First_applications
First_applications_EXTERNAL_OBJECTS =

First_applications: CMakeFiles/First_applications.dir/src/main.cpp.o
First_applications: CMakeFiles/First_applications.dir/build.make
First_applications: CMakeFiles/First_applications.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohsenh/CODE/GTK_learn/01-first-applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable First_applications"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/First_applications.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/First_applications.dir/build: First_applications
.PHONY : CMakeFiles/First_applications.dir/build

CMakeFiles/First_applications.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/First_applications.dir/cmake_clean.cmake
.PHONY : CMakeFiles/First_applications.dir/clean

CMakeFiles/First_applications.dir/depend:
	cd /home/mohsenh/CODE/GTK_learn/01-first-applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohsenh/CODE/GTK_learn/01-first-applications /home/mohsenh/CODE/GTK_learn/01-first-applications /home/mohsenh/CODE/GTK_learn/01-first-applications/build /home/mohsenh/CODE/GTK_learn/01-first-applications/build /home/mohsenh/CODE/GTK_learn/01-first-applications/build/CMakeFiles/First_applications.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/First_applications.dir/depend
