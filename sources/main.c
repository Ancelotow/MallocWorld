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

void testStorage(){
    World *world1 = generateWorld();
    Position* playerposition = seekPlayer(*world1);
    Storage *test = createStorage(10, 5);
    changeQuantityStorage(test, 10, 8);
    printStorage(test);
    changeQuantityStorage(test, 10, -13);
    printStorage(test);
}

void testRespawn(){
    Position* position = malloc(sizeof(Position));
    position->x = 1;
    position->y = 1;
    position->zone = 0;
    Respawn* respawn = createRespawn(1, position);
    appendRespawn(respawn, 2, position);
    appendRespawn(respawn, 3, position);
    appendRespawn(respawn, 4, position);
    appendRespawn(respawn, 5, position);
    appendRespawn(respawn, 6, position);
    appendRespawn(respawn, 7, position);
    appendRespawn(respawn, 8, position);
    for(int i = 0; i < 20; i++){
        updateAllRespawn(respawn);
    }
}

int main() {
    testRespawn();
    //printTitle();
    //runGame();
    return (0);
}


