/*
**  Filename : game.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the game, the interactions between the game and the player and also printing
*/

#include "../../header/global.h"


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
    int restart = 0;
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
            if(game->player->currentHp <= 0){
                continueGame = 0;
                restart = 1;
            }
        }
    } while(continueGame);
    freeGame(game);
    if(restart) {
        runGame();
    }
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
        printMessage("Impossible de passer ici !");
    } else if(isResource(id)){
        mining(game, id, newPosition);
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    } else if(isMonster(id)){
        startFight(id, game, newPosition);
    } else{
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
        printf("\n");
        printZone(game->world->world[game->position->zone]);
    }
    updateAllRespawn(game);
    printRespawn(game->respawn);
}

void freeGame(Game* game){
    freeWorld(game->world);
    freePosition(game->position);
    freePlayer(game->player);
    freeRespawn(game->respawn);
    free(game);
}



void printMessage(char* message){
    printf("\n\n============================================\n");
    printf("|| %s\t\t\t ||\n", message);
    printf("============================================\n\n");
}
