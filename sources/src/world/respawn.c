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

void freeRespawn(Respawn* respawn){
        freePosition(respawn->position);
        free(respawn);
}


/*void recurrenceRespawn(Respawn respawn) {
    if (#un tour est passé){
        respawn.roundLeft--;
    }

    if(respawn.roundLeft == 0){
        createRespawn(respawn);
    }
}
*/



/*
 * La fréquence de réapparition des ressources dans une zone est de 10 tours. (10
actions de l’utilisateur sur la carte). Si le joueur se trouve sur la case à ce moment, la
ressource réapparaît au tour suivant
 */


/*
* La fréquence de réapparition des monstres dans une zone est de 15 tours. (15 actions
de l’utilisateur sur la carte). Si le joueur se trouve sur la case à ce moment, le monstre
réapparaît au tour suivant.
*/