#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include "../world/zone.h"

#define FILENAME_INVENTORIES "../resources/inventories.csv"

typedef enum InventoryType{
    WEAPON = 1,
    ARMOR = 2,
    CARE = 3,
    RESOURCE = 4,
    TOOL = 5
} InventoryType;

typedef enum ResourceType{
    PLANT = 1,
    WOOD = 2,
    ROCK = 3
} ResourceType;

typedef struct Inventory{
    int id;
    char* name;
    int value;
    float durability;
    float durabilityMax;
    int maxStack;
    InventoryType type;
} Inventory;

/**
 * Get name of inventory type
 * @param type Inventory type
 * @return Name of inventory type
 */
char* getInventoryTypeName(InventoryType type);

/**
 * Create an inventory's object
 * @param id Object's id
 * @param name Object's name (ex: "Sword of Excalibur")
 * @param value Object's value (ex: 13 of damage for weapons)
 * @param durability Object's durability
 * @param type Object's type (Tool, Weapon, Armor, Resource, Care)
 * @return Inventory's object created
 */
Inventory* createInventory(int id, char* name, int value, float durability, int maxStack, InventoryType type);

/**
 * Printed into the console the information about an inventory's object
 * @param inventory Inventory's object
 */
void printInventoryDebug(Inventory inventory);

void printInventory(Inventory inventory);

/**
 * Free inventory object (including name) from memory
 * @param inventory
 */
void freeInventory(Inventory* inventory);

Inventory* getInventoryFromId(int id);

int isIdTool_Plant(Element element, int id);

int isIdTool_Rock(Element element, int id);

int isIdTool_Wood(Element element, int id);

int isIdTool(Element element, int id);

float getUsury(Element element);

#endif //MALLOCWORLD_INVENTORY_H
