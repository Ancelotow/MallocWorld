/*
**  Filename : respawn.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage the respawn of resources and monsters when player kill monster or mine a resource.
*/

#include "../../header/global.h"


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

void updateAllRespawn(Game *game) {
    Respawn* current = game->respawn;
    Respawn* parent = NULL;
    Position* pos;
    while(current != NULL){
        current->roundLeft -= 1;
        if(current->roundLeft <= 0){
            pos = current->position;
            game->world->world[pos->zone]->map[pos->y][pos->x] = current->id;  //fait réapparaitres les montres et ressources
            freePosition(current->position);                                        //met l'ID à la poisition x et y
            if(parent != NULL){
                parent->child = current->child;
                free(current);
                current = parent->child;
            } else {  //concerne uniquement le premier de la liste car pas de parents
                game->respawn = game->respawn->child;
                free(current);
                current = game->respawn;
            }
        } else {
            parent = current;
            current = current->child;
        }
    }

}

void appendRespawn(Respawn* respawn, int id, Position* position) {
    if(respawn != NULL){
        while(respawn->child != NULL){
            respawn = respawn->child;
        }
        respawn->child = createRespawn(id, position);
    }
}

void printRespawn(Respawn *respawn) {
    if(respawn != NULL){
        printf("ID :%d, Tour restant : %d (", respawn->id, respawn->roundLeft);
        printPosition(*respawn->position);
        printf(")\n");
        printRespawn(respawn->child);
    }
}

void freeRespawn(Respawn *respawn) {
    if(respawn != NULL){
        freePosition(respawn->position);
        freeRespawn(respawn->child);
        free(respawn);
    }
}