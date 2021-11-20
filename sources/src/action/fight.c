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
#define CMD_FIGHT_ARMOR 'p'
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

void usePotion(Player* player){
    int nbHealth = getLengthInventoryType(*player, CARE);
    if(nbHealth > 0){
        char strId[10];
        printf("Liste de vos potions :\n");
        printInventoryPlayer(*player, CARE);
        printf("Choississez une potion en saisissant l'ID : ");
        scanf("%s", strId);
        printf("\n\n");
        int length;
        int id = atoi(strId);
        for(int i = 0; i < player->sizeInventory; i++){
            length = player->inventory[i]->length;
            if(player->inventory[i]->id == id && length > 0){
                player->currentHp += player->inventory[i]->inventory[length - 1]->value;
                player->inventory[i]->inventory[length - 1]->durability -= 1;
                if(player->inventory[i]->inventory[length - 1]->durability <= 0){
                    deleteStack(length - 1, player->inventory[i]);
                }
                break;
            }
        }
    } else {
        printMessage("Vous n'avez pas de potion");
    }
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

int tryToEscape(Position* position, Game* game){
    int random = getRandomNumber(0) % 3;
    if(random == 0){
        printMessage("Vous avez fui !");
        position->x = game->position->x;
        position->y = game->position->y;
        position->zone = game->position->zone;
        return 1;
    } else {
        printMessage("Fuite echouee...");
        return 0;
    }
}

int actionFight(char action, Monster* monster, Game* game, Inventory* weapon, Inventory* armor, Position* position){
    int isOver = 0;
    switch (action) {
        case CMD_FIGHT_ATTACK:
            isOver = attack(monster, game->player, weapon);
            break;

        case CMD_FIGHT_ESCAPE:
            isOver = tryToEscape(position, game);
            break;

        case CMD_FIGHT_HEALTH:
            usePotion(game->player);
            break;

        case CMD_FIGHT_WEAPON:
            weapon = choiceWeapon(game->player);
            break;

        case CMD_FIGHT_ARMOR:
            armor = choiceArmor(game->player);
            break;

        default:
            printf("\nAction inconnue !\n");
            break;
    }
    return isOver;
}

int sufferDamage(Monster* monster, Game* game, Inventory* armor){
    int protection = 0;
    if(armor != NULL){
        if(armor->durability > 0){
            protection = armor->value;
            armor->durability -= 1;
            if(armor->durability <= 0){
                printMessage("Votre armure est cassée");
            }
        }
    }
    int damage = monster->damage - protection;
    if(damage > 0){
        game->player->currentHp -= damage;
        if(game->player->currentHp <= 0) {
            printMessage("Vous etes mort...");
            return 1;
        }
    }
    return 0;
}

void startFight(int id, Game* game, Position position){
    Inventory* weapon = choiceWeapon(game->player);
    Inventory* armor = choiceArmor(game->player);
    Position* posMonster = createPositionFromExisting(position);
    Monster* monster = getMonsterFromId(id);
    int isFinished;
    char action;
    do {
        printFight(*monster, *game->player, *weapon);
        printf("\n");
        printActionFight();
        printf("Quel action souhaitez-vous faire : ");
        scanf("%c", &action);
        scanf("%c", &action);
        printf("\n");
        isFinished = actionFight(action, monster, game, weapon, armor, posMonster);
        if(!isFinished){
            isFinished = sufferDamage(monster, game, armor);
        }
    } while(!isFinished);
    Inventory* inventoryMonster = getInventoryFromId(monster->idInventory);
    appendInventory(game->player, inventoryMonster);
    appendRespawn(game->respawn, monster->id, posMonster);
    game->position->x = posMonster->x;
    game->position->y = posMonster->y;
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    freeMonster(monster);
}

