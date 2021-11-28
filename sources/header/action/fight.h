/*
**  Filename : fight.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'action.c'. It's used for fight's action
*/

#ifndef MALLOCWORLD_FIGHT_H
#define MALLOCWORLD_FIGHT_H

/**
 * Commence le combat contre le monstre
 * @param id L'ID du monstre
 * @param game Le jeu
 * @param position La position du monstre
 */
void startFight(int id, Game* game, Position position);

#endif //MALLOCWORLD_FIGHT_H
