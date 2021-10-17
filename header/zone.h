//
// Created by Admin on 17/10/2021.
//

#ifndef MALLOCWORLD_ZONE_H
#define MALLOCWORLD_ZONE_H

typedef enum Element{
    PORTAL_ZONE_2 = -2,
    PORTAL_ZONE_3 = -3,
    IMPASSABLE = -1,
    FREE = 0,
    PLAYER = 1,
    PNJ = 2,
    PLANT_ZONE_1 = 3,
    ROCK_ZONE_1 = 4,
    WOOD_ZONE_1 = 5,
    PLANT_ZONE_2 = 6,
    ROCK_ZONE_2 = 7,
    WOOD_ZONE_2 = 8,
    PLANT_ZONE_3 = 9,
    ROCK_ZONE_3 = 10,
    WOOD_ZONE_3 = 11,
    BOSS = 99
} Element;

typedef enum TypeZone{
    ZONE_1 = 1,
    ZONE_2 = 2,
    ZONE_3 = 3
} TypeZone;

typedef struct Zone{
    int row;
    int column;
    int** map;
    TypeZone type;
} Zone;

Zone* generateZone(TypeZone type);
void printZone(Zone* zone);
void freeZone(Zone* zone);
void generatePortail(Zone* zone);
Element getElementPlant(TypeZone type);
Element getElementWood(TypeZone type);
Element getElementRock(TypeZone type);
int getRandomResource(TypeZone zone);
int getRandomMonster(TypeZone typeZone);

#endif //MALLOCWORLD_ZONE_H
