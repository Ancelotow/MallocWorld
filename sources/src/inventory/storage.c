/*
**  Filename : stack.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage the PNJ's storage
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../header/inventory/storage.h"

Storage *createStorage(int id, int quantity) {
    Storage *storage = malloc(sizeof(Storage));

    storage->id = id;
    storage->quantity = quantity;
    storage->next = NULL;
    return storage;
}

void changeQuantityStorage(Storage* storage, int id, int quantity) {
    while(storage != NULL){
        if (storage->id == id){
            storage->quantity += quantity;
            break;
        }
        storage = storage->next;
    }
}

void printStorage(Storage *storage) {
    printf("ID :%d, Quantité : %d", storage->id, storage->quantity);
    if (storage->next != NULL) {
        printStorage(storage->next);
    }
}

void freeStorage(Storage *storage) {
    if(storage->next != NULL){
        freeStorage(storage->next);
    }
    free(storage);
}

