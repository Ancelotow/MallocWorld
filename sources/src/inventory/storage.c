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
    int idStr[10];
    int quantity;
    int quantityTotal = 0;
    Storage* ressource = NULL;

    printf("Quelles ressources souhaites-tu stocker? \n");
    scanf("%s", idStr);
    int id = atoi(idStr);
    for (int i = 0; i < player->sizeInventory; i++){
        if (player->inventory[i]->id == id){
            quantityTotal += player->inventory[i]->length;
        }
    }

    if (quantityTotal <= 0){
        printf("Tu n'a pas cette ressource\n");
        stockInventory(player);
    }

    do {
        printf("Quelle quantité veux tu stocker? \n");
        scanf("%d", &quantity);
        if (quantity > quantityTotal) {
            printf("Tu n'en a pas assez\n");
        }
    } while (quantity > quantityTotal);

    ressource = createStorage(id, quantity);
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

