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
 * Génération du monde
 * @return Le monde généré
 */
World* generateWorld();

/**
 * Affiche le monde
 * @param world Le monde
 */
void printOriginalWorld(World world);

/**
 * Libère le monde de la mémoire
 * @param world Le monde
 */
void freeWorld(World* world);

#endif //MALLOCWORLD_WORLD_H
