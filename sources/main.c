#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/world.h"
#include "header/inventory.h"

void testPrintWorld(){
    World* world = generateWorld();
    printOriginalWorld(*world);
    freeWorld(world);
    char str[100];
    scanf("Appuyez sur \"Entrée\" pour terminer... %s", str);
}

int main() {
    Inventory* inv = getInventoryFromId(3);
    char str[100];
    if(inv == NULL){
        scanf("Appuyez sur \"Entrée\" pour terminer (not exsists)... %s", str);

        return 0;
    }
    printInventory(*inv);
    freeInventory(inv);
    scanf("Appuyez sur \"Entrée\" pour terminer... %s", str);
    return 0;
}


