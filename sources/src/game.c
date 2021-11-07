#include "../header/game.h"
#include "../header/world/world.h"
#include "../header/position.h"
#include "../header/global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_CREATE_GAME "create"
#define CMD_LOAD_GAME "load [save_file]"

#define CMD_SAVE 'l'
#define CMD_UP 'z'
#define CMD_DOWN 's'
#define CMD_LEFT 'q'
#define CMD_RIGHT 'd'

void runGame(){
    char input[50];
    printf("\nSouhaitez-vous creer (%s) ou charger (%s) une partie ?", CMD_CREATE_GAME, CMD_LOAD_GAME);
    scanf("%s", input);
    printf("\n");
    if(!strcmp(CMD_CREATE_GAME, input)){
        Game* game = createVoidGame();
        play(game);
    } else if(!strcmp(CMD_LOAD_GAME, input)){
        printf("Chargement de la partie");
    } else{
        printf("Commande inconnue\n");
        runGame();
    }
}

void play(Game* game){
    int continueGame = 1;
    char input;
    do{
        printf("\n");
        printZone(game->world->world[0]);
        printAction();
        printf("\nQuelle action souhaitez-vous faire ?");
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        if(input == CMD_SAVE){
            continueGame = 0;
        } else {
            actionMove(input, game->position, game->world);
        }
    } while(continueGame);
    freeGame(game);
}

Game* createVoidGame(){
    Game* game = malloc(sizeof(Game));
    game->world = generateWorld();
    game->player = createPlayerLevel1();
    game->position = seekPlayer(*game->world);
    game->respawn = NULL;
    game->storage = NULL;
    return game;
}

void actionMove(char move, Position* position, World* world){
    world->world[position->zone]->map[position->y][position->x] = 0;
    Position newPosition = *position;
    switch(move){
        case CMD_DOWN:
            newPosition.y += 1;
            break;

        case CMD_UP:
            newPosition.y -= 1;
            break;

        case CMD_RIGHT:
            newPosition.x += 1;
            break;

        case CMD_LEFT:
            newPosition.x -= 1;
            break;
    }
    moves(newPosition, position, world);
}

void moves(Position newPosition, Position* currentPos, World* world){
    if(world->world[newPosition.zone]->map[newPosition.y][newPosition.x] == -1){
        printf("\n\n================================\n");
        printf("|| Impossible de passer ici ! ||\n");
        printf("================================\n\n");
    } else{
        currentPos->x = newPosition.x;
        currentPos->y = newPosition.y;
    }
    world->world[currentPos->zone]->map[currentPos->y][currentPos->x] = 1;
}

void freeGame(Game* game){
    freeWorld(game->world);
    freePosition(game->position);
    freePlayer(game->player);
    free(game);
}
