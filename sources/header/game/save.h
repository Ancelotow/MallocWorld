/*
**  Filename : save.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for "save.c". Save the game into save file.
*/

#ifndef MALLOCWORLD_SAVE_H
#define MALLOCWORLD_SAVE_H

void saveGame(Game game);

void saveWorld(FILE* file, World world);

void savePlayer(FILE* file, Player player);

void savePlayerInventory(FILE* file, Player player);

void saveStorage(FILE* file, Storage* storage);

#endif //MALLOCWORLD_SAVE_H
