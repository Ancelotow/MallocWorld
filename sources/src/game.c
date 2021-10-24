#include "../header/game.h"
#include "../header/world.h"
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
        createVoidPartie();
    } else if(!strcmp(CMD_LOAD_GAME, input)){
        printf("Chargement de la partie");
    } else{
        printf("Commande inconnue\n");
        runGame();
    }
}

void printAction(){
    printf("====================================  ACTION  =====================================\n");
    printf("||                                      ||                                       ||\n");
    printf("||  [Z] -> deplacement haut             ||   [B] -> retour au menu principal     ||\n");
    printf("||  [Q] -> deplacement gauche           ||   [L] -> sauvegarde la partie         ||\n");
    printf("||  [S] -> deplacement bas              ||   [P] -> sauvegarder et quitter       ||\n");
    printf("||  [D] -> deplacement droite           ||   [C] -> quitter sans sauvegarder     ||\n");
    printf("||  [I] -> regader mon inventaire       ||                                       ||\n");
    printf("||                                      ||                                       ||\n");
    printf("===================================================================================\n");
}



void play(World* world){
    int continueGame = 1;
    char input;
    do{
        printf("\n");
        printZone(world->originalWorld[0]);
        printAction();
        printf("\nQuelle action souhaitez-vous faire ?");
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        if(input == CMD_SAVE){
            continueGame = 0;
        }
    } while(continueGame);
    freeWorld(world);
}

void createVoidPartie(){
    printf("Creation de la partie...\n");
    World* world = generateWorld();
    printf("Partie cree avec succes !\n\n");
    play(world);
}