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

void gainExperience(Player* player, int experience);

void freePlayer(Player* player);

Inventory* findInventory(int id);

int getLengthInventoryType(Player player, InventoryType type);

#endif //MALLOCWORLD_PLAYER_H
