/*
**  Filename : restore.h
**
**  Made by : Owen ANCELOT
**
**  Description : Restore the game from save file.
*/
#include "../../header/global.h"

Game* restoreGame(char* path){
    FILE* file = fopen(path, "r");
    if(file != NULL){
        char result[500];
        Game* game = malloc(sizeof(Game));
        int length = getFileLength(file);
        while(ftell(file) < length){
            fgets(result, 500, file);
            if(!strcmp(result, "=== MAP ===\n")){
                printf("%s\n", result);
                restoreMap(file, game, length);
            } else {
                break;
            }
        }
    } else {
        printf("Impossible de charger la sauvegarde...\n\n");
        return NULL;
    }
}

void restoreMap(FILE* file, Game* game, int length){
    game->world = malloc(sizeof(World));
    game->world->world = malloc(sizeof(Zone*) * NB_ZONE);
    int nbZoneGenerated = 0;
    char result[500];
    while(ftell(file) < length || nbZoneGenerated >= NB_ZONE){
        fgets(result, 500, file);
        if(!strcmp(result, "-- ZONE 1 --\n")){
            restoreZone(file, game->world, length, ZONE_1);
            nbZoneGenerated += 1;
        } else if (!strcmp(result, "-- ZONE 2 --\n")){
            restoreZone(file, game->world, length, ZONE_2);
            nbZoneGenerated += 1;
        } else if (!strcmp(result, "-- ZONE 3 --\n")){
            nbZoneGenerated += 1;
            restoreZone(file, game->world, length, ZONE_3);
        }
    }
}

void restoreZone(FILE* file, World* world, int length, TypeZone typeZone){
    world->world[typeZone - 1] = malloc(sizeof(Zone));
    world->world[typeZone - 1]->column = 0;
    world->world[typeZone - 1]->row = 0;
    int** map = malloc(sizeof(int*) * 200);
    char result[500];
    char *caseZone;

    while(ftell(file) < length){
        fgets(result, 500, file);
        if(isEndZoneIntoSaveFile(result)){
            break;
        }
        world->world[typeZone - 1]->column = 0;
        map[world->world[typeZone - 1]->row] = malloc(sizeof(int) * 200);
        caseZone = strtok(result, "  ");
        while(caseZone != NULL){
            map[world->world[typeZone - 1]->row][world->world[typeZone - 1]->column] = atoi(caseZone);
            world->world[typeZone - 1]->column += 1;
            caseZone = strtok(NULL, " ");
        }
        world->world[typeZone - 1]->row += 1;
    }

    world->world[typeZone - 1]->map = malloc(sizeof(int*) * world->world[typeZone - 1]->row);
    for(int i = 0; i < world->world[typeZone - 1]->row; i++){
        world->world[typeZone - 1]->map[i] = malloc(sizeof(int*) * world->world[typeZone - 1]->column);
        for(int j = 0; j < world->world[typeZone - 1]->column; j++){
            world->world[typeZone - 1]->map[i][j] = map[i][j];
        }
    }
    freeTab2D(map, world->world[typeZone - 1]->row);
}

int isEndZoneIntoSaveFile(char* string){
    if(!strcmp(string, "-- ZONE 1 --")){
        return 1;
    } else if (!strcmp(string, "-- ZONE 2 --")){
        return 1;
    } else if (!strcmp(string, "-- ZONE 3 --")){
        return 1;
    } else if (!strcmp(string, "=== PLAYER ===")){
        return 1;
    } else {
        return 0;
    }
}

