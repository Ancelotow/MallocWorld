/*
**  Filename : save.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for "save.c". Save the game into save file.
*/

#ifndef MALLOCWORLD_SAVE_H
#define MALLOCWORLD_SAVE_H

typedef struct Zone Zone;

/**
 * Sauvegarde le jeu
 * @param game Le jeu
 */
void saveGame(Game game);

/**
 * Sauvegarde le monde
 * @param file Le fichier
 * @param world Le monde
 */
void saveWorld(FILE* file, World world);

/**
 * Sauvegarde les paramètres du joueurs (vie, niveau, expérience)
 * @param file Le fichier
 * @param player Le joueur
 */
void savePlayer(FILE* file, Player player);

/**
 * Sauvegarde l'inventaire du joueur
 * @param file Le fichier
 * @param player Le joueur
 */
void savePlayerInventory(FILE* file, Player player);

/**
 * Sauvegarde le stockage
 * @param file Le fichier
 * @param storage Le stockage
 */
void saveStorage(FILE* file, Storage* storage);

/**
 * Sauvegarde la zone
 * @param file Le fichier
 * @param zone La zone
 */
void saveZone(FILE* file, Zone zone);

#endif //MALLOCWORLD_SAVE_H
