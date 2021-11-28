#include "header/global.h"

/**
 * Fonction permettant de tester la création d'un monde
 */
void testPrintWorld(){
    World* world = generateWorld();
    printOriginalWorld(*world);
    freeWorld(world);
}

/**
 * Fonction permettant de tester la récupération d'un inventaire depuis le CSV par rapport à son ID
 * @param idInventory ID de l'inventaire
 */
void testPrintInventory(int idInventory){
    Inventory* inv = getInventoryFromId(34);
    if(inv != NULL){
        printInventory(*inv);
        freeInventory(inv);
    }
}

/**
 * Fonction permettant de tester la récupération d'un monstre depuis le CSV par rapport à son ID
 * @param idMonster ID du monstre
 */
void testPrintMonster(int idMonster){
    Monster* monster = getMonsterFromId(idMonster);
    if(monster != NULL){
        printMonster(*monster);
        freeMonster(monster);
    }
}

/**
 * Fonction permettant de tester la création du joueur ainsi que l'ajout d'inventaire.
 */
void testPrintPlayer(){
    Player* player = createPlayerLevel1();
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(15));
    appendInventory(player, getInventoryFromId(1));
    printPlayerDebug(*player);
    freePlayer(player);
}

/**
 * Fonction principale (point de lancement du jeu)
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    printTitle();
    runGame();
    return (0);
}