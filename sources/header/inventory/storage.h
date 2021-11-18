/*
**  Filename : storage.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'storage.c'. It's used to manage the PNJ's storage
*/

#include "../player.h"

#ifndef MALLOCWORLD_STORAGE_H
#define MALLOCWORLD_STORAGE_H

typedef struct Storage{
    int id;
    int quantity;
    struct Storage* next;
} Storage;

Storage* createStorage(int id, int quantity);

void changeQuantityStorage(Storage* storage, int id, int quantity); //ajouter - enlever des ressources

int stockInventory(Player* player); // Demande quel inventaire stocker et la quantité

void printStorage(Storage* storage);

void freeStorage(Storage* storage);

#endif //MALLOCWORLD_STORAGE_H