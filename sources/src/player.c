/*
**  Filename : player.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the player in the game
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/player.h"
#include "../header/global.h"
#include "../header/action/mining.h"

const int MAX_INVENTORY = 20;

Player* createPlayer(int currentHp, int maxHp, Stack** inventory, int sizeInventory, int level, int xp, int xpNext){
    Player* player = malloc(sizeof(Player));
    player->currentHp = currentHp;
    player->maxHp = maxHp;
    player->inventory = inventory;
    player->sizeInventory = sizeInventory;
    player->level = level;
    player->xp = xp;
    player->xpNext = xpNext;
    return player;
}

Player* createPlayerLevel1(){
    int maxHp = 100;
    int currentHp = maxHp;
    Stack** stack = malloc(sizeof(Stack*) * 20);
    stack[0] = createStackWithInventory(getInventoryFromId(1)); // Epée en bois
    stack[1] = createStackWithInventory(getInventoryFromId(2)); // Pioche en bois
    stack[2] = createStackWithInventory(getInventoryFromId(3)); // Serpe en bois
    stack[3] = createStackWithInventory(getInventoryFromId(4)); // Hache en bois
    Player* player = createPlayer(currentHp, maxHp, stack, 4, 1, 0, 100);
    return player;
}

void appendInventory(Player* player, Inventory* inventory){
    Stack* stack;
    int stackVacant = 0;
    for(int i = 0; i < player->sizeInventory; i++){
        if(player->inventory[i]->id == inventory->id && player->inventory[i]->length < player->inventory[i]->maximum){
            stack = player->inventory[i];
            stackVacant = 1;
            break;
        }
    }
    if(stackVacant){
        appendStack(inventory, stack);
    } else if(player->sizeInventory < 20){
        stack = createStackWithInventory(inventory);
        player->inventory[player->sizeInventory] = stack;
        player->sizeInventory += 1;
    }
}

void printPlayerDebug(Player player){
    printf("Joueur : %d/%dHP, %d/%dxp, lvl%d\n", player.currentHp, player.maxHp, player.xp, player.xpNext, player.level);
    printf("\t -- INVENTAIRE --\n");
    for(int i=0; i < player.sizeInventory; i++){
        printf("\t");
        printStackDebug(*player.inventory[i]);
        printf("\n");
    }
}

void printInventoryPlayer(Player player, InventoryType type){
    printf("======================= INVENTAIRE =======================\n");
    Inventory* inventory = NULL;
    for(int i = 0; i < player.sizeInventory; i++){
        if(type == 0){
            printStack(*player.inventory[i]);
        } else {
           inventory = getInventoryFromId(player.inventory[i]->id);
           if(inventory->type == type){
               printStack(*player.inventory[i]);
           }
        }
    }
    if(inventory != NULL){
        freeInventory(inventory);
    }
    printf("==========================================================\n\n");
}

void freePlayer(Player* player){
    for(int i=0; i < player->sizeInventory; i++){
        freeStack(player->inventory[i]);
    }
    free(player->inventory);
    free(player);
}

void savePlayer(FILE* file, Player player){
    fputs("=== PLAYER ===\n", file);
    fprintf(file, "{%d}\n", player.level);
    fprintf(file, "{%d}/{%d}\n", player.xp, player.xpNext);
    fprintf(file, "{%d}/{%d}\n", player.currentHp, player.maxHp);
    fputs("-- INVENTORY --\n", file);
}

int useToolToMining(Element element, Player* player){
    float usury = getUsury(element);
    float newDurability;
    for(int i = 0; i < player->sizeInventory; i++){
        if(isIdTool(element, player->inventory[i]->id)){
            for(int j = 0; j < player->inventory[i]->length; j++){
                newDurability = player->inventory[i]->inventory[j]->durability - (usury * player->inventory[i]->inventory[j]->durabilityMax);
                if(newDurability > 0){
                    player->inventory[i]->inventory[j]->durability = newDurability;
                    return 1;
                }
            }
        }
    }
    return 0;
}
