/*
**  Filename : game.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'game.c'. Manage interactions between player/game and the printing.
*/

#ifndef MALLOCWORLD_GAME_H
#define MALLOCWORLD_GAME_H

typedef struct World World;
typedef struct Player Player;
typedef struct Position Position;
typedef struct Respawn Respawn;
typedef struct Storage Storage;


typedef struct Game{
    World* world;
    Player* player;
    Position* position;
    Respawn* respawn;
    Storage* storage;
} Game;

/**
 * Lance le jeu
 */
void runGame();

/**
 * Création du jeu à partir de zéro
 * @return Le jeu
 */
Game* createVoidGame();

/**
 * Intéraction avec le joueur pour qu'il puisse jouer sont personnage
 * @param game le jeu
 */
void play(Game* game);

/**
 * Prévoie le déplacement du joueur pour savoir s'il doit miner, se battre, etc...
 * @param move Direction de déplacement
 * @param game Le jeu
 */
void movePlayer(char move, Game* game);

/**
 * Execute l'action en fonction de la case où veux aller le joueur
 * @param newPosition La nouvelle postion (la case que cible le joueur)
 * @param game Le jeu
 */
void executeAction(Position newPosition, Game* game);

/**
 * Libère le jeu de la mémoire
 * @param game Le jeu
 */
void freeGame(Game* game);

/**
 * Affiche un message
 * @param message Le message
 */
void printMessage(char* message);

#endif //MALLOCWORLD_GAME_H
