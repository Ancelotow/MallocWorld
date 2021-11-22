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

Respawn *createRespawn(int id, Position *position) {
    Respawn *respawn = malloc(sizeof(Respawn));
    int roundLeft;
    if (id >= 3 && id <= 11) {
        roundLeft = 10;
    } else {
        roundLeft = 15;
    }
    respawn->roundLeft = roundLeft;
    respawn->id = id;
    respawn->position = position;
    respawn->child = NULL;
    return respawn;
}

void appendRespawn(Respawn* respawn, int id, Position* position) {
    if(respawn != NULL){
        while(respawn->child != NULL){
            respawn = respawn->child;
        }
        respawn->child = createRespawn(id, position);
    }
}

void updateAllRespawn(Respawn *respawn) {
    Respawn *n,*precedent;

    respawn->roundLeft--;
    if (respawn->roundLeft <= 0) {   //on cherche si c'est la 1ère valeur
        n = respawn;
        respawn = respawn->child;
        free(n);
    } else {               // on boucle jusqu'a trouver la valeur
        precedent = respawn;
        n = respawn->child;
        while (n != NULL) {
            if (respawn->roundLeft <= 0) {
                precedent->child = n->child;
                free(n);
                break;
            }
            precedent = n;
            n = n->child;
        }
    }
}

void printRespawn(Respawn *respawn) {
    printPosition(*respawn->position);
    printf("ID :%d, Tour restant : %d (", respawn->id, respawn->roundLeft);
    printPosition(*respawn->position);
    printf(")\n");
    if (respawn->child != NULL) {
        printRespawn(respawn->child);
    }
}

void freeRespawn(Respawn *respawn) {
    freePosition(respawn->position);
    if(respawn->child != NULL){
        freeRespawn(respawn->child);
    }
    free(respawn);
}
