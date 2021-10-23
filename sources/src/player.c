#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/player.h"

const int MAX_INVENTORY = 20;

Player* createPlayer(int currentHp, int maxHp, Inventory** inventory, int sizeInventory, int level, int xp, int xpNext){
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
    Inventory** inventory = malloc(sizeof(Inventory*) * 20);
    inventory[0] = getInventoryFromId(1); // Epée en bois
    inventory[1] = getInventoryFromId(2); // Pioche en bois
    inventory[2] = getInventoryFromId(3); // Serpe en bois
    inventory[3] = getInventoryFromId(4); // Hache en bois
    Player* player = createPlayer(currentHp, maxHp, inventory, 4, 1, 0, 100);
    /*for(int i=0; i < 4; i++){
        freeInventory(inventory[0]);
    }
    free(inventory);*/
    return player;
}

void printPlayer(Player player){
    printf("Joueur : %d/%dHP, %d/%dxp, lvl%d\n", player.currentHp, player.maxHp, player.xp, player.xpNext, player.level);
    printf("\t -- INVENTAIRE --\n");
    for(int i=0; i < player.sizeInventory; i++){
        printf("\t");
        printInventory(*player.inventory[i]);
        printf("\n");
    }
}

void freePlayer(Player* player){
    for(int i=0; i < player->sizeInventory; i++){
        freeInventory(player->inventory[i]);
    }
    free(player->inventory);
    free(player);
}