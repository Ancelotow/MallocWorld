/*
**  Filename : zone.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage zone of world (also create a zone's type randomly and his height and width)
*/

#include "../../header/global.h"

Zone* generateZone(TypeZone type){
    Zone* zone = malloc(sizeof(Zone));
    zone->row = 20; //getRandomNumber(20);
    zone->column = 20; //getRandomNumber(20);
    zone->type = type;
    zone->map = malloc(sizeof(int*) * zone->row);
    for(int i=0; i < zone->row; i++){
        zone->map[i] = malloc(sizeof(int) * zone->column);
        for(int j=0; j < zone->column; j++){
            zone->map[i][j] = 0;
        }
    }
    if(getRandomNumber(0) % 2){
        generateVillage(zone);
    } else {
        generateForest(zone);
    }
    if(zone->type == ZONE_1) {
        placePlayer(zone);
    }
    return zone;
}

void generatePortail(Zone* zone){
    int position = getRandomNumber(0) % zone->column;
    int position_bis = getRandomNumber(0) % zone->column;
    switch(zone->type){
        case ZONE_1:
            zone->map[zone->row - 1][position] = PORTAL_ZONE_2;
            break;

        case ZONE_2:
            zone->map[0][position] = PORTAL_ZONE_2;
            zone->map[zone->row - 1][position_bis] = PORTAL_ZONE_3;
            break;

        case ZONE_3:
            zone->map[0][position] = PORTAL_ZONE_3;
            break;
    }
}

void placePlayer(Zone* zone){
    if(zone->type == ZONE_1){
        int playerGenerate = 0;
        while(!playerGenerate){
            int colStart = getRandomNumber(0) % zone->column;
            if(zone->map[0][colStart]  == 0){
                zone->map[0][colStart] = PLAYER;
                playerGenerate = 1;
            }
        }
    }
}

Element getElementPlant(TypeZone type){
    switch(type){
        case ZONE_1:
            return PLANT_ZONE_1;

        case ZONE_2:
            return PLANT_ZONE_2;

        case ZONE_3:
            return PLANT_ZONE_3;

        default:
            return FREE;
    }
}

Element getElementWood(TypeZone type){
    switch(type){
        case ZONE_1:
            return WOOD_ZONE_1;

        case ZONE_2:
            return WOOD_ZONE_2;

        case ZONE_3:
            return WOOD_ZONE_3;

        default:
            return FREE;
    }
}

Element getElementRock(TypeZone type){
    switch(type){
        case ZONE_1:
            return ROCK_ZONE_1;

        case ZONE_2:
            return ROCK_ZONE_2;

        case ZONE_3:
            return ROCK_ZONE_3;

        default:
            return FREE;
    }
}

Element getRandomResource(TypeZone typeZone){
    int type = (getRandomNumber(0) % 3) + 1;
    switch(type){
        case PLANT:
            return getElementPlant(typeZone);

        case WOOD:
            return getElementWood(typeZone);

        case ROCK:
            return getElementRock(typeZone);

        default:
            return FREE;
    }
}

int getRandomMonster(TypeZone typeZone){
    int monsterStart = 0;
    switch (typeZone){
        case ZONE_1:
            monsterStart = 12;
            break;

        case ZONE_2:
            monsterStart = 24;
            break;

        case ZONE_3:
            monsterStart = 36;
            break;
    }
    return (getRandomNumber(0) % 11) + monsterStart + 1;
}

void printZoneDebug(Zone* zone){
    printf("-- ZONE %d --  (row: %d, column: %d)\n", zone->type, zone->row, zone->column);
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            printf("%2d ", zone->map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void printZone(Zone* zone){
    printf("-- ZONE %d -- \n", zone->type);
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            printf("%2d ", zone->map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void freeZone(Zone* zone){
    for(int i=0; i < zone->row; i++){
        free(zone->map[i]);
    }
    free(zone->map);
    free(zone);
}

int isResource(int id){
    if(id < 12 && id >= 3){
        return 1;
    } else {
        return 0;
    }
}

int getIdResource(Element element){
    switch (element) {
        default:
        case PLANT_ZONE_1:
            return 7;

        case PLANT_ZONE_2:
            return 18;

        case PLANT_ZONE_3:
            return 29;

        case WOOD_ZONE_1:
            return 5;

        case WOOD_ZONE_2:
            return 16;

        case WOOD_ZONE_3:
            return 27;

        case ROCK_ZONE_1:
            return 6;

        case ROCK_ZONE_2:
            return 17;

        case ROCK_ZONE_3:
            return 28;
    }
}

int isMonster(int id){
    if(id >= 12){
        return 1;
    } else {
        return 0;
    }
}

int isPortal(int id){
    if(id == -2 || id == -3){
        return 1;
    } else {
        return 0;
    }
}

Position getPositionPortal(Zone zone, Element portal){
    Position posPortal;
    for(int i = 0; i < zone.row; i++){
        for(int j = 0; j < zone.column; j++){
            if(zone.map[i][j] == portal){
                posPortal.x = j;
                posPortal.y = i;
                posPortal.zone = (zone.type - 1);
                return posPortal;
            }
        }
    }
    return posPortal;
}