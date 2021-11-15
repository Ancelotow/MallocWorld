/*
**  Filename : global.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'global.c'. Gather the functions which can be called anywhere
*/

#ifndef MALLOCWORLD_GLOBAL_H
#define MALLOCWORLD_GLOBAL_H

#include <stdio.h>
#include "position.h"
#include "game.h"
#include "monster.h"
#include "player.h"
#include "action/fight.h"
#include "action/mining.h"
#include "inventory/inventory.h"
#include "inventory/stack.h"
#include "inventory/storage.h"
#include "world/world.h"
#include "world/zone.h"
#include "world/respawn.h"
#include "world/map/forest.h"
#include "world/map/village.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
 * Created a copy of string. It's used to initialize new string
 * @param string Source string
 * @return The string's copy
 */
char* copyString(char* string);

/**
 * Printed the game's title
 */
void printTitle();

/**
 * Get a random number
 * @param min Minimum value
 * @return Random number
 */
int getRandomNumber(int min);

/**
 * Get file length
 * @param file The file
 * @return File length
 */
int getFileLength(FILE* file);

void printAction();


#endif //MALLOCWORLD_GLOBAL_H
