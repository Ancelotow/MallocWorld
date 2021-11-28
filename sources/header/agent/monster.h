/*
**  Filename : monsters.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'monsters.c'. Manage monsters.
*/

#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H

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
 * La création d'un monstre
 * @param id L'ID du monstre
 * @param name Le nom du monstre
 * @param breed La race du monstre
 * @param xp L'expérience que rapporte le monstre
 * @param damage Les dégâts qu'inflige le monstre
 * @param idInventory L'ID de l'inventaire que laisse tomber une fois battu
 * @param hp Les points de vies du monstre
 * @return Le monstre
 */
Monster* createMonster(int id, char* name, MonsterBreed breed, int xp, int damage, int idInventory, int hp);

/**
 * Récupération du nom de la race du monstre
 * @param race La race du monstre
 * @return Le nom de la race du monstre
 */
char* getMonsterRaceName(MonsterBreed breed);

/**
 * Affiche le monstre
 * @param monster Le monstre
 */
void printMonster(Monster monster);

/**
 * Libère le monstre de la mémoire
 * @param monster
 */
void freeMonster(Monster* monster);

/**
 * Récupération du monstre en fonction de l'ID depuis le CSV
 * @param id L'ID du monstre
 * @return Le monstre
 */
Monster* getMonsterFromId(int id);

#endif //MALLOCWORLD_MONSTER_H
