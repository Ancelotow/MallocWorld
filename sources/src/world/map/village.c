/*
**  Filename : forest.c
**
**  Made by : Owen ANCELOT
**
**  Description : Create a type's zone "Village" when the world is generated.
*/

#include "../../../header/global.h"

const int HOUSE_HEIGHT = 7;
const int HOUSE_WIDTH = 7;

/**
 * Génération des ressources dans le Village
 * @param zone La zone de type "Village"
 */
void generateResource_Village(Zone* zone){
    int random;
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            if(zone->map[i][j] == 0){
                random = getRandomNumber(0) % 10; // 10% de chance de générer une ressource
                if(random == 0){
                    zone->map[i][j] = getRandomResource(zone->type);
                }
            }
        }
    }
}

/**
 * Génération d'une maison
 * @param zone Le type de la zone
 * @param row La ligne
 * @param column La colonne
 * @param isPnjHouse Si c'est une maison pour un PNJ
 */
void generateHouse(Zone* zone, int row, int column, int isPnjHouse){
    for (int i = 1; i < HOUSE_HEIGHT - 1; i++) {  // Génération des 2 murs verticaux
        zone->map[row + i][column + 1] = IMPASSABLE;
        zone->map[row + i][column + HOUSE_WIDTH - 2] = IMPASSABLE;
    }
    for (int i = 2; i < HOUSE_WIDTH - 2; i++) { // Génération des 2 murs horizontaux
        zone->map[row + 1][column + i] = IMPASSABLE;
        if (HOUSE_WIDTH / 2 != i) { // Création de la porte d'entrée pour la maison
            zone->map[row + HOUSE_HEIGHT - 2][column + i] = IMPASSABLE;
        }
    }
    if(isPnjHouse){ // Génère le PNJ si c'est une maison pour un PNJ
        zone->map[row + HOUSE_HEIGHT / 2][column + HOUSE_WIDTH / 2] = PNJ;
    } else{
        int random = getRandomNumber(0) % 2;
        if(random){ // 50% de chance de générer 2 monstres dans la maison (chacun dans un coin de la maison)
            zone->map[row + HOUSE_HEIGHT - 3][column + HOUSE_WIDTH - 3] = getRandomMonster(zone->type);
            zone->map[row + 2][column + 2] = getRandomMonster(zone->type);
        } else { // 50% de chance de générer 1 monstre dans la maison (au centre de la maison)
            zone->map[row + HOUSE_HEIGHT / 2][column + HOUSE_WIDTH / 2] = getRandomMonster(zone->type);
        }
    }
}

/**
 * Génération d'une zone de type "Village"
 * @param zone La zone vide
 */
void generateVillage(Zone* zone){
    int pnjGenerated = 0;
    while (!pnjGenerated){ // On recommence toute la génération si le PNJ n'as pas été généré
        for(int i=0; i < zone->row; i += HOUSE_HEIGHT){ // Les cases pour les maisons font 7 de hauteur
            for(int j=0; j < zone->column; j += HOUSE_WIDTH){ // Les cases pour les maisons font 7 de largeur
                if(i + HOUSE_HEIGHT <= zone->row && j + HOUSE_WIDTH <= zone->column){ // S'il y a la place de générer une maison
                    if(getRandomNumber(0) % 2 && !pnjGenerated){ //  50% de chance de générer un PNJ
                        generateHouse(zone, i, j, 1);
                        pnjGenerated = 1;
                    } else {
                        generateHouse(zone, i, j, 0);
                    }
                }
            }
        }
    }
    generatePortail(zone); // Génération du ou des portail (en fonction du TypeZone)
    generateResource_Village(zone); // Génération des ressources dans le village
}



