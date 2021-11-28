/*
**  Filename : moving.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'moving.c'. Manage move.
*/

#ifndef MALLOCWORLD_MOVING_H
#define MALLOCWORLD_MOVING_H

/**
 * Spécifie si la case est disponible ou non
 * @param newPosition
 * @param world
 * @return
 */
int isFreeCase(Position position, World world);

/**
 * Change la position du joueur suite à son déplacement
 * @param position La nouvelle position du joueur
 * @param game Le jeu
 */
void actionMove(Position position, Game* game);

/**
 * Fait changer de zone au joueur quand il passe un portail
 * @param game Le jeu
 * @param portal Le portail
 */
void changeZone(Game* game, Element portal);

#endif //MALLOCWORLD_MOVING_H
