/*
**  Filename : storage.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'storage.c'. It's used to manage the PNJ's storage
*/

#ifndef MALLOCWORLD_STORAGE_H
#define MALLOCWORLD_STORAGE_H

typedef struct Game Game;
typedef struct Player Player;

typedef struct Storage{
    int id;
    int quantity;
    struct Storage* next;
} Storage;

Storage* createStorage(int id, int quantity);

void retrieveFromStorage(Game* game, int id, int quantity);

void storeIntoStorage(Game *game, int id, int quantity);

void appendStorage(Game* game, Storage* newStorage);

void printStorage(Storage* storage);

void freeStorage(Storage* storage);

#endif //MALLOCWORLD_STORAGE_H