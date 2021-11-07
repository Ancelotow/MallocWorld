//
// Created by Admin on 23/10/2021.
//

#ifndef MALLOCWORLD_GAME_H
#define MALLOCWORLD_GAME_H

#include "world/world.h"
#include "position.h"
#include "player.h"
#include "inventory/storage.h"

typedef struct Game{
    World* world;
    Player* player;
    Position* position;
    Respawn* respawn;
    Storage* storage;
} Game;

void runGame();

Game* createVoidGame();

void play(Game* game);

void actionMove(char move, Position* position, World* world);

void moves(Position newPosition, Position* currentPos, World* world);

void freeGame(Game* game);

void saveGame(Game game);

#endif //MALLOCWORLD_GAME_H
