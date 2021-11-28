/*
**  Filename : pnj.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'pnj.c'. Manage action with PNJ (storage, repair, craft)
*/

#ifndef MALLOCWORLD_PNJ_H
#define MALLOCWORLD_PNJ_H

/**
 * Gère les intéraction du joueur avec le PNJ
 * @param game Le jeu
 */
void interactionWithPnj(Game* game);

/**
 * Exécute l'action voulu par le joueur
 * @param action Action
 * @param game Le jeu
 * @return Si on quitte le PNJ ou non
 */
int actionPNJ(char action, Game* game);

/**
 * Répare tout l'inventaire du joueur
 * @param player Le joueur
 */
void repairPlayerInventory(Player* player);

/**
 * Stocke de l'inventaire dans le stockage
 * @param game Le jeu
 */
void stockStorage(Game* game);

/**
 * Récupère un inventaire du stockage
 * @param game Le jeu
 */
void retrieveStorage(Game* game);

#endif //MALLOCWORLD_PNJ_H
