/*
**  Filename : craft.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for "craft.c". Craft tools, armors, weapons and potions
*/

#ifndef MALLOCWORLD_CRAFTING_H
#define MALLOCWORLD_CRAFTING_H

#define FILENAME_CRAFT "../resources/craft.csv"
#define MAX_LENGTH_LIST_CRAFT 25

typedef struct Craft{
    Inventory* inventoryCraft;
    int inventory1;
    int quantityInv1;
    int inventory2;
    int quantityInv2;
    int zoneMin;
} Craft;

typedef struct ListCraft{
    Craft** list;
    int length;
} ListCraft;

void actionCraft(Game* game);

void craftInventory(int id, ListCraft* listCraft, Game* game);

void crafting(ListCraft* listCraft, Game* game, int id);

void printListCraft(ListCraft listCraft);

Craft* craftInventoryWithSplit(char* csv);

void printCraft(Craft craft);

Craft* createCraft(Inventory* inventoryCraft, int inv1, int quantityInv1, int inv2, int quantityInv2, int zoneMin);

ListCraft* createListCraft();

ListCraft* getListCraftPossible(Game* game);

int craftIsPossible(Craft craft, Game game);

void freeCraft(Craft* craft);

void freeListCraft(ListCraft* listCraft);

#endif //MALLOCWORLD_CRAFTING_H
