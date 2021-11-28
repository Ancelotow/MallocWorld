/*
**  Filename : position.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'position.c'. Manage the position of the player in the world (zone, row and column).
*/

#ifndef MALLOCWORLD_POSITION_H
#define MALLOCWORLD_POSITION_H

typedef struct World World;

typedef struct Position{
    int x;
    int y;
    int zone;
} Position;

/**
 * Créer une position depuis une position existante
 * @param posExisting La position existante
 * @return La position
 */
Position* createPositionFromExisting(Position posExisting);

/**
 * Récupération de la position du joueur sur la map
 * @param world Le monde (la map)
 * @return La position du joueur
 */
Position* seekPlayer(World world);

/**
 * Fonction de test pour afficher la position
 * @param position La position
 */
void printPosition(Position position);

/**
 * Libère la position de la mémoire
 * @param position La position
 */
void freePosition(Position* position);

#endif //MALLOCWORLD_POSITION_H
