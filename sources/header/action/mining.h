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

void mining(Game* game, int id);

int isIdTool_Plant(Element element, int id);

int isIdTool_Rock(Element element, int id);

int isIdTool_Wood(Element element, int id);

int isIdTool(Element element, int id);

float getUsury(Element element);

#endif //MALLOCWORLD_MINING_H
