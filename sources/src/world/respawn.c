/*
**  Filename : respawn.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage the respawn of resources and monsters when player kill monster or mine a resource.
*/

#include "../../header/global.h"

/**
 * Création d'un respawn
 * @param id L'id de l'élement (monstre, ressource, portail)
 * @param position La position de l'élément sur la map
 * @return Le respawn créé
 */
Respawn* createRespawn(int id, Position *position) {
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
 * Modifie tout les respawn dans la liste chaîné en diminuer le "Tours restants" (roundLeft) de 1.
 * Si "Tours restants" est à 0, on remet l'élément sur la map et on le supprime de la liste chaînée
 * @param game Le jeu
 */
void updateAllRespawn(Game *game) {
    Respawn* current = game->respawn;
    Respawn* parent = NULL;
    Position* pos;
    while(current != NULL){
        current->roundLeft -= 1;
        if(current->roundLeft <= 0){
            pos = current->position;
            game->world->world[pos->zone]->map[pos->y][pos->x] = current->id; // fait réapparaitres les montres et ressources
            freePosition(current->position);  // met l'ID à la poisition x et y
            if(parent != NULL){
                parent->child = current->child;
                free(current);
                current = parent->child;
            } else {  // concerne uniquement le premier de la liste car pas de parents
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
 * Ajoute un respwan à la liste chaînée
 * @param respawn La liste chaînée de respawn
 * @param id L'id de l'élement à ajouter dans la liste
 * @param position La position de l'élément
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
 * Fonction de test pour afficher tout les respawn
 * @param respawn La liste chaînée de respawn
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
 * Libère les respawn de la mémoire
 * @param respawn La liste chaînée de respawn
 */
void freeRespawn(Respawn *respawn) {
    if(respawn != NULL){
        freePosition(respawn->position);
        freeRespawn(respawn->child);
        free(respawn);
    }
}