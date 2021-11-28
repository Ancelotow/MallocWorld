/*
**  Filename : zone.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'zone.c'. Manage a zone in the world
*/

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
 * Génération du zone procéduralement
 * @param type Type de la zone (1, 2, 3)
 * @return La zone généré procéduralement
 */
Zone* generateZone(TypeZone type);

/**
 * Place le joueur sur sa case de départ (exclusivement ZONE 1)
 * @param zone La zone
 */
void placePlayer(Zone* zone);

/**
 * Affiche une zone
 * @param zone La zone
 */
void printZone(Zone* zone);

/**
 * Libère la zone de la mémoire
 * @param zone La zone
 */
void freeZone(Zone* zone);

/**
 * Génère le ou les portails de changement de zone sur une zone
 * @param zone La zone
 */
void generatePortail(Zone* zone);

/**
 * Retourne l'ID de la plante en fonction du type de zone
 * @param type Le type de la zone
 * @return L'ID de la plante
 */
Element getElementPlant(TypeZone type);

/**
 * Retourne l'ID du bois en fonction du type de zone
 * @param type Le type de la zone
 * @return L'ID du bois
 */
Element getElementWood(TypeZone type);

/**
 * Retourne l'ID de la pierre en fonction du type de zone
 * @param type Le type de la zone
 * @return L'ID de la pierre
 */
Element getElementRock(TypeZone type);

/**
 * Retourne l'ID d'une ressource aléatoirement en fonction du type de zone
 * @param type Le type de la zone
 * @return L'ID d'une ressource aléatoire
 */
Element getRandomResource(TypeZone typeZone);

/**
 * Retourne l'ID d'un monstre en fonction du type de zone
 * @param type Le type de la zone
 * @return L'ID d'un monstre aléatoire
 */
int getRandomMonster(TypeZone typeZone);

/**
 * Fonction de test qui affiche une zone
 * @param zone La zone
 */
void printZoneDebug(Zone* zone);

/**
 * Spécifie si cette ID correspond à une ressource ou non
 * @param id ID à vérifier
 * @return Si c'est une ressource ou non
 */
int isResource(int id);

/**
 * Spécifie si cette ID correspond à un monstre ou non
 * @param id ID à vérifier
 * @return Si c'est un monstre ou non
 */
int isMonster(int id);

/**
 * Retourne l'ID  de de la ressource correspondant à l'élément miné
 * @param element Element miné
 * @return L'ID de la ressource
 */
int getIdResource(Element element);

/**
 * Spécifie si cette ID correspond à un portail ou non
 * @param id ID à vérifier
 * @return Si c'est un portail ou non
 */
int isPortal(int id);

/**
 * Récupération de la position du portail dans une zone
 * @param zone La zone
 * @param portal Le portail recherché
 * @return La position du portail
 */
Position getPositionPortal(Zone zone, Element portal);

/**
 * Place le boss de fin sur sa case (exclusivement ZONE 3)
 * @param zone La zone
 */
void placeFinalBoss(Zone* zone);

#endif //MALLOCWORLD_ZONE_H
