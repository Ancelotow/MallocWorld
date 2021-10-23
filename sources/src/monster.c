#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/monster.h"
#include "../header/global.h"


Monster* createMonster(int id, char* name, MonsterBreed breed, int xp, int damage, int idInventory, int hp){
    Monster* monster = malloc(sizeof(Monster));
    monster->id = id;
    monster->breed = breed;
    monster->xp = xp;
    monster->hp = hp;
    monster->damage = damage;
    monster->idInventory = idInventory;
    monster->name = copyString(name);
    return monster;
}

void printMonster(Monster monster){
    char* race = getMonsterRaceName(monster.breed);
    printf("%s : %s %dxp", race, monster.name, monster.xp);
}

char* getMonsterRaceName(MonsterBreed race){
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

        case BALROG:
            return "Balrog";

        default:
            return NULL;
    }
}

void freeMonster(Monster* monster){
    free(monster->name);
    free(monster);
}

Monster* getMonsterFromId(int id){
    FILE* csv = fopen(FILENAME_MONSTERS, "r");
    if(csv != NULL){
        int length = getFileLength(csv);
        char inv[100];
        char *split;
        while(ftell(csv) < length){
            fgets(inv, 100, csv);
            split = strtok(inv, ";");
            if(atoi(split) == id){
                char *name = strtok(NULL, ";");
                int hp = atoi(strtok(NULL, ";"));
                int damage = atoi(strtok(NULL, ";"));
                int xp = atoi(strtok(NULL, ";"));
                MonsterBreed breed = atoi(strtok(NULL, ";"));
                int idInventory = atoi(strtok(NULL, ";"));
                fclose(csv);
                return createMonster(id, name, breed, xp, damage, idInventory, hp);
            }
        }
        fclose(csv);
        return NULL;
    } else{
        return NULL;
    }
}