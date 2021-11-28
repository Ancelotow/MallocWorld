cmake_minimum_required(VERSION 3.15)
project(MallocWorld C)

set(CMAKE_C_STANDARD 99)
set(SDL2_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/ext/sdl/include)
set(SDL2_LIB_DIRS ${PROJECT_SOURCE_DIR}ext/sdl/lib)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIB_DIRS})

add_executable(MallocWorld sources/main.c sources/src/inventory/inventory.c sources/header/inventory/inventory.h sources/src/global.c sources/header/global.h sources/src/agents/monster.c sources/header/agent/monster.h sources/src/world/world.c sources/header/world/world.h sources/src/world/map/village.c sources/header/world/map/village.h sources/src/world/zone.c sources/header/world/zone.h sources/src/world/respawn.c sources/header/world/respawn.h sources/src/world/map/forest.c sources/header/world/map/forest.h sources/src/agents/player.c sources/header/agent/player.h sources/src/game/game.c sources/header/game/game.h sources/src/world/position.c sources/header/world/position.h sources/src/inventory/stack.c sources/header/inventory/stack.h sources/src/inventory/storage.c sources/header/inventory/storage.h sources/src/action/fight.c sources/header/action/fight.h sources/src/action/mining.c sources/header/action/mining.h sources/src/agents/pnj.c sources/header/agent/pnj.h sources/src/game/save.c sources/header/game/save.h sources/src/action/crafting.c sources/header/action/crafting.h sources/src/action/moving.c sources/header/action/moving.h)

