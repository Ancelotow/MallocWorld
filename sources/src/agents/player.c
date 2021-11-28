/*
**  Filename : player.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the player in the game
*/

#include "../../header/global.h"

const int MAX_INVENTORY = 20;

/**
 * Création d'un joueur
 * @param currentHp Les points de vie courant du joueur
 * @param maxHp Les points de vie max du joueur
 * @param inventory L'inventaire du joueur
 * @param sizeInventory Le nombre d'inventaire du joueur
 * @param level Le niveau du joueur
 * @param xp L'expérience du joueur
 * @param xpNext L'expérience nécessaire pour changer de niveau
 * @return Le joueur
 */
Player* createPlayer(int currentHp, int maxHp, Stack** inventory, int sizeInventory, int level, int xp, int xpNext){
    Player* player = malloc(sizeof(Player));
    player->currentHp = currentHp;
    player->maxHp = maxHp;
    player->inventory = inventory;
    player->sizeInventory = sizeInventory;
    player->level = level;
    player->xp = xp;
    player->xpNext = xpNext;
    return player;
}

/**
 * Création d'un joueur de niveau 1
 * @return Le joueur
 */
Player* createPlayerLevel1(){
    int maxHp = 100;
    int currentHp = maxHp;
    Stack** stack = malloc(sizeof(Stack*) * 20); // xp = 100 pour être au level 2 puis doublé pour les autres
    stack[0] = createStackWithInventory(getInventoryFromId(1)); // Epée en bois
    stack[1] = createStackWithInventory(getInventoryFromId(2)); // Pioche en bois
    stack[2] = createStackWithInventory(getInventoryFromId(3)); // Serpe en bois
    stack[3] = createStackWithInventory(getInventoryFromId(4)); // Hache en bois
    Player* player = createPlayer(currentHp, maxHp, stack, 4, 1, 0, 100);
    return player;
}

/**
 * Ajoute un inventaire à dans l'inventaire du joueur
 * @param player Le joueur
 * @param inventory L'inventaire à ajouter
 * @return Si l'inventaire à été ajouté ou non
 */
int appendInventory(Player* player, Inventory* inventory){
    Stack* stack;
    int stackVacant = 0;
    for(int i = 0; i < player->sizeInventory; i++){
        if(player->inventory[i]->id == inventory->id && player->inventory[i]->length < player->inventory[i]->maximum){
            stack = player->inventory[i];
            stackVacant = 1;
            break;
        }
    }
    if(stackVacant){
        appendStack(inventory, stack);
        return 1;
    } else if(player->sizeInventory < 20){
        stack = createStackWithInventory(inventory);
        player->inventory[player->sizeInventory] = stack;
        player->sizeInventory += 1;
        return 1;
    } else {
        return 0;
    }
}

/**
 * Fonction de test pour afficher un joueur
 * @param player Le joueur
 */
void printPlayerDebug(Player player){
    printf("Joueur : %d/%dHP, %d/%dxp, lvl%d\n", player.currentHp, player.maxHp, player.xp, player.xpNext, player.level);
    printf("\t -- INVENTAIRE --\n");
    for(int i=0; i < player.sizeInventory; i++){
        printf("\t");
        printStackDebug(*player.inventory[i]);
        printf("\n");
    }
}

/**
 * Affiche l'inventaire du joueur
 * @param player Le joueur
 * @param type Le type d'inventaire à afficher (0 pour tout afficher)
 */
void printInventoryPlayer(Player player, InventoryType type){
    printf("======================= INVENTAIRE =======================\n");
    Inventory* inventory = NULL;
    for(int i = 0; i < player.sizeInventory; i++){
        if(type == 0){
            printStack(*player.inventory[i]);
        } else {
           inventory = getInventoryFromId(player.inventory[i]->id);
           if(inventory->type == type){
               printStack(*player.inventory[i]);
           }
        }
    }
    if(inventory != NULL){
        freeInventory(inventory);
    }
    printf("==========================================================\n\n");
}

/**
 * Récupération du nombre d'inventaire pour un type donné
 * @param player Le joueur
 * @param type Le type d'inventaire
 * @return Le nombre d'inventaire
 */
int getLengthInventoryType(Player player, InventoryType type){
    Inventory* inventory = NULL;
    int length = 0;
    for(int i = 0; i < player.sizeInventory; i++){
        if(type == 0){
            length += 1;
        } else {
            inventory = getInventoryFromId(player.inventory[i]->id);
            if(inventory->type == type){
                length += 1;
            }
        }
    }
    if(inventory != NULL){
        freeInventory(inventory);
    }
    return length;
}

/**
 * Récupération de la quantité d'un objet donné
 * @param player Le joueur
 * @param idInventory L'ID de l'inventaire
 * @return La quantité
 */
int getQuantityInventory(Player player, int idInventory){
    int quantity = 0;
    for(int i = 0; i < player.sizeInventory; i++){
        if(player.inventory[i]->id == idInventory){
            quantity += player.inventory[i]->length;
        }
    }
    return quantity;
}

/**
 * Libère le joueur de la mémoire
 * @param player Le joueur
 */
void freePlayer(Player* player){
    for(int i=0; i < player->sizeInventory; i++){
        freeStack(player->inventory[i]);
    }
    free(player->inventory);
    free(player);
}

/**
 * Utilisation d'un outil de minage (change la durabilité)
 * @param element L'élément miné
 * @param player Le joueur
 * @return Si l'outil est utilisable ou non
 */
int useToolToMining(Element element, Player* player){
    float usury = getUsury(element);
    float newDurability;
    for(int i = 0; i < player->sizeInventory; i++){
        if(isIdTool(element, player->inventory[i]->id)){
            for(int j = 0; j < player->inventory[i]->length; j++){
                newDurability = player->inventory[i]->inventory[j]->durability - (usury * player->inventory[i]->inventory[j]->durabilityMax);
                if(newDurability > 0){
                    player->inventory[i]->inventory[j]->durability = newDurability;
                    return 1;
                }
            }
        }
    }
    return 0;
}

/**
 * Gain d'expérience pour le joueur
 * @param player Le joueur
 * @param experience L'expérience gagné
 */
void gainExperience(Player* player, int experience){
    player->xp += experience;
    if(player->xp >= player->xpNext){
        printMessage("Vous avez gagne un niveau !");
        player->xp = player->xpNext - player->xp;
        player->xpNext *= 2;
        player->level += 1;
        if(player->level < 6 ){
            player->maxHp += 10;
        } else if (player->level >= 6 && player->level <= 8){
            player->maxHp += 50;
        } else {
            player->maxHp += 75;
        }
        player->currentHp = player->maxHp;
    }
}

/**
 * Supprime un nombre d'objet donné de l'inventaire du joueur
 * @param player Le joueur
 * @param id L'ID de l'inventaire
 * @param quantity La quantité à supprimer
 */
void removeQuantityInventory(Player* player, int id, int quantity){
    for(int i = 0; i < player->sizeInventory; i++){
        if(player->inventory[i]->id == id){
            for(int j = player->inventory[i]->length - 1; j >= 0; j--){
                deleteStack(j, player->inventory[i]);
                quantity -= 1;
                if(quantity <= 0){
                    break;
                }
            }
            if(player->inventory[i]->length <= 0){
                deleteInventory(player, i);
                i = 0;
            }
        }
        if(quantity <= 0){
            return;
        }
    }
}

/**
 * Suppression d'un inventaire à un index donné
 * @param player Le joueur
 * @param index L'index à supprimer
 */
void deleteInventory(Player* player, int index){
    if(player->sizeInventory > 0 && index < player->sizeInventory){
        freeStack(player->inventory[index]);
        for (int i = index + 1; i < player->sizeInventory; i++) {
            player->inventory[i - 1] = player->inventory[i];
        }
        player->sizeInventory -= 1;
    }
}

/**
 * Affiche les informations du joueur
 * @param player Le joueur
 */
void printPlayer(Player player){
    printf("\n============ JOUEUR ============\n");
    printf("Niveau : %d\n", player.level);
    printf("Experience : %d/%d\n", player.xp, player.xpNext);
    printf("PV : %d/%d\n", player.currentHp, player.maxHp);
    printf("================================\n\n");
}



