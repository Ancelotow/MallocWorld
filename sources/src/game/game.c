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

/**
 * Lance le jeu
 */
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

/**
 * Intéraction avec le joueur pour qu'il puisse jouer sont personnage
 * @param game le jeu
 */
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
            respawnAllElement(game);
            saveGame(*game);
            continueGame = 0;
        } else if(input == CMD_INVENTORY) {
            printInventoryPlayer(*game->player, 0);
        } else if(input == CMD_MAP) {
            printZone(game->world->world[game->position->zone]);
        } else {
            movePlayer(input, game);
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

/**
 * Création du jeu à partir de zéro
 * @return Le jeu
 */
Game* createVoidGame(){
    Game* game = malloc(sizeof(Game));
    game->world = generateWorld();
    game->player = createPlayerLevel1();
    game->position = seekPlayer(*game->world);
    game->respawn = NULL;
    game->storage = NULL;
    return game;
}

/**
 * Prévoie le déplacement du joueur pour savoir s'il doit miner, se battre, etc...
 * @param move Direction de déplacement
 * @param game Le jeu
 */
void movePlayer(char move, Game* game){
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
    if(!isFreeCase(newPosition, *game->world)){
        printMessage("Impossible de passer ici !");
        printZone(game->world->world[game->position->zone]);
    } else {
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 0;
        executeAction(newPosition, game);
    }
}

/**
 * Execute l'action en fonction de la case où veux aller le joueur
 * @param newPosition La nouvelle postion (la case que cible le joueur)
 * @param game Le jeu
 */
void executeAction(Position newPosition, Game* game){
    int id =  game->world->world[newPosition.zone]->map[newPosition.y][newPosition.x];
    if(isResource(id)){
        mining(game, id, newPosition);
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    } else if(isMonster(id)){
        startFight(id, game, newPosition);
    } else if(isPortal(id)){
        changeZone(game, id);
    } else if(id == PNJ){
        interactionWithPnj(game);
    } else {
        actionMove(newPosition, game);
    }
    updateAllRespawn(game);
}

/**
 * Libère le jeu de la mémoire
 * @param game Le jeu
 */
void freeGame(Game* game){
    freeWorld(game->world);
    freePosition(game->position);
    freePlayer(game->player);
    freeRespawn(game->respawn);
    free(game);
}

/**
 * Affiche un message
 * @param message Le message
 */
void printMessage(char* message){
    printf("\n\n============================================\n");
    printf("|| %s\n", message);
    printf("============================================\n\n");
}
