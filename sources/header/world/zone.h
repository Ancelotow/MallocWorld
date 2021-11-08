//
// Created by Admin on 17/10/2021.
//

#ifndef MALLOCWORLD_ZONE_H
#define MALLOCWORLD_ZONE_H

#include <stdio.h>

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

/**
 * Generated a zone
 * @param type The zone's type (1, 2 or 3)
 * @return The zone
 */
Zone* generateZone(TypeZone type);

/**
 * Placed the player in zone 1
 * @param zone The zone 1
 */
void placePlayer(Zone* zone);

/**
 * Printed into console the zone
 * @param zone The zone
 */
void printZone(Zone* zone);

/**
 * Free the zone (including the map) from memory
 * @param zone The zone
 */
void freeZone(Zone* zone);

/**
 * Generated a portal (portal to pass between each zone) into a zone
 * @param zone The zone
 */
void generatePortail(Zone* zone);

/**
 * Get plant from zone
 * @param type The type of zone (1, 2 or 3)
 * @return The plant
 */
Element getElementPlant(TypeZone type);

/**
 * Get wood from zone
 * @param type The type of zone (1, 2 or 3)
 * @return The wood
 */
Element getElementWood(TypeZone type);

/**
 * Get rock from zone
 * @param type The type of zone (1, 2 or 3)
 * @return The rock
 */
Element getElementRock(TypeZone type);

/**
 * Get a random resource (plant, wood or rock) for a zone
 * @param typeZone The type of zone (1, 2 or 3)
 * @return The random resource
 */
int getRandomResource(TypeZone typeZone);

/**
 * Get a random monster for a zone
 * @param typeZone The type of zone (1, 2 or 3)
 * @return The random monster
 */
int getRandomMonster(TypeZone typeZone);

void printZoneDebug(Zone* zone);

void saveZone(FILE* file, Zone zone);

int isResource(int id);

int isMonster(int id);

int getIdResource(Element element);

#endif //MALLOCWORLD_ZONE_H
