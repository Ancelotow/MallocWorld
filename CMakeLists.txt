cmake_minimum_required(VERSION 3.15)
project(MallocWorld C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/sdl/cmake")

#et(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/sdl/include/SLD2/")
#set(SDL2_IMAGE_LIBRARY "${PROJECT_SOURCE_DIR}/sdl/lib/SDL2_image.lib")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_Image REQUIRED)


add_executable(MallocWorld sources/main.c sources/src/inventory/inventory.c sources/header/inventory/inventory.h sources/src/global.c sources/header/global.h sources/src/monster.c sources/header/monster.h sources/src/world/world.c sources/header/world/world.h sources/src/world/map/village.c sources/header/world/map/village.h sources/src/world/zone.c sources/header/world/zone.h sources/src/world/respawn.c sources/header/world/respawn.h sources/src/world/map/forest.c sources/header/world/map/forest.h sources/src/player.c sources/header/player.h sources/src/game.c sources/header/game.h sources/src/position.c sources/header/position.h sources/src/inventory/stack.c sources/header/inventory/stack.h sources/src/inventory/storage.c sources/header/inventory/storage.h)
#include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_IMAGE_INCLUDE_DIR})
#target_link_libraries(MallocWorld ${SDL2_LIBRARY})