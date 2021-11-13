/*
**  Filename : respawn.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage the respawn of resources and monsters when player kill monster or mine a resource.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../header/world/respawn.h"


/*
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

void appendRespawn(Respawn* respawn, int id, Position* position) {
    createRespawn(id, position);
}
**/
/**
 * presque, si le roundLeft est à 0, il faut le supprimer...
 */
/**
void updateAllRespawn(Respawn* respawn) {
    respawn->roundLeft--;
    if(respawn->roundLeft == 0){
        //supprimer un respawn
    }
    if(respawn->child != NULL){
        updateAllRespawn(respawn->child);
    }
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
}**/