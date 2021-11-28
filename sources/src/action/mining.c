/*
**  Filename : mining.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the mining's action when player meet a mining a resource in the world
*/


#include "../../header/global.h"

void mining(Game *game, int id, Position position) {
    int isUsed = useToolToMining(id, game->player); //cherche outil de minage
    if (isUsed) {
        int isCollect = 0;
        int isAppend;
        int nbResources = (getRandomNumber(0) % 4) + 1;
        Inventory *inventory;
        for (int i = 0; i < nbResources; i++) {
            inventory = getInventoryFromId(getIdResource(id));  //regarde si sa correspond a la ressource
            isAppend = appendInventory(game->player, inventory);
            if (isAppend) {
                isCollect = 1;  //la mine et l'ajoute
            }
        }
        if(isCollect) {
            Position* posResource = createPositionFromExisting(position);
            printMessage("Ressource recoltee !");
            if(game->respawn == NULL){
                game->respawn = createRespawn(id, posResource);     //pour repop
            } else {
                appendRespawn(game->respawn, id, posResource);
            }
        } else {
            printMessage("Votre inventaire est plein");
        }
    } else {
        printMessage("Vous n'avez pas l'outil adequat");
    }
}

int isIdTool_Plant(Element element, int id) {
    switch (element) {
        case PLANT_ZONE_1:
            if (id == 3 || id == 13 || id == 24) {
                return 1;
            } else {
                return 0;
            }

        case PLANT_ZONE_2:
            if (id == 13 || id == 24) {
                return 1;
            } else {
                return 0;
            }

        case PLANT_ZONE_3:
            if (id == 24) {
                return 1;
            } else {
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool_Rock(Element element, int id) {
    switch (element) {
        case ROCK_ZONE_1:
            if (id == 2 || id == 12 || id == 23) {
                return 1;
            } else {
                return 0;
            }

        case ROCK_ZONE_2:
            if (id == 12 || id == 23) {
                return 1;
            } else {
                return 0;
            }

        case ROCK_ZONE_3:
            if (id == 23) {
                return 1;
            } else {
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool_Wood(Element element, int id) {
    switch (element) {
        case WOOD_ZONE_1:
            if (id == 4 || id == 14 || id == 25) {
                return 1;
            } else {
                return 0;
            }

        case WOOD_ZONE_2:
            if (id == 14 || id == 25) {
                return 1;
            } else {
                return 0;
            }

        case WOOD_ZONE_3:
            if (id == 25) {
                return 1;
            } else {
                return 0;
            }

        default:
            return 0;
    }
}

int isIdTool(Element element, int id) {
    switch (element) {
        case PLANT_ZONE_1:
        case PLANT_ZONE_2:
        case PLANT_ZONE_3:
            return isIdTool_Plant(element, id);

        case WOOD_ZONE_1:
        case WOOD_ZONE_2:
        case WOOD_ZONE_3:
            return isIdTool_Wood(element, id);

        case ROCK_ZONE_1:
        case ROCK_ZONE_2:
        case ROCK_ZONE_3:
            return isIdTool_Rock(element, id);

        default:
            return 0;
    }
}

float getUsury(Element element) {
    switch (element) {
        case PLANT_ZONE_1:
        case WOOD_ZONE_1:
        case ROCK_ZONE_1:
            return 0.10f;

        case PLANT_ZONE_2:
        case WOOD_ZONE_2:
        case ROCK_ZONE_2:
            return 0.20f;

        case PLANT_ZONE_3:
        case WOOD_ZONE_3:
        case ROCK_ZONE_3:
            return 0.40f;

        default:
            return 0.00f;
    }
}

