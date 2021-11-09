/*
**  Filename : respawn.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'respawn.c'. Manage the respawn of monsters and resources with chained list
*/

#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

#include "zone.h"

typedef struct Respawn{
    TypeZone typeZone;
    int id;
    int row;
    int column;
    int roundLeft;
    struct Respawn* child;
} Respawn;

#endif //MALLOCWORLD_RESPAWN_H
