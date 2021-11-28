/*
**  Filename : pnj.c
**
**  Made by : Elsa FIRMIN
**
**  Description : Manage action with PNJ (storage, repair, craft)
*/

#include "../../header/global.h"

#define CMD_REPAIR 'r'
#define CMD_STORE 'a'
#define CMD_QUIT 'q'
#define CMD_RETRIEVE 't'
#define CMD_SEE_COFFER 's'
#define CMD_CRAFT 'c'

/**
 * Gère les intéraction du joueur avec le PNJ
 * @param game Le jeu
 */
void interactionWithPnj(Game* game){
    int continueInteraction = 1;
    char chr;
    do {
        printActionPNJ();
        printf("\nQue souhaitez-vous faire ?");
        scanf("%c", &chr);
        scanf("%c", &chr);
        continueInteraction = actionPNJ(chr, game);
    } while(continueInteraction);
}

/**
 * Exécute l'action voulu par le joueur
 * @param action Action
 * @param game Le jeu
 * @return Si on quitte le PNJ ou non
 */
int actionPNJ(char action, Game* game){
    switch(action){
        case CMD_CRAFT:
            actionCraft(game);
            return 1;

        case CMD_REPAIR:
            repairPlayerInventory(game->player);
            return 1;

        case CMD_STORE:
            stockStorage(game);
            return 1;

        case CMD_SEE_COFFER:
            printStorage(game->storage);
            return 1;

        case CMD_RETRIEVE:
            retrieveStorage(game);
            return 1;

        case CMD_QUIT:
            return 0;

        default:
            printMessage("Commande inconnue.");
            return 1;
    }
}

/**
 * Répare tout l'inventaire du joueur
 * @param player Le joueur
 */
void repairPlayerInventory(Player* player){
    for(int i = 0; i < player->sizeInventory; i++){
        for(int j = 0; j < player->inventory[i]->length; j++){
            player->inventory[i]->inventory[j]->durability = player->inventory[i]->inventory[j]->durabilityMax;
        }
    }
}

/**
 * Stocke de l'inventaire dans le stockage
 * @param game Le jeu
 */
void stockStorage(Game* game){
    int continueInteraction = 1;
    char input[50];
    char inputQty[50];
    do {
        printInventoryPlayer(*game->player, 0);
        printf("\nSaississez l'ID de l'inventaire que vous souhaitez stocker (ou [Q] pour quitter) : ");
        scanf("%s", input);
        if(!strcmp(input, "q")){
            continueInteraction = 0;
        } else {
            printf("\nQuelle quantitee ? ");
            scanf("%s", inputQty);
            storeIntoStorage(game, atoi(input), atoi(inputQty));
        }
    } while(continueInteraction);
}

/**
 * Récupère un inventaire du stockage
 * @param game Le jeu
 */
void retrieveStorage(Game* game){
    int continueInteraction = 1;
    char input[50];
    char inputQty[50];
    do {
        printStorage(game->storage);
        printf("\nSaississez l'ID de l'inventaire que vous souhaitez recuperer (ou [Q] pour quitter) : ");
        scanf("%s", input);
        if(!strcmp(input, "q")){
            continueInteraction = 0;
        } else {
            printf("\nQuelle quantitee ? ");
            scanf("%s", inputQty);
            retrieveFromStorage(game, atoi(input), atoi(inputQty));
        }
    } while(continueInteraction);
}

