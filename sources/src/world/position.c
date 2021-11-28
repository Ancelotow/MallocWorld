/*
**  Filename : position.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the player's position in the world (zone, row and column)
*/

#include "../../header/global.h"

/**
 * Créer une position depuis une position existante
 * @param posExisting La position existante
 * @return La position
 */
Position* createPositionFromExisting(Position posExisting){
    Position* position = malloc(sizeof(Position));
    position->x = posExisting.x;
    position->y = posExisting.y;
    position->zone = posExisting.zone;
    return position;
}

/**
 * Récupération de la position du joueur sur la map
 * @param world Le monde (la map)
 * @return La position du joueur
 */
Position* seekPlayer(World world){
    Position *position = malloc(sizeof(Position));
    position->x = -1;
    position->y = -1;
    for(int i=0; i < NB_ZONE; i++){
        for(int r=0; r < world.world[i]->row; r++){
            for(int c=0; c < world.world[i]->column; c++){
                if(world.world[i]->map[r][c] == 1){
                    position->x = c;
                    position->y = r;
                    position->zone = i;
                    break;
                }
            }
            if(position->x != -1){
                break;
            }
        }
        if(position->x != -1){
            break;
        }
    }
    return position;
}

/**
 * Fonction de test pour afficher la position
 * @param position La position
 */
void printPosition(Position position){
    printf("X : %d, Y : %d, ZONE : %d", position.x, position.y, position.zone);
}

/**
 * Libère la position de la mémoire
 * @param position La position
 */
void freePosition(Position* position){
    free(position);
}