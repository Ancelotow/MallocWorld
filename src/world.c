#include "../header/world.h"
#include "../header/global.h"
#include "../header/map/village.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


World* generateWorld(){
    World* world = malloc(sizeof(World));
    world->originalWorld = malloc(sizeof(Zone*) * NB_ZONE);
    world->originalWorld[0] = generateZone(ZONE_1);
    world->originalWorld[1] = generateZone(ZONE_2);
    world->originalWorld[2] = generateZone(ZONE_3);
    return world;
}

void printOriginalWorld(World world){
    printf("====================== WORLD =========================\n\n\n");
    for(int i=0; i < NB_ZONE; i++){
        printZone(world.originalWorld[i]);
    }
    printf("\n\n======================================================");
}

void freeWorld(World* world){
    for(int i=0; i < NB_ZONE; i++){
        freeZone(world->originalWorld[i]);
        //freeZone(world->currentWorld[i]);
    }
    free(world);
}