/*
**  Filename : forest.c
**
**  Made by : Owen ANCELOT
**
**  Description : Create a type's zone "Forest" when the world is generated.
*/

#include "../../../header/global.h"

const int TREE_WIDTH = 7;
const int TREE_HEIGHT = 7;

/**
 * Génération des ressources dans la zone de type "Foret".
 * @param zone La zone
 */
void generateResource_Forest(Zone* zone){
    int random;
    for(int i=0; i < zone->row; i++){
        for(int j=0; j < zone->column; j++){
            if(zone->map[i][j] == 0){   // Génération de la ressource uniquement sur un case libre
                random = getRandomNumber(0) % 10;
                if(random == 0){   // 10% de chance de générer une ressource aléatoire
                    zone->map[i][j] = getRandomResource(zone->type);
                } else if(random < 2){ // 10% de chance de générer une plante
                    zone->map[i][j] = getElementPlant(zone->type);
                }
            }
        }
    }
}

/**
 * Génération d'un arbre (modèle 1)
 * @param zone la zone
 * @param row La ligne de départ
 * @param column La colonne de départ
 * @param isPnjTree Si cette arbre est pour un PNJ
 */
void generateTree_One(Zone* zone, int row, int column, int isPnjTree){
    int middleHeight = TREE_HEIGHT / 2; // On part du millieu pour générer l'arbre
    int middleWidth = TREE_WIDTH / 2; // On part du millieu pour générer l'arbre
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

/**
 * Génération d'un arbre (modèle 2)
 * @param zone la zone
 * @param row La ligne de départ
 * @param column La colonne de départ
 */
void generateTree_Two(Zone* zone, int row, int column){
    int monsterLeft = 3; // On doit générer 3 monstres autour de l'arbre
    int random;
    int rowStart = getRandomNumber(0) % (TREE_HEIGHT - 3); // La ligne de départ
    int columnStart = getRandomNumber(0) % (TREE_HEIGHT - 3); // La colonne de départ
    for(int j=0; j < 3; j++){ // Génération de l'arbre (qui sera un carré de 3x3)
        zone->map[row + rowStart + j][column + columnStart] = IMPASSABLE;
        zone->map[row + rowStart + j][column + columnStart + 1] = IMPASSABLE;
        zone->map[row + rowStart + j][column + columnStart + 2] = IMPASSABLE;
    }
    int index = 0;
    while (monsterLeft > 0){ // tant que les 3 monstres n'ont pas été générés
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

/**
 * Génération d'une zone de type "Foret"
 * @param zone La zone vide
 */
void generateForest(Zone* zone){
    int pnjGenerated = 0;
    while (!pnjGenerated) { // On recommence toute la génération si le PNJ n'as pas été généré
        for (int i = 0; i < zone->row; i += TREE_HEIGHT) { // Les cases pour les arbres font 7 de hauteur
            for (int j = 0; j < zone->column; j += TREE_WIDTH) { // Les cases pour les arbres font 7 de largeur
                if (i + TREE_HEIGHT <= zone->row && j + TREE_WIDTH <= zone->column) { // S'il y a la place de générer un arbre
                    if (getRandomNumber(0) % 2) { //  50% de chance de générer un PNJ
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
    generatePortail(zone); // Génération du ou des portail (en fonction du TypeZone)
    generateResource_Forest(zone); // Génération des ressources dans la foret
}
