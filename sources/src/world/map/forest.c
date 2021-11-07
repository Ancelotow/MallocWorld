#include "../../../header/world/zone.h"
#include "../../../header/global.h"

const int TREE_WIDTH = 7;
const int TREE_HEIGHT = 7;

void generateResource_Forest(Zone* zone){
    int random;
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            if(zone->map[i][j] == 0){
                random = getRandomNumber(0) % 10;
                if(random == 0){
                    zone->map[i][j] = getRandomResource(zone->type);
                } else if(random < 2){
                    zone->map[i][j] = getElementPlant(zone->type);
                }
            }
        }
    }
}

void generateTree_One(Zone* zone, int row, int column, int isPnjTree){
    int middleHeight = TREE_HEIGHT / 2;
    int middleWidth = TREE_WIDTH / 2;
    for(int i=1; i < TREE_HEIGHT - 1; i++){
        zone->map[row + i][column + middleWidth] = IMPASSABLE;
    }
    for(int i=1; i < TREE_WIDTH - 1; i++){
        zone->map[row + middleHeight][column + i] = IMPASSABLE;
        if(i == (middleWidth - 1) || i == (middleWidth + 1)){
            zone->map[row + middleHeight + 1][column + i] = IMPASSABLE;
            zone->map[row + middleHeight - 1][column + i] = IMPASSABLE;
        }
    }
    int value = (isPnjTree) ? 2 : getRandomMonster(zone->type);
    zone->map[row + middleHeight + 1][column + middleWidth + 2] = value;
}

void generateTree_Two(Zone* zone, int row, int column){
    int monsterLeft = 3;
    int random;
    int rowStart = getRandomNumber(0) % (TREE_HEIGHT - 3);
    int columnStart = getRandomNumber(0) % (TREE_HEIGHT - 3);
    for(int j=0; j < 3; j++){
        zone->map[row + rowStart + j][column + columnStart] = IMPASSABLE;
        zone->map[row + rowStart + j][column + columnStart + 1] = IMPASSABLE;
        zone->map[row + rowStart + j][column + columnStart + 2] = IMPASSABLE;
    }
    int index = 0;
    while (monsterLeft > 0){
        for(int j=0; j < TREE_WIDTH; j++){
            if(monsterLeft <= 0){
                break;
            } else if(zone->map[row + index][column + j] == 0){
                random = getRandomNumber(0) % 10;
                if(random == 0){
                    zone->map[row + index][column + j] = getRandomMonster(zone->type);
                    monsterLeft -= 1;
                }
            }
        }
        index += 1;
        if(index >= TREE_HEIGHT){
            index = 0;
        }
    }
}

void generateForest(Zone* zone){
    int pnjGenerated = 0;
    while (!pnjGenerated) {
        for (int i = 0; i < zone->row; i += TREE_HEIGHT) {
            for (int j = 0; j < zone->column; j += TREE_WIDTH) {
                if (i + TREE_HEIGHT <= zone->row && j + TREE_WIDTH <= zone->column) {
                    if (getRandomNumber(0) % 2) {
                        if (!pnjGenerated) {
                            generateTree_One(zone, i, j, 1);
                            pnjGenerated = 1;
                        } else {
                            generateTree_One(zone, i, j, 0);

                        }
                    } else {
                        generateTree_Two(zone, i, j);
                    }
                }
            }
        }
    }
    generatePortail(zone);
    generateResource_Forest(zone);
}
