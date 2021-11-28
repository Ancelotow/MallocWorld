/*
**  Filename : inventory.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'inventory.c'. It's used to manage inventory
*/

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H


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
 * Récupération du nom d'un type d'inventaire
 * @param type Le type d'inventaire
 * @return Le nom du type d'inventaire
 */
char* getInventoryTypeName(InventoryType type);

/**
 * Création d'un inventaire
 * @param id L'ID
 * @param name Le nom
 * @param value La valeur (dégâts, sauvegarde de dégâts, nombre de HP restaurer)
 * @param durability La durabilité
 * @param maxStack L'empilation max
 * @param type Le type (Armure, Arme, Outil, Ressource, Potion)
 * @return L'inventaire créé
 */
Inventory* createInventory(int id, char* name, int value, float durability, int maxStack, InventoryType type);

/**
 * Fonction de test pour afficher un inventaire
 * @param inventory L'inventaire
 */
void printInventoryDebug(Inventory inventory);

/**
 * Affiche un inventaire
 * @param inventory L'inventaire
 */
void printInventory(Inventory inventory);

/**
 * Libère de la mémoire l'inventaire
 * @param inventory L'inventaire
 */
void freeInventory(Inventory* inventory);

/**
 * Récupération d'un inventaire depuis le CSV en fonction de l'ID
 * @param id L'ID de l'inventaire
 * @return L'inventaire
 */
Inventory* getInventoryFromId(int id);

#endif //MALLOCWORLD_INVENTORY_H
