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

Respawn* createRespawn(int id, struct Position* position);

void appendRespawn(Respawn* respawn, int id, struct Position* position);

void printRespawn(Respawn* respawn);

void freeRespawn(Respawn* respawn);

#endif //MALLOCWORLD_RESPAWN_H
