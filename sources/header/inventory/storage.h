/*
**  Filename : storage.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'storage.c'. It's used to manage the PNJ's storage
*/

#ifndef MALLOCWORLD_STORAGE_H
#define MALLOCWORLD_STORAGE_H

typedef struct Game Game;
typedef struct Player Player;

typedef struct Storage{
    int id;
    int quantity;
    struct Storage* next;
} Storage;

/**
 * Création d'un stockage
 * @param id L'ID de l'inventaire
 * @param quantity La quantité
 * @return Le stockage
 */
Storage* createStorage(int id, int quantity);

/**
 * Récupération d'inventaires depuis le stockage
 * @param game Le jeu
 * @param id L'ID de l'inventaire à récupérer
 * @param quantity La quantité à récupérer
 */
void retrieveFromStorage(Game* game, int id, int quantity);

/**
 * Stocke un inventaire dans le stockage
 * @param game Le jeu
 * @param id L'ID de l'inventaire à stocker
 * @param quantity La quantité à stocker
 */
void storeIntoStorage(Game *game, int id, int quantity);

/**
 * Ajoute un stockage dans la liste chaînée des stockage
 * @param game Le jeu
 * @param newStorage Le stockage
 */
void appendStorage(Game* game, Storage* newStorage);

/**
 * Affiche le Storage
 * @param storage
 */
void printStorage(Storage* storage);

/**
 * Libère la mémoire du stockage
 * @param storage Le stockage
 */
void freeStorage(Storage* storage);

#endif //MALLOCWORLD_STORAGE_H