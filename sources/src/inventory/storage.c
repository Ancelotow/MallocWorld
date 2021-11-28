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
#include "../../header/global.h"

Storage *createStorage(int id, int quantity) {
    Storage *storage = malloc(sizeof(Storage));

    storage->id = id;
    storage->quantity = quantity;
    storage->next = NULL;
    return storage;
}

void DeleteStorage(Game* game){
    Storage * current = game->storage;
    Storage * parent = NULL;
    while(current != NULL){
        if(current->quantity <= 0){
            if(parent != NULL){
                parent->next = current->next;
                free(current);
                current = parent->next;
            } else {
                game->storage = game->storage->next;
                free(current);
                current = game->storage;
            }
        } else {
            parent = current;
            current = current->next;
        }
    }
}

void changeQuantityStorage(Storage* storage, int id, int quantity, Game* game) {
    Storage *n,*precedent;

    while(storage != NULL){
        if (storage->id == id){
            storage->quantity += quantity;
            break;
        }
        storage = storage->next;
    }

    if(storage->quantity <= 0){   //on cherche si c'est la 1ère valeur
        n = storage;
        storage = storage->next;
        free(n);
    }
    else{               // on boucle jusqu'a trouver la valeur
        precedent = storage;
        n = storage->next;
        while(n != NULL ){
           if (n->quantity <= 0){
                precedent->next = n->next;
                free(n);
                break;
            }
            precedent = n;
            n = n->next;
        }
    }
    DeleteStorage(game);
}

void stockInventory(Player* player, Game* game){
    char idStr[10];
    int quantity;
    int quantityTotal = 0;

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
        stockInventory(player, game);
    }
    do {
        printf("Quelle quantité veux tu stocker? \n");
        scanf("%d", &quantity);
        if (quantity > quantityTotal) {
            printf("Tu n'en a pas assez\n");
        }
    } while (quantity > quantityTotal);
    if (game->storage == NULL){
        game->storage = createStorage(id, quantity);
    } else{
        changeQuantityStorage(game->storage, id, quantity);
    }
}

void printStorage(Storage *storage) {
    printf("ID :%d, Quantite : %d\n", storage->id, storage->quantity);
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

