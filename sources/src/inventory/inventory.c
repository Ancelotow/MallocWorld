#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/inventory/inventory.h"
#include "../../header/global.h"
#include "../../header/world/zone.h"

Inventory* createInventory(int id, char* name, int value, float durability, int maxStack, InventoryType type){
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->id = id;
    inventory->value = value;
    inventory->name = copyString(name);
    inventory->durability = durability;
    inventory->durabilityMax = durability;
    inventory->maxStack = maxStack;
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

void printInventory(Inventory inventory){
    printf("||\t -");
    switch(inventory.type){
        case WEAPON:
            printf("%d degats, %0.2f durabilite\t\t\t||\n",inventory.value, inventory.durability);
            break;

        case ARMOR:
            printf("%d resistance\t\t\t\t\t||\n", inventory.value);
            break;

        case TOOL:
            printf("%0.2f durabilite\t\t\t\t\t||\n", inventory.durability);
            break;

        case CARE:
            printf("restaure %d HP\t\t\t\t\t||\n", inventory.value);
            break;

        case RESOURCE:
            printf("%d maximum\t\t\t\t\t||\n", inventory.maxStack);
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

int isIdTool_Plant(Element element, int id){
    switch (element) {
        case PLANT_ZONE_1:
            if(id == 3 || id == 13 || id == 24){
                return 1;
            } else{
                return 0;
            }

        case PLANT_ZONE_2:
            if(id == 13 || id == 24){
                return 1;
            } else{
                return 0;
            }

        case PLANT_ZONE_3:
            if(id == 24){
                return 1;
            } else{
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool_Rock(Element element, int id){
    switch (element) {
        case ROCK_ZONE_1:
            if(id == 2 || id == 12 || id == 23){
                return 1;
            } else{
                return 0;
            }

        case ROCK_ZONE_2:
            if(id == 12 || id == 23){
                return 1;
            } else{
                return 0;
            }

        case ROCK_ZONE_3:
            if(id == 23){
                return 1;
            } else{
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool_Wood(Element element, int id){
    switch (element) {
        case WOOD_ZONE_1:
            if(id == 4 || id == 14 || id == 25){
                return 1;
            } else{
                return 0;
            }

        case WOOD_ZONE_2:
            if(id == 14 || id == 25){
                return 1;
            } else{
                return 0;
            }

        case WOOD_ZONE_3:
            if(id == 25){
                return 1;
            } else{
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool(Element element, int id){
    switch (element) {
        case PLANT_ZONE_1:
        case PLANT_ZONE_2:
        case PLANT_ZONE_3:
            return isIdTool_Plant(element, id);

        case WOOD_ZONE_1:
        case WOOD_ZONE_2:
        case WOOD_ZONE_3:
            return isIdTool_Wood(element, id);

        case ROCK_ZONE_1:
        case ROCK_ZONE_2:
        case ROCK_ZONE_3:
            return isIdTool_Rock(element, id);

        default:
            return 0;
    }
}

float getUsury(Element element){
    switch (element) {
        case PLANT_ZONE_1:
        case WOOD_ZONE_1:
        case ROCK_ZONE_1:
            return 0.10f;

        case PLANT_ZONE_2:
        case WOOD_ZONE_2:
        case ROCK_ZONE_2:
            return 0.20f;

        case PLANT_ZONE_3:
        case WOOD_ZONE_3:
        case ROCK_ZONE_3:
            return 0.40f;

        default:
            return 0.00f;
    }
}