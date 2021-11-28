/*
**  Filename : pnj.c
**
**  Made by : Owen ANCELOT & Elsa FIRMIN
**
**  Description : Manage pnj
*/

#include "../../header/agent/pnj.h"
#include "../../header/inventory/storage.h"

void stockPNJ(Player* player, Game* game){
    stockInventory(player, game);
}

void changeQuantityPNJ(Storage* storage, int id, int quanity, Game* game){
    changeQuantityStorage(storage, id, quanity, game);
}