/*
**  Filename : fight.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the fight's action when player meet a monster
*/

#include "../../header/global.h"

#define CMD_FIGHT_ATTACK 'a'
#define CMD_FIGHT_ESCAPE 'e'
#define CMD_FIGHT_HEALTH 'h'
#define CMD_FIGHT_WEAPON 'w'


Inventory* choiceWeapon(Player* player){
    char strId[10];
    printf("Liste de vos armes :\n");
    printInventoryPlayer(*player, WEAPON);
    printf("Choississez une arme en saisissant l'ID : ");
    scanf("%s", strId);
    printf("\n\n");
    int id = atoi(strId);
    for(int i = 0; i < player->sizeInventory; i++){
        if(player->inventory[i]->id == id && player->inventory[i]->length > 0){
            return player->inventory[i]->inventory[0];
        }
    }
    return NULL;
}

Inventory* choiceArmor(Player* player){
    int nbArmor = getLengthInventoryType(*player, ARMOR);
    if(nbArmor > 0){
        char strId[10];
        printf("Liste de vos armures :\n");
        printInventoryPlayer(*player, ARMOR);
        printf("Choississez une armure en saisissant l'ID : ");
        scanf("%s", strId);
        printf("\n\n");
        int id = atoi(strId);
        for(int i = 0; i < player->sizeInventory; i++){
            if(player->inventory[i]->id == id && player->inventory[i]->length > 0){
                return player->inventory[i]->inventory[0];
            }
        }
    }
    return NULL;
}

void printFight(Monster monster, Player player, Inventory weapon){
    printf("======= JOUEUR : LVL %d =======\n", player.level);
    printf("Vie : %d / %d\n", player.currentHp, player.maxHp);
    printf("Arme : %s ; durabilite %0.2f\n\n", weapon.name, weapon.durability);
    printf("======= ENNEMI : %s =======\n", monster.name);
    printf("Vie : %d \n\n", monster.hp);
}

int attack(Monster* monster, Player* player, Inventory* weapon){
    int monsterIsDead = 0;
    printFight(*monster, *player, *weapon);
    if(weapon->durability > 0){
        monster->hp -= weapon->value;
        weapon->durability -= 1;
    } else {
        printMessage("Votre arme est cassee !");
    }
    if(monster->hp <= 0){
        monster->hp = 0;
        monsterIsDead = 1;
    }
    return monsterIsDead;
}

int tryToEscape(){
    int random = getRandomNumber(0) % 3;
    if(random == 0){
        printMessage("Vous avez fui !");
        return 1;
    } else {
        printMessage("Fuite echouee...");
        return 0;
    }
}

int actionFight(char action, Monster* monster, Game* game, Inventory* weapon, Inventory* armor){
    int isOver = 0;
    switch (action) {
        case CMD_FIGHT_ATTACK:
            isOver = attack(monster, game->player, weapon);
            break;

        case CMD_FIGHT_ESCAPE:
            isOver = tryToEscape();
            break;

        case CMD_FIGHT_HEALTH:
            // TODO: Action health
            break;

        case CMD_FIGHT_WEAPON:
            weapon = choiceWeapon(game->player);
            break;

        default:
            printf("\nAction inconnue !\n");
            break;
    }
    return isOver;
}

void sufferDamage(Monster* monster, Player* player, Inventory* armor){
    int protection = 0;
    if(armor != NULL){
        protection = armor->value;
        armor->durability -= 1;
    }
    int damage = monster->damage - protection;
    if(damage > 0){
        player->currentHp -= damage;
        if(player->currentHp <= 0){
            printMessage("Vous etes mort...");
        }
    }
}

void startFight(int id, Game* game){
    Inventory* weapon = choiceWeapon(game->player);
    Inventory* armor = choiceArmor(game->player);
    Monster* monster = getMonsterFromId(id);
    int isFinished = 0;
    char action;
    do {
        printActionFight();
        printf("Quel action souhaitez-vous faire : ");
        scanf("%c", &action);
        scanf("%c", &action);
        printf("\n");
        isFinished = actionFight(action, monster, game, weapon, armor);
        if(!isFinished){
            sufferDamage(monster, game->player, armor);
        }
    } while(!isFinished);
    Inventory* inventoryMonster = getInventoryFromId(monster->idInventory);
    appendInventory(game->player, inventoryMonster);
    freeMonster(monster);
}

