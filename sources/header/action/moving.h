//
// Created by Admin on 27/11/2021.
//

#ifndef MALLOCWORLD_MOVING_H
#define MALLOCWORLD_MOVING_H

int isFreeCase(Position position, World world);

void actionMove(Position position, Game* game);

void changeZone(Game* game, Element portal);

#endif //MALLOCWORLD_MOVING_H
