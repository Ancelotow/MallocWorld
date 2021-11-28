/*
**  Filename : mining.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'mining.c'. It's used for mining's action
*/

#ifndef MALLOCWORLD_MINING_H
#define MALLOCWORLD_MINING_H

typedef enum Element Element;
typedef struct Game Game;

/**
 * Permet de miner une ressource
 * @param game le jeu
 * @param id L'ID de la ressource
 * @param position La position de la ressource
 */
void mining(Game* game, int id, Position position);

/**
 * Spécifie si l'ID de l'outil est compatible ou pas avec la plante minée
 * @param element La plante minée
 * @param id l'ID de l'outil
 * @return Si l'ID de l'outil est compatible
 */
int isIdTool_Plant(Element element, int id);

/**
 * Spécifie si l'ID de l'outil est compatible ou pas avec la pierre minée
 * @param element La pierre minée
 * @param id l'ID de l'outil
 * @return Si l'ID de l'outil est compatible
 */
int isIdTool_Rock(Element element, int id);

/**
 * Spécifie si l'ID de l'outil est compatible ou pas avec le bois minée
 * @param element Le bois minée
 * @param id l'ID de l'outil
 * @return Si l'ID de l'outil est compatible
 */
int isIdTool_Wood(Element element, int id);

/**
 * Spécifie si l'ID de l'outil est compatible ou pas avec la ressource minée
 * @param element Le ressource minée
 * @param id l'ID de l'outil
 * @return Si l'ID de l'outil est compatible
 */
int isIdTool(Element element, int id);

/**
 * Récupération de l'usure que devra subir l'outil de minage en fonction de l'élément miné
 * @param element L'élément miné
 * @return L'usure subi
 */
float getUsury(Element element);

#endif //MALLOCWORLD_MINING_H