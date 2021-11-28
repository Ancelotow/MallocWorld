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

/**
 * Création d'un stockage
 * @param id L'ID de l'inventaire
 * @param quantity La quantité
 * @return Le stockage
 */
Storage* createStorage(int id, int quantity) {
    Storage *storage = malloc(sizeof(Storage));
    storage->id = id;
    storage->quantity = quantity;
    storage->next = NULL;
    return storage;
}

/**
 * Ajoute un stockage dans la liste chaînée des stockage
 * @param game Le jeu
 * @param newStorage Le stockage
 */
void appendStorage(Game* game, Storage* newStorage) {
    if(game->storage == NULL){
        game->storage = newStorage;
    } else {
        Storage *current = game->storage;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStorage;
    }
}

/**
 * Récupération d'inventaires depuis le stockage
 * @param game Le jeu
 * @param id L'ID de l'inventaire à récupérer
 * @param quantity La quantité à récupérer
 */
void retrieveFromStorage(Game *game, int id, int quantity) {
    Storage *current = game->storage;
    Storage *parent = NULL;
    while (current != NULL) {
        if (current->id == id) {
            for (int i = 0; i < quantity; i++) {
                Inventory *inventory = getInventoryFromId(id);
                appendInventory(game->player, inventory);
                current->quantity -= 1;
                if (current->quantity <= 0) {
                    break;
                }
            }
        }
        if (current->quantity <= 0) {
            if (parent != NULL) {
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

/**
 * Stocke un inventaire dans le stockage
 * @param game Le jeu
 * @param id L'ID de l'inventaire à stocker
 * @param quantity La quantité à stocker
 */
void storeIntoStorage(Game *game, int id, int quantity) {
    int length = getQuantityInventory(*game->player, id);
    if (length < quantity) {
        printMessage("Vous n'en avez pas assez.");
    } else {
        Storage *current = game->storage;
        int isAdded = 0;
        while (current != NULL) {
            if(current->id == id){
                current->quantity += quantity;
                isAdded = 1;
            }
            current = current->next;
        }
        if(!isAdded){
            appendStorage(game, createStorage(id, quantity));
        }
        removeQuantityInventory(game->player, id, quantity);
    }
}

/**
 * Affiche le Storage
 * @param storage
 */
void printStorage(Storage *storage) {
    Storage *current = storage;
    Inventory *inv;
    printf("=================== COFFRE ===================\n");
    while (current != NULL) {
        inv = getInventoryFromId(current->id);
        printf("|| %d : %s (x%d) \n", current->id, inv->name, current->quantity);
        freeInventory(inv);
        current = current->next;
    }
    printf("==============================================\n\n");
}

/**
 * Libère la mémoire du stockage
 * @param storage Le stockage
 */
void freeStorage(Storage *storage) {
    if (storage->next != NULL) {
        freeStorage(storage->next);
    }
    free(storage);
}

