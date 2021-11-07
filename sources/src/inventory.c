#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/inventory.h"
#include "../header/global.h"

Inventory* createInventory(int id, char* name, int value, int durability, int maxStack, InventoryType type){
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->id = id;
    inventory->value = value;
    inventory->name = copyString(name);
    inventory->durability = durability;
    inventory->maxStack = maxStack;
    inventory->type = type;
    return inventory;
}

void printInventory(Inventory inventory){
    printf("\t -");
    switch(inventory.type){
        case WEAPON:
            printf("Arme: %s,  %d degats, %d durabilite", inventory.name, inventory.value, inventory.durability);
            break;

        case ARMOR:
            printf("Armure: %s,  %d resistance", inventory.name, inventory.value);
            break;

        case TOOL:
            printf("Outil: %s,  %d durabilite", inventory.name, inventory.durability);
            break;

        case CARE:
            printf("Soin: %s,  restaure %d HP", inventory.name, inventory.value);
            break;

        case RESOURCE:
            printf("Ressource: %s, %d maximum", inventory.name, inventory.value);
            break;
    }
    printf("\n");
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

Inventory* getInventoryFromId(int id){
    FILE* csv = fopen(FILENAME_INVENTORIES, "r");
    if(csv != NULL){
        int length = getFileLength(csv);
        char inv[100];
        char *split;
        while(ftell(csv) < length){
            fgets(inv, 100, csv);
            split = strtok(inv, ";");
            if(atoi(split) == id){
                char *name = strtok(NULL, ";");
                int value = atoi(strtok(NULL, ";"));
                int durability = atoi(strtok(NULL, ";"));
                int maxStack = atoi(strtok(NULL, ";"));
                InventoryType type = atoi(strtok(NULL, ";"));
                fclose(csv);
                return createInventory(id, name, value, durability, maxStack, type);
            }
        }
        fclose(csv);
        return NULL;
    } else{
        return NULL;
    }
}