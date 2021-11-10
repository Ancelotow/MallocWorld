#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

#include "zone.h"
#include"../position.h"

//Quand on tue monstre ou recup ressource pour qu'elle repop
typedef struct Respawn{
    int id;
    int roundLeft;
    Position* position;
    struct Respawn* child;
} Respawn;


Respawn* createRespawn(int id, Position* position); // doit retourner Respawn*

void recurrenceRespawn(Respawn respawn);

void freeRespawn(Respawn* respawn);

#endif //MALLOCWORLD_RESPAWN_H
