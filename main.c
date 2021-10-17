#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/world.h"

int main() {
    World* world = generateWorld();
    printOriginalWorld(*world);
    freeWorld(world);
    char str[100];
    scanf("Appuyez sur \"Entrée\" pour terminer... %s", str);
    return 0;
}
