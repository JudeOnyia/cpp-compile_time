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
CMAKE_COMMAND = /home/frodo/public/ugls_lab-4.0.70/packages/cmake-3.17.1/bin/cmake

# The command to remove a file.
RM = /home/frodo/public/ugls_lab-4.0.70/packages/cmake-3.17.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived

# Include any dependencies generated for this target.
include CMakeFiles/test_cexpr_basic_string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_cexpr_basic_string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_cexpr_basic_string.dir/flags.make

CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o: CMakeFiles/test_cexpr_basic_string.dir/flags.make
CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o: /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source/app/test_cexpr_basic_string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o"
	/home/frodo/public/ugls_lab-4.0.70/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o -c /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source/app/test_cexpr_basic_string.cpp

CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.i"
	/home/frodo/public/ugls_lab-4.0.70/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source/app/test_cexpr_basic_string.cpp > CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.i

CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.s"
	/home/frodo/public/ugls_lab-4.0.70/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source/app/test_cexpr_basic_string.cpp -o CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.s

# Object files for target test_cexpr_basic_string
test_cexpr_basic_string_OBJECTS = \
"CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o"

# External object files for target test_cexpr_basic_string
test_cexpr_basic_string_EXTERNAL_OBJECTS =

test_cexpr_basic_string: CMakeFiles/test_cexpr_basic_string.dir/app/test_cexpr_basic_string.cpp.o
test_cexpr_basic_string: CMakeFiles/test_cexpr_basic_string.dir/build.make
test_cexpr_basic_string: CMakeFiles/test_cexpr_basic_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_cexpr_basic_string"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cexpr_basic_string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_cexpr_basic_string.dir/build: test_cexpr_basic_string

.PHONY : CMakeFiles/test_cexpr_basic_string.dir/build

CMakeFiles/test_cexpr_basic_string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_cexpr_basic_string.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_cexpr_basic_string.dir/clean

CMakeFiles/test_cexpr_basic_string.dir/depend:
	cd /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/source /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived /home/judeonyia/Documents/ECE596C_Assignments/ECE596C_Assgn_2/cpp_compile_time-JudeOnyia/cktmp/package-string_orig/derived/CMakeFiles/test_cexpr_basic_string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_cexpr_basic_string.dir/depend

