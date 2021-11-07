#include "../header/game.h"
#include "../header/world.h"
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
        createVoidGame();
    } else if(!strcmp(CMD_LOAD_GAME, input)){
        printf("Chargement de la partie");
    } else{
        printf("Commande inconnue\n");
        runGame();
    }
}

void play(World* world){
    int continueGame = 1;
    char input;
    Position* position = seekPlayer(*world);
    do{
        printf("\n");
        printZone(world->world[0]);
        printAction();
        printf("\nQuelle action souhaitez-vous faire ?");
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        if(input == CMD_SAVE){
            continueGame = 0;
        } else {
            actionMove(input, position, world);
        }
    } while(continueGame);
    freeWorld(world);
    freePosition(position);
}

void createVoidGame(){

    printf("Creation de la partie...\n");
    World* world = generateWorld();
    printf("Partie cree avec succes !\n\n");
    play(world);
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
