# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Zack H'Doubler\source\repos\Escape-the-City"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug"

# Include any dependencies generated for this target.
include CMakeFiles/Escape-the-City_core.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Escape-the-City_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Escape-the-City_core.dir/flags.make

CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj: ../src/GameLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\GameLogic.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\GameLogic.cpp"

CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\GameLogic.cpp" > CMakeFiles\Escape-the-City_core.dir\src\GameLogic.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\GameLogic.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\GameLogic.cpp.s

CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj: ../src/Interactables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\Interactables.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\Interactables.cpp"

CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\Interactables.cpp" > CMakeFiles\Escape-the-City_core.dir\src\Interactables.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\Interactables.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\Interactables.cpp.s

CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj: ../src/LevelReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\LevelReader.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelReader.cpp"

CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelReader.cpp" > CMakeFiles\Escape-the-City_core.dir\src\LevelReader.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelReader.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\LevelReader.cpp.s

CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj: ../src/LevelState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\LevelState.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelState.cpp"

CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelState.cpp" > CMakeFiles\Escape-the-City_core.dir\src\LevelState.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\LevelState.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\LevelState.cpp.s

CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj: ../src/PlayerChar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\PlayerChar.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\PlayerChar.cpp"

CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\PlayerChar.cpp" > CMakeFiles\Escape-the-City_core.dir\src\PlayerChar.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\PlayerChar.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\PlayerChar.cpp.s

CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj: CMakeFiles/Escape-the-City_core.dir/flags.make
CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj: CMakeFiles/Escape-the-City_core.dir/includes_CXX.rsp
CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj: ../src/ScreenView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Escape-the-City_core.dir\src\ScreenView.cpp.obj -c "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\ScreenView.cpp"

CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\ScreenView.cpp" > CMakeFiles\Escape-the-City_core.dir\src\ScreenView.cpp.i

CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\src\ScreenView.cpp" -o CMakeFiles\Escape-the-City_core.dir\src\ScreenView.cpp.s

# Object files for target Escape-the-City_core
Escape__the__City_core_OBJECTS = \
"CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj" \
"CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj" \
"CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj" \
"CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj" \
"CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj" \
"CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj"

# External object files for target Escape-the-City_core
Escape__the__City_core_EXTERNAL_OBJECTS =

libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/GameLogic.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/Interactables.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/LevelReader.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/LevelState.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/PlayerChar.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/src/ScreenView.cpp.obj
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/build.make
libEscape-the-City_core.a: CMakeFiles/Escape-the-City_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libEscape-the-City_core.a"
	$(CMAKE_COMMAND) -P CMakeFiles\Escape-the-City_core.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Escape-the-City_core.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Escape-the-City_core.dir/build: libEscape-the-City_core.a

.PHONY : CMakeFiles/Escape-the-City_core.dir/build

CMakeFiles/Escape-the-City_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Escape-the-City_core.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Escape-the-City_core.dir/clean

CMakeFiles/Escape-the-City_core.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Zack H'Doubler\source\repos\Escape-the-City" "C:\Users\Zack H'Doubler\source\repos\Escape-the-City" "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug" "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug" "C:\Users\Zack H'Doubler\source\repos\Escape-the-City\Debug\CMakeFiles\Escape-the-City_core.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Escape-the-City_core.dir/depend
