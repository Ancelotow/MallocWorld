/*
**  Filename : global.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'global.c'. Gather the functions which can be called anywhere
*/

#ifndef MALLOCWORLD_GLOBAL_H
#define MALLOCWORLD_GLOBAL_H

#include "world/position.h"
#include "game/game.h"
#include "game/save.h"
#include "agent/monster.h"
#include "agent/player.h"
#include "agent/pnj.h"
#include "action/fight.h"
#include "action/mining.h"
#include "action/moving.h"
#include "action/crafting.h"
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
#include <ctype.h>


/**
 * Permet de dupliquer une chaîne de charactère
 * @param string La chaîne de charactère à dupliquer
 * @return La chaîne de charactère dupliquer
 */
char* copyString(char* string);

/**
 * Affiche le titre du jeu : "Malloc World"
 */
void printTitle();

/**
 * Retourne un nombre aléatoire
 * @param min La valeur minimum du nombre aléatoir
 * @return Un nombre aléatoire
 */
int getRandomNumber(int min);

/**
 * Récupère la taille d'un fichier
 * @param file Le fihier
 * @return La taille d'un fichier
 */
int getFileLength(FILE* file);

/**
 * Affiche les actions possible en jeu
 */
void printAction();

/**
 * Affiche les actions que peux effectuer le PNJ
 */
void printActionPNJ();

/**
 * Affiche les actions possible en combat
 */
void printActionFight();

/**
 * Libère un tableau de 'int' en 2 dimensions
 * @param tab Tableau en 2 dimensions
 * @param row Nombre de lignes
 */
void freeTab2D(int** tab, int row);

#endif //MALLOCWORLD_GLOBAL_H
