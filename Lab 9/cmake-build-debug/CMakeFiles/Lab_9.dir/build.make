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
CMAKE_SOURCE_DIR = "C:\Users\Kev\Desktop\CS\162\Lab 9"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_9.dir/flags.make

CMakeFiles/Lab_9.dir/main.cpp.obj: CMakeFiles/Lab_9.dir/flags.make
CMakeFiles/Lab_9.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_9.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_9.dir\main.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 9\main.cpp"

CMakeFiles/Lab_9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_9.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 9\main.cpp" > CMakeFiles\Lab_9.dir\main.cpp.i

CMakeFiles/Lab_9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_9.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 9\main.cpp" -o CMakeFiles\Lab_9.dir\main.cpp.s

CMakeFiles/Lab_9.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_9.dir/main.cpp.obj.requires

CMakeFiles/Lab_9.dir/main.cpp.obj.provides: CMakeFiles/Lab_9.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_9.dir\build.make CMakeFiles/Lab_9.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_9.dir/main.cpp.obj.provides

CMakeFiles/Lab_9.dir/main.cpp.obj.provides.build: CMakeFiles/Lab_9.dir/main.cpp.obj


CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj: CMakeFiles/Lab_9.dir/flags.make
CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj: ../bufferPalindrome.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_9.dir\bufferPalindrome.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 9\bufferPalindrome.cpp"

CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 9\bufferPalindrome.cpp" > CMakeFiles\Lab_9.dir\bufferPalindrome.cpp.i

CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 9\bufferPalindrome.cpp" -o CMakeFiles\Lab_9.dir\bufferPalindrome.cpp.s

CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.requires

CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.provides: CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_9.dir\build.make CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.provides

CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.provides.build: CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj


CMakeFiles/Lab_9.dir/InputValidation.cpp.obj: CMakeFiles/Lab_9.dir/flags.make
CMakeFiles/Lab_9.dir/InputValidation.cpp.obj: ../InputValidation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab_9.dir/InputValidation.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_9.dir\InputValidation.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 9\InputValidation.cpp"

CMakeFiles/Lab_9.dir/InputValidation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_9.dir/InputValidation.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 9\InputValidation.cpp" > CMakeFiles\Lab_9.dir\InputValidation.cpp.i

CMakeFiles/Lab_9.dir/InputValidation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_9.dir/InputValidation.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 9\InputValidation.cpp" -o CMakeFiles\Lab_9.dir\InputValidation.cpp.s

CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.requires

CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.provides: CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_9.dir\build.make CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.provides

CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.provides.build: CMakeFiles/Lab_9.dir/InputValidation.cpp.obj


CMakeFiles/Lab_9.dir/Menu.cpp.obj: CMakeFiles/Lab_9.dir/flags.make
CMakeFiles/Lab_9.dir/Menu.cpp.obj: ../Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab_9.dir/Menu.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_9.dir\Menu.cpp.obj -c "C:\Users\Kev\Desktop\CS\162\Lab 9\Menu.cpp"

CMakeFiles/Lab_9.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_9.dir/Menu.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kev\Desktop\CS\162\Lab 9\Menu.cpp" > CMakeFiles\Lab_9.dir\Menu.cpp.i

CMakeFiles/Lab_9.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_9.dir/Menu.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kev\Desktop\CS\162\Lab 9\Menu.cpp" -o CMakeFiles\Lab_9.dir\Menu.cpp.s

CMakeFiles/Lab_9.dir/Menu.cpp.obj.requires:

.PHONY : CMakeFiles/Lab_9.dir/Menu.cpp.obj.requires

CMakeFiles/Lab_9.dir/Menu.cpp.obj.provides: CMakeFiles/Lab_9.dir/Menu.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab_9.dir\build.make CMakeFiles/Lab_9.dir/Menu.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab_9.dir/Menu.cpp.obj.provides

CMakeFiles/Lab_9.dir/Menu.cpp.obj.provides.build: CMakeFiles/Lab_9.dir/Menu.cpp.obj


# Object files for target Lab_9
Lab_9_OBJECTS = \
"CMakeFiles/Lab_9.dir/main.cpp.obj" \
"CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj" \
"CMakeFiles/Lab_9.dir/InputValidation.cpp.obj" \
"CMakeFiles/Lab_9.dir/Menu.cpp.obj"

# External object files for target Lab_9
Lab_9_EXTERNAL_OBJECTS =

Lab_9.exe: CMakeFiles/Lab_9.dir/main.cpp.obj
Lab_9.exe: CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj
Lab_9.exe: CMakeFiles/Lab_9.dir/InputValidation.cpp.obj
Lab_9.exe: CMakeFiles/Lab_9.dir/Menu.cpp.obj
Lab_9.exe: CMakeFiles/Lab_9.dir/build.make
Lab_9.exe: CMakeFiles/Lab_9.dir/linklibs.rsp
Lab_9.exe: CMakeFiles/Lab_9.dir/objects1.rsp
Lab_9.exe: CMakeFiles/Lab_9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Lab_9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_9.dir/build: Lab_9.exe

.PHONY : CMakeFiles/Lab_9.dir/build

CMakeFiles/Lab_9.dir/requires: CMakeFiles/Lab_9.dir/main.cpp.obj.requires
CMakeFiles/Lab_9.dir/requires: CMakeFiles/Lab_9.dir/bufferPalindrome.cpp.obj.requires
CMakeFiles/Lab_9.dir/requires: CMakeFiles/Lab_9.dir/InputValidation.cpp.obj.requires
CMakeFiles/Lab_9.dir/requires: CMakeFiles/Lab_9.dir/Menu.cpp.obj.requires

.PHONY : CMakeFiles/Lab_9.dir/requires

CMakeFiles/Lab_9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_9.dir/clean

CMakeFiles/Lab_9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Kev\Desktop\CS\162\Lab 9" "C:\Users\Kev\Desktop\CS\162\Lab 9" "C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug" "C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug" "C:\Users\Kev\Desktop\CS\162\Lab 9\cmake-build-debug\CMakeFiles\Lab_9.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_9.dir/depend

