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

int stockInventory(Player* player){
    Stack **inventory;
    int quantity;
    int isExist = 0;

    printf("Quelles ressources souhaites-tu stocker? \n");
    scanf("%s", &inventory);
    for(int i = 0; i < player->sizeInventory; i++){
        for(int j = 0; j < player->inventory[i]->length; j++){
            if (inventory == player->inventory[i]){
                isExist = 1;
                break;
            }
        }
        if(isExist){
            break;
        }
    }
    if (!isExist){
        printf("Tu n'a pas cette ressource \n");
        stockInventory(player);
    }




    printf("Quel quantité veut tu stocker? \n");
    scanf("%d", &quantity);
    if (quantity > player->sizeInventory) {
        printf("Tu n'en a pas assez \n");
        stockInventory(player);
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

