cmake_minimum_required(VERSION 3.15)
project(MallocWorld)
set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Program Files/JetBrains/CLion 2021.2.3/bin/cmake/cygwin/share/cmake-3.20.2/Modules")

set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL/include")
set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL/lib")

find_package(SDL2 REQUIRED)
#find_library(SDL2_LIBRARY NAME SDL2)
#find_package(SDL2_Image REQUIRED)


add_executable(MallocWorld main.cpp)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} )
target_link_libraries(MallocWorld ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY})



