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
#define CMD_QUIT_GAME "quit"

#define CMD_SAVE 'l'
#define CMD_SAVE_QUIT 'p'
#define CMD_SHOW_PLAYER 'j'
#define CMD_QUIT_WITHOUT_SAVE 'c'
#define CMD_INVENTORY 'i'
#define CMD_UP 'z'
#define CMD_DOWN 's'
#define CMD_LEFT 'q'
#define CMD_RIGHT 'd'
#define CMD_MAP 'm'

/**
 * Lance le jeu
 */
void runGame() {
    char input[50];
    printf("\nSouhaitez-vous creer (%s) ou quitter (%s) partie ?", CMD_CREATE_GAME, CMD_QUIT_GAME);
    scanf("%s", input);
    printf("\n");
    if (!strcmp(CMD_CREATE_GAME, input)) {
        Game *game = createVoidGame();
        play(game);
    } else if (!strcmp(CMD_LOAD_GAME, input)) {
        printf("Chargement de la partie");
    } else if (!strcmp(CMD_QUIT_GAME, input)) {
        return;
    } else {
        printf("Commande inconnue\n");
        runGame();
    }
}

/**
 * Intéraction avec le joueur pour qu'il puisse jouer sont personnage
 * @param game le jeu
 */
void play(Game *game) {
    int continueGame = 1;
    char input;
    printf("\n");
    printZone(game->world->world[game->position->zone]);
    do {
        printAction();
        printf("\nQuelle action souhaitez-vous faire ?");
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        scanf("%c", &input); // TODO: Pourquoi il faut 2 scanf ?
        continueGame = executeActionPlayer(input, game);
    } while (continueGame);
    freeGame(game);
    runGame();
}

/**
 * Execute l'action du joueur
 * @param action L'action du joueur
 * @param game le jeu
 * @return Si le jeu continue ou non
 */
int executeActionPlayer(char action, Game* game){
    switch(action){
        case CMD_SAVE:
            respawnAllElement(game);
            saveGame(*game);
            return 1;

        case CMD_INVENTORY:
            printInventoryPlayer(*game->player, 0);
            return 1;

        case CMD_MAP:
            printZone(game->world->world[game->position->zone]);
            return 1;

        case CMD_SAVE_QUIT:
            respawnAllElement(game);
            saveGame(*game);
            return 0;

        case CMD_QUIT_WITHOUT_SAVE:
            return 0;

        case CMD_SHOW_PLAYER:
            printPlayer(*game->player);
            return 1;

        case CMD_DOWN:
        case CMD_UP:
        case CMD_RIGHT:
        case CMD_LEFT:
            movePlayer(action, game);
            if (game->player->currentHp <= 0) {
                return 0;
            } else {
                return 1;
            }

        default:
            printMessage("Commande inconnue.");
            return 1;

    }
}

/**
 * Création du jeu à partir de zéro
 * @return Le jeu
 */
Game *createVoidGame() {
    Game *game = malloc(sizeof(Game));
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
void movePlayer(char move, Game *game) {
    Position newPosition = *game->position;
    switch (move) {
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
    if (!isFreeCase(newPosition, *game->world)) {
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
void executeAction(Position newPosition, Game *game) {
    int id = game->world->world[newPosition.zone]->map[newPosition.y][newPosition.x];
    if (isResource(id)) {
        mining(game, id, newPosition);
        game->position->x = newPosition.x;
        game->position->y = newPosition.y;
        game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    } else if (isMonster(id)) {
        startFight(id, game, newPosition);
    } else if (isPortal(id)) {
        changeZone(game, id);
    } else if (id == PNJ) {
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
void freeGame(Game *game) {
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
void printMessage(char *message) {
    printf("\n\n============================================\n");
    printf("|| %s\n", message);
    printf("============================================\n\n");
}
