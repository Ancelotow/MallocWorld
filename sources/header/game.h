/*
**  Filename : game.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'game.c'. Manage interactions between player/game and the printing.
*/

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

void actionMove(char move, Game* game);

void moves(Position newPosition, Game* game);

void freeGame(Game* game);

void saveGame(Game game);

#endif //MALLOCWORLD_GAME_H
