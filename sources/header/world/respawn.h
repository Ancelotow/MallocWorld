#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

#include "zone.h"


//Quand on tue monstre ou recup ressource pour qu'elle repop
typedef struct Respawn{
    TypeZone typeZone;
    int id;
    int row;
    int column;
    int roundLeft;
    struct Respawn* child;
} Respawn;


Respawn* createRespawn(int id); // doit retourner Respawn*

void recurrenceRespawn(Respawn respawn);

void freeRespawn(Respawn* respawn);

#endif //MALLOCWORLD_RESPAWN_H
