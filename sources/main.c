#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/world.h"
#include "header/inventory.h"
#include "header/monster.h"

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

void testPrintMonster(int idInventory){
    Monster* monster = getMonsterFromId(idInventory);
    if(monster != NULL){
        printMonster(*monster);
        freeMonster(monster);
    }
}

int main() {
    testPrintMonster(40);
    return 0;
}


