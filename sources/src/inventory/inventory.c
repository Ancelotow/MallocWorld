/*
**  Filename : inventory.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the inventory (tools, healths, armors, weapons and resources)
*/

#include "../../header/global.h"

/**
 * Fonction qui créer un inventaire
 * @param id de la ressource
 * @param name
 * @param value
 * @param durability si c'est une arme ou si c'est une ressource = 1
 * @param maxStack
 * @param type
 * @return
 */
Inventory* createInventory(int id, char* name, int value, float durability, int maxStack, InventoryType type){
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->id = id;
    inventory->value = value;
    inventory->name = copyString(name);
    switch(type){
        case CARE:
        case RESOURCE:
            inventory->durability = 0.00f;
            inventory->durabilityMax = 0.00f;
            inventory->maxStack = maxStack;
            break;

        default:
        case ARMOR:
        case WEAPON:
        case TOOL:
            inventory->durability = durability;
            inventory->durabilityMax = durability;
            inventory->maxStack = 1;
            break;
    }
    inventory->type = type;
    return inventory;
}

void printInventoryDebug(Inventory inventory){
    printf("\t -");
    switch(inventory.type){
        case WEAPON:
            printf("Arme: %s,  %d degats, %0.2f durabilite", inventory.name, inventory.value, inventory.durability);
            break;

        case ARMOR:
            printf("Armure: %s,  %d resistance", inventory.name, inventory.value);
            break;

        case TOOL:
            printf("Outil: %s,  %0.2f durabilite", inventory.name, inventory.durability);
            break;

        case CARE:
            printf("Soin: %s,  restaure %d HP", inventory.name, inventory.value);
            break;

        case RESOURCE:
            printf("Ressource: %s, %d maximum", inventory.name, inventory.maxStack);
            break;
    }
    printf("\n");
}

/**
 * Affiche l'inventaire
 * @param inventory
 */
void printInventory(Inventory inventory){
    printf("||\t -");
    switch(inventory.type){
        case WEAPON:
            printf("%d degats, %0.2f durabilite\n",inventory.value, inventory.durability);
            break;

        case ARMOR:
            printf("%d resistance\n", inventory.value);
            break;

        case TOOL:
            printf("%0.2f durabilite\n", inventory.durability);
            break;

        case CARE:
            printf("restaure %d HP\n", inventory.value);
            break;

        case RESOURCE:
            printf("%d maximum\n", inventory.maxStack);
            break;
    }
}

/**
 * Fonction qui permet de récupérer les ressources de l'inventaire en fonction du type
 * @param type
 * @return
 */
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

/**
 * Libère le tableau d'inventaire
 * @param inventory
 */
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
                float durability = (float) atoi(strtok(NULL, ";"));
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

