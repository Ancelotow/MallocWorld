//
// Created by Admin on 23/10/2021.
//

#ifndef MALLOCWORLD_GAME_H
#define MALLOCWORLD_GAME_H

#include "world.h"
#include "position.h"

void runGame();

void createVoidPartie();

void actionMove(char move, Position* position, World* world);

#endif //MALLOCWORLD_GAME_H
