//
// Created by Admin on 17/10/2021.
//

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
