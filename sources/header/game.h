//
// Created by Admin on 23/10/2021.
//

#ifndef MALLOCWORLD_GAME_H
#define MALLOCWORLD_GAME_H

#include "world.h"
#include "position.h"
#include "player.h"

typedef struct Game{
    World* world;
    Player* player;
    Position* position;
    Respawn* respawn;
} Game;

void runGame();

void createVoidGame();

void actionMove(char move, Position* position, World* world);

void moves(Position newPosition, Position* currentPos, World* world);

#endif //MALLOCWORLD_GAME_H
