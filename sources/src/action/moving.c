/*
**  Filename : moving.c
**
**  Made by : Owen ANCELOT
**
**  Description : Move the player, change zone if player going to portal.
*/

#include "../../header/global.h"

/**
 * Spécifie si la case est disponible ou non
 * @param newPosition
 * @param world
 * @return
 */
int isFreeCase(Position newPosition, World world){
    if(newPosition.y >= world.world[newPosition.zone]->row || newPosition.y < 0){ // Vérifie que le joueur ne sorte pas de la carte (verticalement)
        return 0;
    } else if(newPosition.x >= world.world[newPosition.zone]->column || newPosition.x < 0){ // Vérifie que le joueur ne sorte pas de la carte (horizontalement)
        return 0;
    } else if(world.world[newPosition.zone]->map[newPosition.y][newPosition.x] == IMPASSABLE){ // vérifie que la case n'est pas un mur
        return 0;
    } else {
        return 1;
    }
}

/**
 * Change la position du joueur suite à son déplacement
 * @param position La nouvelle position du joueur
 * @param game Le jeu
 */
void actionMove(Position position, Game* game){
    game->position->x = position.x;
    game->position->y = position.y;
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    printf("\n");
    printZone(game->world->world[game->position->zone]);
}

/**
 * Fait changer de zone au joueur quand il passe un portail
 * @param game Le jeu
 * @param portal Le portail
 */
void changeZone(Game* game, Element portal){
    Position posPortal = *game->position;
    int zoneSearch = 0;
    if(portal == PORTAL_ZONE_2){
        if(game->player->level < 3){
            printMessage("Niveau 3 requis.");
        } else {
            zoneSearch = (game->position->zone == 0) ? 1 : 0;
            posPortal = getPositionPortal(*game->world->world[zoneSearch], PORTAL_ZONE_2); // Récupération de la sortie du portail
            appendRespawn(game->respawn, -2, createPositionFromExisting(posPortal)); // Le joueur arrivant sur le portail, on fera réapparaître le portail au prochain tour
        }
    } else if(portal == PORTAL_ZONE_3){
        if(game->player->level < 7){
            printMessage("Niveau 7 requis.");
        } else {
            zoneSearch = (game->position->zone == 1) ? 2 : 1;
            posPortal = getPositionPortal(*game->world->world[zoneSearch], PORTAL_ZONE_3); // Récupération de la sortie du portail
            appendRespawn(game->respawn, PORTAL_ZONE_3, createPositionFromExisting(posPortal)); // Le joueur arrivant sur le portail, on fera réapparaître le portail au prochain tour
        }
    }
    game->position->x = posPortal.x;
    game->position->y = posPortal.y;
    game->position->zone = posPortal.zone;
    game->world->world[game->position->zone]->map[game->position->y][game->position->x] = 1;
    printZone(game->world->world[game->position->zone]);
}