#include "../../../header/world/zone.h"
#include "../../../header/global.h"

const int HOUSE_HEIGHT = 7;
const int HOUSE_WIDTH = 7;

void generateResource_Village(Zone* zone){
    int random;
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            if(zone->map[i][j] == 0){
                random = getRandomNumber(0) % 10;
                if(random == 0){
                    zone->map[i][j] = getRandomResource(zone->type);
                }
            }
        }
    }
}

void generateHouse(Zone* zone, int row, int column, int isPnjHouse){
    for (int i = 1; i < HOUSE_HEIGHT - 1; i++) {
        zone->map[row + i][column + 1] = IMPASSABLE;
        zone->map[row + i][column + HOUSE_WIDTH - 2] = IMPASSABLE;
    }
    for (int i = 2; i < HOUSE_WIDTH - 2; i++) {
        zone->map[row + 1][column + i] = IMPASSABLE;
        if (HOUSE_WIDTH / 2 != i) {
            zone->map[row + HOUSE_HEIGHT - 2][column + i] = IMPASSABLE;
        }
    }
    if(isPnjHouse){
        zone->map[row + HOUSE_HEIGHT / 2][column + HOUSE_WIDTH / 2] = PNJ;
    } else{
        int random = getRandomNumber(0) % 2;
        if(random){
            zone->map[row + HOUSE_HEIGHT - 3][column + HOUSE_WIDTH - 3] = getRandomMonster(zone->type);
            zone->map[row + 2][column + 2] = getRandomMonster(zone->type);
        } else {
            zone->map[row + HOUSE_HEIGHT / 2][column + HOUSE_WIDTH / 2] = getRandomMonster(zone->type);
        }
    }
}

void generateVillage(Zone* zone){
    int pnjGenerated = 0;
    while (!pnjGenerated){
        for(int i=0; i < zone->row; i += HOUSE_HEIGHT){
            for(int j=0; j < zone->column; j += HOUSE_WIDTH){
                if(i + HOUSE_HEIGHT <= zone->row && j + HOUSE_WIDTH <= zone->column){
                    if(getRandomNumber(0) % 2 && !pnjGenerated){
                        generateHouse(zone, i, j, 1);
                        pnjGenerated = 1;
                    } else {
                        generateHouse(zone, i, j, 0);
                    }
                }
            }
        }
    }
    generatePortail(zone);
    generateResource_Village(zone);
}



