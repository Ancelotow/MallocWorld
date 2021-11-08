#include "../header/game.h"
#include "../header/world/world.h"
#include "../header/position.h"
#include "../header/global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_SAVE "../resources/save/save.txt"

#define CMD_CREATE_GAME "create"
#define CMD_LOAD_GAME "load [save_file]"

#define CMD_SAVE 'l'
#define CMD_INVENTORY 'i'
#define CMD_UP 'z'
#define CMD_DOWN 's'
#define CMD_LEFT 'q'
#define CMD_RIGHT 'd'
#define CMD_MAP 'm'

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
    printf("\n");
    printZone(game->world->world[game->position->zone]);
    do{
        printAction();
        printf("\nQuelle action souhaitez-vous faire ?");
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        if(input == CMD_SAVE){
            saveGame(*game);
            continueGame = 0;
        } else if(input == CMD_INVENTORY) {
            printInventoryPlayer(*game->player, 0);
        } else if(input == CMD_MAP) {
            printZone(game->world->world[game->position->zone]);
        } else {
            actionMove(input, game);
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

void actionMove(char move, Game* game){
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 0;
    Position newPosition = *game->position;
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
    moves(newPosition, game);
}

void moves(Position newPosition, Game* game){
    int id =  game->world->world[newPosition.zone]->map[newPosition.y][newPosition.x];
    if(id == IMPASSABLE){
        printf("\n\n================================\n");
        printf("|| Impossible de passer ici ! ||\n");
        printf("================================\n\n");
    } else if(isResource(id)){
        mining(game, id);
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    } else if(isMonster(id)){
        // TODO: Combat d'un monstre
    } else{
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
        printf("\n");
        printZone(game->world->world[game->position->zone]);
    }

}

void mining(Game* game, int id){
    int isUsed = useToolToMining(id, game->player);
    if(isUsed){
        printf("\n\n================================\n");
        printf("|| Ressource recoltee !      ||\n");
        printf("================================\n\n");
        int nbResources = (getRandomNumber(0) % 4) + 1;
        Inventory* inventory;
        for(int i = 0; i < nbResources; i++){
            inventory = getInventoryFromId(getIdResource(id));
            appendInventory(game->player, inventory);
        }
    } else {
        printf("\n\n==========================================\n");
        printf("|| Vous n'avez pas l'outil adequat      ||\n");
        printf("==========================================\n\n");
    }
}

void freeGame(Game* game){
    freeWorld(game->world);
    freePosition(game->position);
    freePlayer(game->player);
    free(game);
}

void saveGame(Game game){
    FILE* file = fopen(PATH_SAVE, "w+");
    if(file != NULL){
        saveWorld(file, *game.world);
        savePlayer(file, *game.player);
        fclose(file);
    } else{
        printf("NULLkllll");
    }
}
