/*
**  Filename : save.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the backup
*/

#include "../../header/global.h"

#define PATH_SAVE "../saves/"

char* createFilenameSave(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char totalStr[10];
    int total = tm.tm_sec + tm.tm_min + tm.tm_hour + tm.tm_mday + tm.tm_mon + tm.tm_year;
    sprintf(totalStr, "%d", total);
    char* filename = concatStr("save_", totalStr);
    filename = concatStr(filename, ".txt");
    return filename;
}

/**
 * Sauvegarde le jeu
 * @param game Le jeu
 */
void saveGame(Game game){
    char* filename = createFilenameSave();
    char* fullpath = concatStr(PATH_SAVE, createFilenameSave());
    mkdir(PATH_SAVE);
    FILE* file = fopen(fullpath, "w+");
    if(file != NULL){
        saveWorld(file, *game.world);
        savePlayer(file, *game.player);
        saveStorage(file, game.storage);
        fclose(file);
    } else{
        printf("Impossible d'enregistrer !\n\n");
    }
    free(filename);
}

/**
 * Sauvegarde le monde
 * @param file Le fichier
 * @param world Le monde
 */
void saveWorld(FILE* file, World world){
    fputs("=== MAP ===\n", file);
    for(int i = 0; i < NB_ZONE; i++){
        saveZone(file, *world.world[i]);
    }
}

/**
 * Sauvegarde la zone
 * @param file Le fichier
 * @param zone La zone
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
 * @param file Le fichier
 * @param player Le joueur
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
 * @param file Le fichier
 * @param player Le joueur
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
 * Sauvegarde le stockage
 * @param file Le fichier
 * @param storage Le stockage
 */
void saveStorage(FILE* file, Storage* storage){
    fputs("-- STORAGE --\n", file);
    while(storage != NULL){
        fprintf(file, "{%d}@{%d}\n", storage->id, storage->quantity);
        storage = storage->next;
    }
}