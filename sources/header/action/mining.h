//
// Created by Admin on 09/11/2021.
//

#ifndef MALLOCWORLD_MINING_H
#define MALLOCWORLD_MINING_H

#include "../game.h"

void mining(Game* game, int id);

int isIdTool_Plant(Element element, int id);

int isIdTool_Rock(Element element, int id);

int isIdTool_Wood(Element element, int id);

int isIdTool(Element element, int id);

float getUsury(Element element);

#endif //MALLOCWORLD_MINING_H
