/*
**  Filename : monsters.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'monsters.c'. Manage monsters.
*/

#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H

#include "inventory/inventory.h"
#define FILENAME_MONSTERS "../resources/monsters.csv"

typedef enum MonsterBreed{
    CREATURE = 1,
    ORC = 2,
    TROLL = 3,
    GOBLIN = 5,
    DARK_ELF = 6,
    UNDEAD = 7,
    DRAGON = 8,
    BALROG = 9
} MonsterBreed;

typedef struct Monster{
    int id;
    char* name;
    MonsterBreed breed;
    int xp;
    int damage;
    int idInventory;
    int hp;
} Monster;

/**
 * Created a monster
 * @param id Monster's id
 * @param name Monsters's name
 * @param race Monster's race (ex: Goblin, Dark Elf, Orc, ...)
 * @param xp Monster's experience gain
 * @param damage Monster's damage
 * @param idInventory Monster's object when he's defeated
 * @return A monster
 */
Monster* createMonster(int id, char* name, MonsterBreed breed, int xp, int damage, int idInventory, int hp);

/**
 * Get name of a monster race
 * @param race Race monster
 * @return Name of a monster race
 */
char* getMonsterRaceName(MonsterBreed breed);

/**
 * Printed into the console the information about a monster
 * @param monster Monster
 */
void printMonster(Monster monster);

/**
 * Free monster (including name and object) from memory
 * @param monster
 */
void freeMonster(Monster* monster);

Monster* getMonsterFromId(int id);

#endif //MALLOCWORLD_MONSTER_H
