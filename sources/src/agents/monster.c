/*
**  Filename : monster.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the monsters in the world
*/

#include "../../header/global.h"

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

/**
 * Affiche le monstre
 * @param monster Le monstre
 */
void printMonster(Monster monster){
    char* race = getMonsterRaceName(monster.breed);
    printf("%s : %s %dxp", race, monster.name, monster.xp);
}

/**
 * Récupération du nom de la race du monstre
 * @param race La race du monstre
 * @return Le nom de la race du monstre
 */
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

/**
 * Libère le monstre de la mémoire
 * @param monster
 */
void freeMonster(Monster* monster){
    free(monster->name);
    free(monster);
}

/**
 * Récupération du monstre en fonction de l'ID depuis le CSV
 * @param id L'ID du monstre
 * @return Le monstre
 */
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