cmake_minimum_required(VERSION 3.15)
project(MallocWorld)
set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Program Files/JetBrains/CLion 2021.2.3/bin/cmake/cygwin/share/cmake-3.20.2/Modules")

#set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL/include")
#set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL/lib")

#find_package(SDL2 REQUIRED)
#find_library(SDL2_LIBRARY NAME SDL2)
#find_package(SDL2_Image REQUIRED)


add_executable(MallocWorld sources/main.c sources/src/inventory/inventory.c sources/header/inventory/inventory.h sources/src/global.c sources/header/global.h sources/src/monster.c sources/header/monster.h sources/src/world/world.c sources/header/world/world.h sources/src/world/map/village.c sources/header/world/map/village.h sources/src/world/zone.c sources/header/world/zone.h sources/src/world/respawn.c sources/header/world/respawn.h sources/src/world/map/forest.c sources/header/world/map/forest.h sources/src/player.c sources/header/player.h sources/src/game.c sources/header/game.h sources/src/position.c sources/header/position.h sources/src/inventory/stack.c sources/header/inventory/stack.h sources/src/inventory/storage.c sources/header/inventory/storage.h sources/src/action/fight.c sources/header/action/fight.h sources/src/action/mining.c sources/header/action/mining.h)

#include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} )
#target_link_libraries(MallocWorld ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY})



