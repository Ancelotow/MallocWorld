/*
**  Filename : player.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'player.c'. Manage the player.
*/

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H

typedef struct Stack Stack;
typedef struct Inventory Inventory;
typedef enum Element Element;
typedef enum InventoryType InventoryType;

typedef struct Player{
    int currentHp;
    int maxHp;
    Stack** inventory;
    int sizeInventory;
    int level;
    int xp;
    int xpNext;
} Player;

Player* createPlayer(int currentHp, int maxHp, Stack** inventory, int sizeInventory, int level, int xp, int xpNext);

Player* createPlayerLevel1();

int appendInventory(Player* player, Inventory* inventory);

void printPlayerDebug(Player player);

void printInventoryPlayer(Player player, InventoryType type);

int useToolToMining(Element element, Player* player);

void freePlayer(Player* player);

void savePlayer(FILE* file, Player player);

#endif //MALLOCWORLD_PLAYER_H
