/*
**  Filename : respawn.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage the respawn of resources and monsters when player kill monster or mine a resource.
*/

#include "../../header/global.h"

/**
 * Fonction qui créer un Respawn pour repop les ressources ou monstres
 * @param id de la ressource ou du montre
 * @param position de celui ci
 * @return
 */
Respawn *createRespawn(int id, Position *position) {
    Respawn *respawn = malloc(sizeof(Respawn));
    int roundLeft;
    if (id >= 3 && id <= 11) {
        roundLeft = 10;
    } else if(id < 0){
        roundLeft = 1;
    } else {
        roundLeft = 15;
    }
    respawn->roundLeft = roundLeft;
    respawn->id = id;
    respawn->position = position;
    respawn->child = NULL;
    return respawn;
}

/**
 * Enleve un tour pour chaque ressources ou monstres qui doit repop et réapparation de ceux ci si le nombre de tour est fini
 * @param game
 */
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

/**
 * Ajoute une ressource ou un montre qui devront réapparaitre
 * @param respawn Tableau de respawn
 * @param id de la ressource ou du monstre
 * @param position de celui ci
 */
void appendRespawn(Respawn* respawn, int id, Position* position) {
    if(respawn != NULL){
        while(respawn->child != NULL){
            respawn = respawn->child;
        }
        respawn->child = createRespawn(id, position);
    }
}

/**
 * Affiche les ressources et monstres qui doivent repop avec leur tour restant
 * @param respawn Tableau de Respawn
 */
void printRespawn(Respawn *respawn) {
    if(respawn != NULL){
        printf("ID :%d, Tour restant : %d (", respawn->id, respawn->roundLeft);
        printPosition(*respawn->position);
        printf(")\n");
        printRespawn(respawn->child);
    }
}

/**
 * Libére Respawn
 * @param respawn Tableau de Respawn
 */
void freeRespawn(Respawn *respawn) {
    if(respawn != NULL){
        freePosition(respawn->position);
        freeRespawn(respawn->child);
        free(respawn);
    }
}