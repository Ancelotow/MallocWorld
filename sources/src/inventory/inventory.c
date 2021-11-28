/*
**  Filename : inventory.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the inventory (tools, healths, armors, weapons and resources)
*/

#include "../../header/global.h"

/**
 * Création d'un inventaire
 * @param id L'ID
 * @param name Le nom
 * @param value La valeur (dégâts, sauvegarde de dégâts, nombre de HP restaurer)
 * @param durability La durabilité
 * @param maxStack L'empilation max
 * @param type Le type (Armure, Arme, Outil, Ressource, Potion)
 * @return L'inventaire créé
 */
Inventory* createInventory(int id, char* name, int value, float durability, int maxStack, InventoryType type){
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->id = id;
    inventory->value = value;
    inventory->name = copyString(name);
    switch(type){

        // Si c'est un soin ou une ressource, il n'y a pas de durabilité
        case CARE:
        case RESOURCE:
            inventory->durability = 0.00f;
            inventory->durabilityMax = 0.00f;
            inventory->maxStack = maxStack;
            break;

        // Si c'est un soin, une ressource ou un outil, l'empilement max est de 1
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

/**
 * Fonction de test pour afficher un inventaire
 * @param inventory L'inventaire
 */
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
 * Affiche un inventaire
 * @param inventory L'inventaire
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
 * Récupération du nom d'un type d'inventaire
 * @param type Le type d'inventaire
 * @return Le nom du type d'inventaire
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
 * Libère de la mémoire l'inventaire
 * @param inventory L'inventaire
 */
void freeInventory(Inventory* inventory){
    free(inventory->name);
    free(inventory);
}

/**
 * Récupération d'un inventaire depuis le CSV en fonction de l'ID
 * @param id L'ID de l'inventaire
 * @return L'inventaire
 */
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

