# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Kev\Desktop\CS\162\Lab 10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_10.dir/flags.make

CMakeFiles/Lab_10.dir/main.cpp.obj: CMakeFiles/Lab_10.dir/flags.make
CMakeFiles/Lab_10.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_10.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_10.dir\main.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 10\main.cpp"

CMakeFiles/Lab_10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_10.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 10\main.cpp" > CMakeFiles\Lab_10.dir\main.cpp.i

CMakeFiles/Lab_10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_10.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 10\main.cpp" -o CMakeFiles\Lab_10.dir\main.cpp.s

CMakeFiles/Lab_10.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_10.dir/main.cpp.obj.requires

CMakeFiles/Lab_10.dir/main.cpp.obj.provides: CMakeFiles/Lab_10.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_10.dir\build.make CMakeFiles/Lab_10.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_10.dir/main.cpp.obj.provides

CMakeFiles/Lab_10.dir/main.cpp.obj.provides.build: CMakeFiles/Lab_10.dir/main.cpp.obj


CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj: CMakeFiles/Lab_10.dir/flags.make
CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj: ../FibonacciNR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_10.dir\FibonacciNR.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciNR.cpp"

CMakeFiles/Lab_10.dir/FibonacciNR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_10.dir/FibonacciNR.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciNR.cpp" > CMakeFiles\Lab_10.dir\FibonacciNR.cpp.i

CMakeFiles/Lab_10.dir/FibonacciNR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_10.dir/FibonacciNR.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciNR.cpp" -o CMakeFiles\Lab_10.dir\FibonacciNR.cpp.s

CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.requires

CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.provides: CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_10.dir\build.make CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.provides

CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.provides.build: CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj


CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj: CMakeFiles/Lab_10.dir/flags.make
CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj: ../FibonacciR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_10.dir\FibonacciR.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciR.cpp"

CMakeFiles/Lab_10.dir/FibonacciR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_10.dir/FibonacciR.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciR.cpp" > CMakeFiles\Lab_10.dir\FibonacciR.cpp.i

CMakeFiles/Lab_10.dir/FibonacciR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_10.dir/FibonacciR.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 10\FibonacciR.cpp" -o CMakeFiles\Lab_10.dir\FibonacciR.cpp.s

CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.requires

CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.provides: CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_10.dir\build.make CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.provides

CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.provides.build: CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj


# Object files for target Lab_10
Lab_10_OBJECTS = \
"CMakeFiles/Lab_10.dir/main.cpp.obj" \
"CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj" \
"CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj"

# External object files for target Lab_10
Lab_10_EXTERNAL_OBJECTS =

Lab_10.exe: CMakeFiles/Lab_10.dir/main.cpp.obj
Lab_10.exe: CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj
Lab_10.exe: CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj
Lab_10.exe: CMakeFiles/Lab_10.dir/build.make
Lab_10.exe: CMakeFiles/Lab_10.dir/linklibs.rsp
Lab_10.exe: CMakeFiles/Lab_10.dir/objects1.rsp
Lab_10.exe: CMakeFiles/Lab_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Lab_10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_10.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_10.dir/build: Lab_10.exe

.PHONY : CMakeFiles/Lab_10.dir/build

CMakeFiles/Lab_10.dir/requires: CMakeFiles/Lab_10.dir/main.cpp.obj.requires
CMakeFiles/Lab_10.dir/requires: CMakeFiles/Lab_10.dir/FibonacciNR.cpp.obj.requires
CMakeFiles/Lab_10.dir/requires: CMakeFiles/Lab_10.dir/FibonacciR.cpp.obj.requires

.PHONY : CMakeFiles/Lab_10.dir/requires

CMakeFiles/Lab_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_10.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_10.dir/clean

CMakeFiles/Lab_10.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Kev\Desktop\CS\162\Lab 10" "C:\Users\Kev\Desktop\CS\162\Lab 10" "C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug" "C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug" "C:\Users\Kev\Desktop\CS\162\Lab 10\cmake-build-debug\CMakeFiles\Lab_10.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_10.dir/depend

