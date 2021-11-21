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
typedef enum TypeZone TypeZone;

Game* restoreGame(char* path);

void restoreMap(FILE* file, Game* game, int length);

int isEndZoneIntoSaveFile(char* string);

void restoreZone(FILE* file, World* world, int length, TypeZone typeZone);

void restorePlayer(FILE* file, Game* game);

void restoreInventory(FILE* file, Player* player);

void restoreStorage(FILE* file, Game* Game);

#endif //MALLOCWORLD_RESTORE_H
