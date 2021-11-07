#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/world/world.h"
#include "header/inventory/inventory.h"
#include "header/monster.h"
#include "header/player.h"
#include "header/game.h"
#include "header/global.h"

void testPrintWorld(){
    World* world = generateWorld();
    printOriginalWorld(*world);
    freeWorld(world);
}

void testPrintInventory(int idInventory){
    Inventory* inv = getInventoryFromId(34);
    if(inv != NULL){
        printInventory(*inv);
        freeInventory(inv);
    }
}

void testPrintMonster(int idMonster){
    Monster* monster = getMonsterFromId(idMonster);
    if(monster != NULL){
        printMonster(*monster);
        freeMonster(monster);
    }
}

void testPrintPlayer(){
    Player* player = createPlayerLevel1();
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(1));
    printPlayerDebug(*player);
    freePlayer(player);
}

int main() {
    printTitle();
    runGame();
    return (0);
}


