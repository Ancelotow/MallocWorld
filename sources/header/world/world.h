//
// Created by Admin on 16/10/2021.
//

#ifndef MALLOCWORLD_WORLD_H
#define MALLOCWORLD_WORLD_H

#include "zone.h"
#include "respawn.h"

#define NB_ZONE 3

typedef struct World{
    Zone** world;
    Respawn respawnHeader;
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
