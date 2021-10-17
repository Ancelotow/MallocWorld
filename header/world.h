//
// Created by Admin on 16/10/2021.
//

#ifndef MALLOCWORLD_WORLD_H
#define MALLOCWORLD_WORLD_H

#include "zone.h"

#define NB_ZONE 3

typedef struct World{
    Zone** originalWorld;
    Zone** currentWorld;
} World;

World* generateWorld();
void printOriginalWorld(World world);
void freeWorld(World* world);

#endif //MALLOCWORLD_WORLD_H
