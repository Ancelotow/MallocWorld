/*
**  Filename : respawn.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'respawn.c'. Manage the respawn of monsters and resources with chained list
*/

#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

typedef struct Position Position;

typedef struct Respawn{
    int id;
    int roundLeft;
    struct Position* position;
    struct Respawn* child;
} Respawn;

/**
 * Création d'un respawn
 * @param id L'id de l'élement (monstre, ressource, portail)
 * @param position La position de l'élément sur la map
 * @return Le respawn créé
 */
Respawn* createRespawn(int id, struct Position* position);

/**
 * Ajoute un respwan à la liste chaînée
 * @param respawn La liste chaînée de respawn
 * @param id L'id de l'élement à ajouter dans la liste
 * @param position La position de l'élément
 */
void appendRespawn(Respawn* respawn, int id, struct Position* position);

/**
 * Modifie tout les respawn dans la liste chaîné en diminuer le "Tours restants" (roundLeft) de 1.
 * Si "Tours restants" est à 0, on remet l'élément sur la map et on le supprime de la liste chaînée
 * @param game Le jeu
 */
void updateAllRespawn(Game* game);

/**
 *
 * @param game Le jeu
 */
void respawnAllElement(Game *game);

/**
 * Fonction de test pour afficher tout les respawn
 * @param respawn La liste chaînée de respawn
 */
void printRespawn(Respawn* respawn);

/**
 * Libère les respawn de la mémoire
 * @param respawn La liste chaînée de respawn
 */
void freeRespawn(Respawn* respawn);

#endif //MALLOCWORLD_RESPAWN_H
