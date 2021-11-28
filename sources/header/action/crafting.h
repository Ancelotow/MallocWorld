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

/**
 * Gère les intéraction du joueur avec les actions de crafting
 * @param game Le jeu
 */
void actionCraft(Game* game);

void craftInventory(int id, ListCraft* listCraft, Game* game);

/**
 * Craft un objet
 * @param listCraft Liste des craft disponible
 * @param game Le jeu
 * @param id L'ID de l'inventaire à crafter
 */
void crafting(ListCraft* listCraft, Game* game, int id);

/**
 * Affiche la liste des craft disponible
 * @param listCraft Liste des crafts
 */
void printListCraft(ListCraft listCraft);

/**
 * Création d'un craft en faisait des 'split' depuis une ligne d'un CSV
 * @param csv La ligne CSV
 * @return Le craft
 */
Craft* craftInventoryWithSplit(char* csv);

/**
 * Affiche un craft
 * @param craft Le craft
 */
void printCraft(Craft craft);

/**
 * Création d'un craft
 * @param inventoryCraft L'inventaire qui sera crafter
 * @param inv1 L'élement 1 pour crafter
 * @param quantityInv1 La quantité d'élement 1 pour crafter
 * @param inv2 L'élement 2 pour crafter
 * @param quantityInv2 La quantité d'élement 2 pour crafter
 * @param zoneMin La zone minimum requis pour crafter l'objet
 * @return Le craft
 */
Craft* createCraft(Inventory* inventoryCraft, int inv1, int quantityInv1, int inv2, int quantityInv2, int zoneMin);

/**
 * Création d'une liste de crafts
 * @return La liste de crafts
 */
ListCraft* createListCraft();

/**
 * Récupération de la liste des crafts possible
 * @param game Le jeu
 * @return Liste des crafts possible
 */
ListCraft* getListCraftPossible(Game* game);

/**
 * Spécifie si le craft est possible ou non pour un objet
 * @param craft Le craft
 * @param game Le jeu
 * @return Si c'est possible de crafter ou pas
 */
int craftIsPossible(Craft craft, Game game);

/**
 * Libère un craft de la mémoire
 * @param craft Le craft
 */
void freeCraft(Craft* craft);

/**
 * Libère la liste des crafts de la mémoire
 * @param listCraft La liste des crafts
 */
void freeListCraft(ListCraft* listCraft);

#endif //MALLOCWORLD_CRAFTING_H
