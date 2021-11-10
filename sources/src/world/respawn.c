#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../header/world/respawn.h"

Respawn* createRespawn(int id, Position* position){
    Respawn* respawn;
    Respawn* respawnChild;

    int roundLeft;
    if(id >= 3 && id <= 11){
        roundLeft = 10;
    }else{
        roundLeft = 15;
    }
    respawn->roundLeft = roundLeft;
    respawn->id = id;
    respawn->position = position;
    respawn->child = respawnChild;
}

void updateAllRespawn(Respawn* respawn) {
    respawn->roundLeft--;
}

void printPosition(Position* position){
    printf("%d %d %d", position->x, position->y, position->zone);
}

void printRespawn(Respawn* respawn){
    printPosition(respawn->position);
    printf("%d %d", respawn->id, respawn->roundLeft);
    if(respawn->child != NULL){
        printRespawn(respawn->child);
    }
}

void freeRespawn(Respawn* respawn){
    freePosition(respawn->position);
    free(respawn);
}

