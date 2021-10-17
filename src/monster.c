#include "../header/monster.h"
#include "../header/global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Monster* createMonster(int id, char* name, MonsterRace race, int xp, int damage, Inventory object, int hp){
    Monster* monster = malloc(sizeof(Monster));
    monster->id = id;
    monster->race = race;
    monster->xp = xp;
    monster->hp = hp;
    monster->damage = damage;
    monster->object = createInventory(object.id, object.name, object.value, object.durability, object.type);
    monster->name = copyString(name);
    return monster;
}

void printMonster(Monster monster){
    char* race = getMonsterRaceName(monster.race);
    printf("%s : %s %dxp", race, monster.name, monster.xp);
}

char* getMonsterRaceName(MonsterRace race){
    switch(race){
        case CREATURE:
            return "Creature";

        case ORC:
            return "Orque";

        case TROLL:
            return "Troll";

        case GOBLIN:
            return "Goblin";

        case DARK_ELF:
            return "Elfe noir";

        case UNDEAD:
            return "Mort-vivant";

        case DRAGON:
            return "Dragon";

        default:
            return NULL;
    }
}

void freeMonster(Monster* monster){
    freeInventory(monster->object);
    free(monster->name);
    free(monster);
}