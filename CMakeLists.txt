cmake_minimum_required(VERSION 3.15)
project(MallocWorld C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/sdl/cmake")

#et(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/sdl/include/SLD2/")
#set(SDL2_IMAGE_LIBRARY "${PROJECT_SOURCE_DIR}/sdl/lib/SDL2_image.lib")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_Image REQUIRED)


add_executable(MallocWorld sources/main.c sources/src/inventory.c sources/header/inventory.h sources/src/global.c sources/header/global.h sources/src/monster.c sources/header/monster.h sources/src/world.c sources/header/world.h sources/src/map/village.c sources/header/map/village.h sources/src/zone.c sources/header/zone.h sources/src/respawn.c sources/header/respawn.h sources/src/map/forest.c sources/header/map/forest.h sources/src/player.c sources/header/player.h sources/src/game.c sources/header/game.h sources/src/position.c sources/header/position.h)
#include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_IMAGE_INCLUDE_DIR})
#target_link_libraries(MallocWorld ${SDL2_LIBRARY})