cmake_minimum_required(VERSION 3.15)
project(MallocWorld C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/SDL/cmake")

#et(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL/include/SLD2/")
#set(SDL2_IMAGE_LIBRARY "${PROJECT_SOURCE_DIR}/SDL/lib/SDL2_image.lib")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_Image REQUIRED)


add_executable(MallocWorld main.c src/inventory.c header/inventory.h src/global.c header/global.h src/monster.c header/monster.h src/world.c header/world.h src/map/village.c header/map/village.h src/zone.c header/zone.h src/respawn.c header/respawn.h src/map/forest.c header/map/forest.h)
#include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_IMAGE_INCLUDE_DIR})
#target_link_libraries(MallocWorld ${SDL2_LIBRARY})