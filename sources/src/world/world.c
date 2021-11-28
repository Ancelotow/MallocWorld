/*
**  Filename : world.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the world (create three zones randomly)
*/

#include "../../header/global.h"

/**
 * Génération du monde
 * @return Le monde généré
 */
World* generateWorld(){
    World* world = malloc(sizeof(World));
    world->world = malloc(sizeof(Zone*) * NB_ZONE);
    world->world[0] = generateZone(ZONE_1);
    world->world[1] = generateZone(ZONE_2);
    world->world[2] = generateZone(ZONE_3);
    return world;
}

/**
 * Affiche le monde
 * @param world Le monde
 */
void printOriginalWorld(World world){
    printf("====================== WORLD =========================\n\n\n");
    for(int i=0; i < NB_ZONE; i++){
        printZoneDebug(world.world[i]);
    }
    printf("\n\n======================================================");
}

/**
 * Libère le monde de la mémoire
 * @param world Le monde
 */
void freeWorld(World* world){
    for(int i=0; i < NB_ZONE; i++){
        freeZone(world->world[i]);
    }
    free(world);
}
