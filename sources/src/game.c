#include "../header/game.h"
#include "../header/world.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_CREATE_GAME "create"
#define CMD_LOAD_GAME "load [save_file]"

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

void createVoidPartie(){
    printf("Creation de la partie...\n");
    World* world = generateWorld();
    printf("Partie cree avec succes !\n\n");
    printZone(world->originalWorld[0]);
}