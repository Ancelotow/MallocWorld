#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/player.h"

const int MAX_INVENTORY = 20;

Player* createPlayer(int currentHp, int maxHp, Inventory** inventory, int level, int xp, int xpNext){
    Player* player = malloc(sizeof(Player));
    player->currentHp = currentHp;
    player->maxHp = maxHp;
    player->inventory = inventory;
    player->level = level;
    player->xp = xp;
    player->xpNext = xpNext;
    return player;
}

Player* createPlayerLevel1(){
    int maxHp = 100;
    int currentHp = maxHp;

}