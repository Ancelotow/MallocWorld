/*
**  Filename : save.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the backup
*/

#include "../../header/global.h"

#define PATH_SAVE "../resources/save/save.txt"

/**
 * Sauvegarde le jeu
 * @param game
 */
void saveGame(Game game){
    FILE* file = fopen(PATH_SAVE, "w+");
    if(file != NULL){
        saveWorld(file, *game.world);
        savePlayer(file, *game.player);
        saveStorage(file, game.storage);
        fclose(file);
    } else{
        printf("Impossible d'enregistrer !\n\n");
    }
}

/**
 * Sauvegarde le monde
 * @param file
 * @param world
 */
void saveWorld(FILE* file, World world){
    fputs("=== MAP ===\n", file);
    for(int i = 0; i < NB_ZONE; i++){
        saveZone(file, *world.world[i]);
    }
}

/**
 * Sauvegarde la position du joueur et la zone
 * @param file
 * @param zone
 */
void saveZone(FILE* file, Zone zone){
    fprintf(file, "-- ZONE %d --\n", zone.type);
    for(int i = 0; i < zone.row; i++){
        for(int j = 0; j < zone.column; j++){
            fprintf(file, "%2d", zone.map[i][j]);
            if(j + 1 < zone.column){
                fputc(' ', file);
            }
        }
        fputs("\n", file);
    }
}

/**
 * Sauvegarde les paramètres du joueurs (vie, niveau, expérience)
 * @param file
 * @param player
 */
void savePlayer(FILE* file, Player player){
    fputs("=== PLAYER ===\n", file);
    fprintf(file, "{%d}\n", player.level);
    fprintf(file, "{%d}/{%d}\n", player.xp, player.xpNext);
    fprintf(file, "{%d}/{%d}\n", player.currentHp, player.maxHp);
    fputs("-- INVENTORY --\n", file);
    savePlayerInventory(file, player);
}

/**
 * Sauvegarde l'inventaire du joueur
 * @param file
 * @param player
 */
void savePlayerInventory(FILE* file, Player player){
    Inventory* inv;
    for(int i = 0; i < 20; i++){
        if(i < player.sizeInventory){
            inv = getInventoryFromId(player.inventory[i]->id);
            fprintf(file, "{%d}@{%d}@{%.0f}\n", player.inventory[i]->length, player.inventory[i]->id, player.inventory[i]->inventory[0]->durability);
        } else {
            fprintf(file, "{0}@{0}@{0}\n");
        }
    }
    freeInventory(inv);
}

/**
 * Sauvegarde le storage
 * @param file
 * @param storage
 */
void saveStorage(FILE* file, Storage* storage){
    fputs("-- STORAGE --\n", file);
    while(storage != NULL){
        fprintf(file, "{%d}@{%d}\n", storage->id, storage->quantity);
        storage = storage->next;
    }
}