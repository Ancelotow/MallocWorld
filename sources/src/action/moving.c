/*
**  Filename : moving.c
**
**  Made by : Owen ANCELOT
**
**  Description : Move the player, change zone if player going to portal.
*/

#include "../../header/global.h"

int isFreeCase(Position newPosition, World world){
    if(newPosition.y >= world.world[newPosition.zone]->row || newPosition.y < 0){
        return 0;
    } else if(newPosition.x >= world.world[newPosition.zone]->column || newPosition.x < 0){
        return 0;
    } else if(world.world[newPosition.zone]->map[newPosition.y][newPosition.x] == IMPASSABLE){
        return 0;
    } else {
        return 1;
    }
}

void actionMove(Position position, Game* game){
    game->position->x = position.x;
    game->position->y = position.y;
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    printf("\n");
    printZone(game->world->world[game->position->zone]);
}

void changeZone(Game* game, Element portal){
    Position posPortal = *game->position;
    int zoneSearch = 0;
    if(portal == PORTAL_ZONE_2){
        if(game->player->level < 3){
            printMessage("Niveau 3 requis.");
        } else {
            zoneSearch = (game->position->zone == 0) ? 1 : 0;
            posPortal = getPositionPortal(*game->world->world[zoneSearch], PORTAL_ZONE_2);
            appendRespawn(game->respawn, -2, createPositionFromExisting(posPortal));
        }
    } else if(portal == PORTAL_ZONE_3){
        if(game->player->level < 7){
            printMessage("Niveau 7 requis.");
        } else {
            zoneSearch = (game->position->zone == 1) ? 2 : 1;
            posPortal = getPositionPortal(*game->world->world[zoneSearch], PORTAL_ZONE_3);
            appendRespawn(game->respawn, PORTAL_ZONE_3, createPositionFromExisting(posPortal));
        }
    }
    game->position->x = posPortal.x;
    game->position->y = posPortal.y;
    game->position->zone = posPortal.zone;
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    printZone(game->world->world[game->position->zone]);
}