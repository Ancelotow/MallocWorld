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

/**
 * La soumission des dégâts du monstre au joueur
 * @param monster Le monstre
 * @param game Le jeu
 * @param armor L'armure du joueur
 * @return Si le joueur est mort ou en vie
 */
int sufferDamage(Monster* monster, Game* game, Inventory* armor);

#endif //MALLOCWORLD_FIGHT_H
