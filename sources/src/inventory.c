#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/inventory.h"
#include "../header/global.h"


Inventory* createInventory(int id, char* name, int value, int durability, InventoryType type){
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->id = id;
    inventory->value = value;
    inventory->name = copyString(name);
    inventory->durability = durability;
    inventory->type = type;
    return inventory;
}

void printInventory(Inventory inventory){
    switch(inventory.type){
        case WEAPON:
            printf("Arme: %s,  %d dégâts, %d durabilite", inventory.name, inventory.value, inventory.durability);
            break;

        case ARMOR:
            printf("Armure: %s,  %d resistance", inventory.name, inventory.value);
            break;

        case TOOL:
            printf("Outil: %s,  %d durabilite", inventory.name, inventory.value);
            break;

        case CARE:
            printf("Soin: %s,  restaure %d HP", inventory.name, inventory.value);
            break;

        case RESOURCE:
            printf("Soin: %s, %d maximum", inventory.name, inventory.value);
            break;
    }
}

char* getInventoryTypeName(InventoryType type){
    switch(type){
        case WEAPON:
            return "Arme";

        case ARMOR:
            return "Armure";

        case TOOL:
            return "Outil";

        case CARE:
            return "Soin";

        case RESOURCE:
            return "Ressource de craft";

        default:
            return NULL;
    }
}

void freeInventory(Inventory* inventory){
    free(inventory->name);
    free(inventory);
}

/*Inventory** createAllInventory(){
    Inventory** listInventories = malloc(sizeof())
}*/