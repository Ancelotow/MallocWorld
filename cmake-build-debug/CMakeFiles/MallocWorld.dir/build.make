# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Elsa Firmin\CLionProjects\MallocWorld"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MallocWorld.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MallocWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MallocWorld.dir/flags.make

CMakeFiles/MallocWorld.dir/sources/main.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/main.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/main.c.obj: ../sources/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MallocWorld.dir/sources/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\main.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\main.c"

CMakeFiles/MallocWorld.dir/sources/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\main.c" > CMakeFiles\MallocWorld.dir\sources\main.c.i

CMakeFiles/MallocWorld.dir/sources/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\main.c" -o CMakeFiles\MallocWorld.dir\sources\main.c.s

CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj: ../sources/src/inventory/inventory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\inventory\inventory.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\inventory.c"

CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\inventory.c" > CMakeFiles\MallocWorld.dir\sources\src\inventory\inventory.c.i

CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\inventory.c" -o CMakeFiles\MallocWorld.dir\sources\src\inventory\inventory.c.s

CMakeFiles/MallocWorld.dir/sources/src/global.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/global.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/global.c.obj: ../sources/src/global.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MallocWorld.dir/sources/src/global.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\global.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\global.c"

CMakeFiles/MallocWorld.dir/sources/src/global.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/global.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\global.c" > CMakeFiles\MallocWorld.dir\sources\src\global.c.i

CMakeFiles/MallocWorld.dir/sources/src/global.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/global.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\global.c" -o CMakeFiles\MallocWorld.dir\sources\src\global.c.s

CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj: ../sources/src/agents/monster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\agents\monster.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\monster.c"

CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\monster.c" > CMakeFiles\MallocWorld.dir\sources\src\agents\monster.c.i

CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\monster.c" -o CMakeFiles\MallocWorld.dir\sources\src\agents\monster.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj: ../sources/src/world/world.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\world.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\world.c"

CMakeFiles/MallocWorld.dir/sources/src/world/world.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/world.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\world.c" > CMakeFiles\MallocWorld.dir\sources\src\world\world.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/world.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/world.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\world.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\world.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj: ../sources/src/world/map/village.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\map\village.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\village.c"

CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\village.c" > CMakeFiles\MallocWorld.dir\sources\src\world\map\village.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\village.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\map\village.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj: ../sources/src/world/zone.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\zone.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\zone.c"

CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\zone.c" > CMakeFiles\MallocWorld.dir\sources\src\world\zone.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\zone.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\zone.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj: ../sources/src/world/respawn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\respawn.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\respawn.c"

CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\respawn.c" > CMakeFiles\MallocWorld.dir\sources\src\world\respawn.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\respawn.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\respawn.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj: ../sources/src/world/map/forest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\map\forest.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\forest.c"

CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\forest.c" > CMakeFiles\MallocWorld.dir\sources\src\world\map\forest.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\map\forest.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\map\forest.c.s

CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj: ../sources/src/agents/player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\agents\player.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\player.c"

CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\player.c" > CMakeFiles\MallocWorld.dir\sources\src\agents\player.c.i

CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\player.c" -o CMakeFiles\MallocWorld.dir\sources\src\agents\player.c.s

CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj: ../sources/src/game/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\game\game.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\game.c"

CMakeFiles/MallocWorld.dir/sources/src/game/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/game/game.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\game.c" > CMakeFiles\MallocWorld.dir\sources\src\game\game.c.i

CMakeFiles/MallocWorld.dir/sources/src/game/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/game/game.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\game.c" -o CMakeFiles\MallocWorld.dir\sources\src\game\game.c.s

CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj: ../sources/src/world/position.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\world\position.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\position.c"

CMakeFiles/MallocWorld.dir/sources/src/world/position.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/world/position.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\position.c" > CMakeFiles\MallocWorld.dir\sources\src\world\position.c.i

CMakeFiles/MallocWorld.dir/sources/src/world/position.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/world/position.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\world\position.c" -o CMakeFiles\MallocWorld.dir\sources\src\world\position.c.s

CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj: ../sources/src/inventory/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\inventory\stack.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\stack.c"

CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\stack.c" > CMakeFiles\MallocWorld.dir\sources\src\inventory\stack.c.i

CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\stack.c" -o CMakeFiles\MallocWorld.dir\sources\src\inventory\stack.c.s

CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj: ../sources/src/inventory/storage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\inventory\storage.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\storage.c"

CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\storage.c" > CMakeFiles\MallocWorld.dir\sources\src\inventory\storage.c.i

CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\inventory\storage.c" -o CMakeFiles\MallocWorld.dir\sources\src\inventory\storage.c.s

CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj: ../sources/src/action/fight.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\action\fight.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\fight.c"

CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\fight.c" > CMakeFiles\MallocWorld.dir\sources\src\action\fight.c.i

CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\fight.c" -o CMakeFiles\MallocWorld.dir\sources\src\action\fight.c.s

CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj: ../sources/src/action/mining.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\action\mining.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\mining.c"

CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\mining.c" > CMakeFiles\MallocWorld.dir\sources\src\action\mining.c.i

CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\action\mining.c" -o CMakeFiles\MallocWorld.dir\sources\src\action\mining.c.s

CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj: ../sources/src/agents/pnj.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\agents\pnj.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\pnj.c"

CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\pnj.c" > CMakeFiles\MallocWorld.dir\sources\src\agents\pnj.c.i

CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\agents\pnj.c" -o CMakeFiles\MallocWorld.dir\sources\src\agents\pnj.c.s

CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj: ../sources/src/game/save.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\game\save.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\save.c"

CMakeFiles/MallocWorld.dir/sources/src/game/save.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/game/save.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\save.c" > CMakeFiles\MallocWorld.dir\sources\src\game\save.c.i

CMakeFiles/MallocWorld.dir/sources/src/game/save.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/game/save.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\save.c" -o CMakeFiles\MallocWorld.dir\sources\src\game\save.c.s

CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj: CMakeFiles/MallocWorld.dir/flags.make
CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj: CMakeFiles/MallocWorld.dir/includes_C.rsp
CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj: ../sources/src/game/restore.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MallocWorld.dir\sources\src\game\restore.c.obj -c "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\restore.c"

CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\restore.c" > CMakeFiles\MallocWorld.dir\sources\src\game\restore.c.i

CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\sources\src\game\restore.c" -o CMakeFiles\MallocWorld.dir\sources\src\game\restore.c.s

# Object files for target MallocWorld
MallocWorld_OBJECTS = \
"CMakeFiles/MallocWorld.dir/sources/main.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/global.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj" \
"CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj"

# External object files for target MallocWorld
MallocWorld_EXTERNAL_OBJECTS =

MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/main.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/inventory/inventory.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/global.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/agents/monster.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/world.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/map/village.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/zone.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/respawn.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/map/forest.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/agents/player.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/game/game.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/world/position.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/inventory/stack.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/inventory/storage.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/action/fight.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/action/mining.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/agents/pnj.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/game/save.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/sources/src/game/restore.c.obj
MallocWorld.exe: CMakeFiles/MallocWorld.dir/build.make
MallocWorld.exe: CMakeFiles/MallocWorld.dir/linklibs.rsp
MallocWorld.exe: CMakeFiles/MallocWorld.dir/objects1.rsp
MallocWorld.exe: CMakeFiles/MallocWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_20) "Linking C executable MallocWorld.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MallocWorld.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MallocWorld.dir/build: MallocWorld.exe
.PHONY : CMakeFiles/MallocWorld.dir/build

CMakeFiles/MallocWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MallocWorld.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MallocWorld.dir/clean

CMakeFiles/MallocWorld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Elsa Firmin\CLionProjects\MallocWorld" "C:\Users\Elsa Firmin\CLionProjects\MallocWorld" "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug" "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug" "C:\Users\Elsa Firmin\CLionProjects\MallocWorld\cmake-build-debug\CMakeFiles\MallocWorld.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MallocWorld.dir/depend

