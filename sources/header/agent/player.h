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

/**
 * Création d'un joueur
 * @param currentHp Les points de vie courant du joueur
 * @param maxHp Les points de vie max du joueur
 * @param inventory L'inventaire du joueur
 * @param sizeInventory Le nombre d'inventaire du joueur
 * @param level Le niveau du joueur
 * @param xp L'expérience du joueur
 * @param xpNext L'expérience nécessaire pour changer de niveau
 * @return Le joueur
 */
Player* createPlayer(int currentHp, int maxHp, Stack** inventory, int sizeInventory, int level, int xp, int xpNext);

/**
 * Création d'un joueur de niveau 1
 * @return Le joueur
 */
Player* createPlayerLevel1();

/**
 * Ajoute un inventaire à dans l'inventaire du joueur
 * @param player Le joueur
 * @param inventory L'inventaire à ajouter
 * @return Si l'inventaire à été ajouté ou non
 */
int appendInventory(Player* player, Inventory* inventory);

/**
 * Fonction de test pour afficher un joueur
 * @param player Le joueur
 */
void printPlayerDebug(Player player);

/**
 * Affiche l'inventaire du joueur
 * @param player Le joueur
 * @param type Le type d'inventaire à afficher (0 pour tout afficher)
 */
void printInventoryPlayer(Player player, InventoryType type);

/**
 * Utilisation d'un outil de minage (change la durabilité)
 * @param element L'élément miné
 * @param player Le joueur
 * @return Si l'outil est utilisable ou non
 */
int useToolToMining(Element element, Player* player);

/**
 * Gain d'expérience pour le joueur
 * @param player Le joueur
 * @param experience L'expérience gagné
 */
void gainExperience(Player* player, int experience);

/**
 * Libère le joueur de la mémoire
 * @param player Le joueur
 */
void freePlayer(Player* player);

Inventory* findInventory(int id);

/**
 * Récupération du nombre d'inventaire pour un type donné
 * @param player Le joueur
 * @param type Le type d'inventaire
 * @return Le nombre d'inventaire
 */
int getLengthInventoryType(Player player, InventoryType type);

/**
 * Récupération de la quantité d'un objet donné
 * @param player Le joueur
 * @param idInventory L'ID de l'inventaire
 * @return La quantité
 */
int getQuantityInventory(Player player, int idInventory);

/**
 * Supprime un nombre d'objet donné de l'inventaire du joueur
 * @param player Le joueur
 * @param id L'ID de l'inventaire
 * @param quantity La quantité à supprimer
 */
void removeQuantityInventory(Player* player, int id, int quantity);

/**
 * Suppression d'un inventaire à un index donné
 * @param player Le joueur
 * @param index L'index à supprimer
 */
void deleteInventory(Player* player, int index);

#endif //MALLOCWORLD_PLAYER_H
