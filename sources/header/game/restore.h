/*
**  Filename : restore.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for "restore.c". Restore the game from save file.
*/


#ifndef MALLOCWORLD_RESTORE_H
#define MALLOCWORLD_RESTORE_H

typedef struct Game Game;
typedef struct World World;
typedef struct Player Player;

Game* restoreGame(char* path);

void restoreMap(Game* game);

void restoreZone(World* world);

void restorePlayer(Game* game);

void restoreInventory(Player* player);

void restoreStorage(Game* Game);

#endif //MALLOCWORLD_RESTORE_H
