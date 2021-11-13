/*
**  Filename : respawn.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'respawn.c'. Manage the respawn of monsters and resources with chained list
*/

#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

//Quand on tue monstre ou recup ressource pour qu'elle repop
typedef struct Respawn{
    int id;
    int roundLeft;
    //Position* position;
    struct Respawn* child;
} Respawn;

/*
Respawn* createRespawn(int id, Position* position); // doit retourner Respawn*

void appendRespawn(Respawn* respawn, int id, Position* position);

void updateAllRespawn(Respawn* respawn);

void printRespawn(Respawn* respawn); // Pour voir les infos dedans

void freeRespawn(Respawn* respawn);
**/

#endif //MALLOCWORLD_RESPAWN_H
