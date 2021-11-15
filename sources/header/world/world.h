/*
**  Filename : world.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'world.c'. Manage the world and his zones
*/

#ifndef MALLOCWORLD_WORLD_H
#define MALLOCWORLD_WORLD_H

typedef struct Zone Zone;
#include <stdio.h>

#define NB_ZONE 3

typedef struct World{
    Zone** world;
} World;

/**
 * Generate the world
 * @return The world generated
 */
World* generateWorld();

/**
 * Printed into the console the world
 * @param world The world
 */
void printOriginalWorld(World world);

/**
 * Free the world (including zone and respawn) from memory
 * @param world The world
 */
void freeWorld(World* world);

void saveWorld(FILE* file, World world);

#endif //MALLOCWORLD_WORLD_H
