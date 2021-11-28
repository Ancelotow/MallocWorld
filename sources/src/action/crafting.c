/*
**  Filename : craft.c
**
**  Made by : Owen ANCELOT
**
**  Description : Craft tools, armors, weapons and potions
*/

#include "../../header/global.h"

/**
 * Gère les intéraction du joueur avec les actions de crafting
 * @param game Le jeu
 */
void actionCraft(Game* game){
    ListCraft* listCraft = getListCraftPossible(game);
    if(listCraft->length <= 0){
        printMessage("Vous ne pouvez rien crafter");
    } else {
        int continueCraft = 1;
        char input[50];
        int id;
        do{
            printListCraft(*listCraft);
            printf("Saississez l'ID de l'objet a crafter (ou [q] pour quitter) : ");
            scanf("%s", input);
            if(!strcmp(input, "q")){
                continueCraft = 0;
            } else {
                crafting(listCraft, game, atoi(input));
                freeListCraft(listCraft);
                listCraft = getListCraftPossible(game);
                if(listCraft->length <= 0){
                    printMessage("Vous ne pouvez plus crafter");
                    continueCraft = 0;
                }
            }
        } while(continueCraft);
    }
    freeListCraft(listCraft);
}

/**
 * Craft un objet
 * @param listCraft Liste des craft disponible
 * @param game Le jeu
 * @param id L'ID de l'inventaire à crafter
 */
void crafting(ListCraft* listCraft, Game* game, int id){
    Craft* craft = NULL;
    for(int i = 0; i < listCraft->length; i++){
        if(listCraft->list[i]->inventoryCraft->id == id){
            craft = listCraft->list[i];
            break;
        }
    }
    if(craft == NULL){
        printMessage("Craft inconnu");
        return;
    }
    if(craft->inventory1 > 0){
        removeQuantityInventory(game->player, craft->inventory1, craft->quantityInv1);
    }
    if(craft->inventory2 > 0){
        removeQuantityInventory(game->player, craft->inventory2, craft->quantityInv2);
    }
    appendInventory(game->player, craft->inventoryCraft);
    printInventoryPlayer(*game->player, 0);
}

/**
 * Création d'un craft
 * @param inventoryCraft L'inventaire qui sera crafter
 * @param inv1 L'élement 1 pour crafter
 * @param quantityInv1 La quantité d'élement 1 pour crafter
 * @param inv2 L'élement 2 pour crafter
 * @param quantityInv2 La quantité d'élement 2 pour crafter
 * @param zoneMin La zone minimum requis pour crafter l'objet
 * @return Le craft
 */
Craft* createCraft(Inventory* inventoryCraft, int inv1, int quantityInv1, int inv2, int quantityInv2, int zoneMin){
    Craft* craft = malloc(sizeof(Craft));
    craft->inventoryCraft = inventoryCraft;
    craft->inventory1 = inv1;
    craft->quantityInv1 = quantityInv1;
    craft->inventory2 = inv2;
    craft->quantityInv2 = quantityInv2;
    craft->zoneMin = zoneMin;
    return craft;
}

/**
 * Création d'une liste de crafts
 * @return La liste de crafts
 */
ListCraft* createListCraft(){
    ListCraft* listCraft = malloc(sizeof(ListCraft));
    listCraft->length = 0;
    listCraft->list = malloc(sizeof(Craft) * MAX_LENGTH_LIST_CRAFT);
}

/**
 * Création d'un craft en faisait des 'split' depuis une ligne d'un CSV
 * @param csv La ligne CSV
 * @return Le craft
 */
Craft* craftInventoryWithSplit(char* csv){
    char* split = strtok(csv, ";");
    int inv1 = atoi(strtok(NULL, ";"));
    int quanityInv1 = atoi(strtok(NULL, ";"));
    int inv2 = atoi(strtok(NULL, ";"));
    int quanityInv2 = atoi(strtok(NULL, ";"));
    TypeZone zoneMin = atoi(strtok(NULL, ";"));
    Inventory* inventory = getInventoryFromId(atoi(split));
    return createCraft(inventory, inv1, quanityInv1, inv2, quanityInv2, zoneMin);
}

/**
 * Affiche la liste des craft disponible
 * @param listCraft Liste des crafts
 */
void printListCraft(ListCraft listCraft){
    printf("\n\n======== OBJETS CRAFTABLE ========\n");
    for(int i = 0; i < listCraft.length; i++){
        printCraft(*listCraft.list[i]);
    }
    printf("\n\n");
}

/**
 * Affiche un craft
 * @param craft Le craft
 */
void printCraft(Craft craft){
    printf("%d : %s  ", craft.inventoryCraft->id, craft.inventoryCraft->name);
    if(craft.inventory1 > 0){
        Inventory* inv1 = getInventoryFromId(craft.inventory1);
        printf("%s(x%d) ", inv1->name, craft.quantityInv1);
        freeInventory(inv1);
    }
    if(craft.inventory2 > 0){
        Inventory* inv2 = getInventoryFromId(craft.inventory2);
        printf("%s(x%d)", inv2->name, craft.quantityInv2);
        freeInventory(inv2);
    }
    printf("\n");
}

/**
 * Ajoute un craft dans la liste des crafts
 * @param listCraft la liste des crafts
 * @param craft Le craft
 */
void appendCraft(ListCraft* listCraft, Craft* craft){
    listCraft->list[listCraft->length] = craft;
    listCraft->length += 1;
}

/**
 * Spécifie si le craft est possible ou non pour un objet
 * @param craft Le craft
 * @param game Le jeu
 * @return Si c'est possible de crafter ou pas
 */
int craftIsPossible(Craft craft, Game game){
    int quantity1 = (craft.inventory1 > 0) ? getQuantityInventory(*game.player, craft.inventory1) : 0;
    int quantity2 = (craft.inventory2 > 0) ? getQuantityInventory(*game.player, craft.inventory2) : 0;
    if(quantity1 < craft.quantityInv1){
        return 0;
    } else if(quantity2 < craft.quantityInv2){
        return 0;
    } else if(craft.zoneMin > (game.position->zone + 1)){
        return 0;
    } else {
        return 1;
    }
}

/**
 * Récupération de la liste des crafts possible
 * @param game Le jeu
 * @return Liste des crafts possible
 */
ListCraft* getListCraftPossible(Game* game){
    ListCraft* listCraft = createListCraft();
    Craft* craft;
    FILE* csv = fopen(FILENAME_CRAFT, "r");
    if(csv != NULL){
        int nbLoop = 0;
        int length = getFileLength(csv);
        char craftCsv[100];
        while(ftell(csv) < length){
            fgets(craftCsv, 100, csv);
            if(nbLoop > 0){
                craft = craftInventoryWithSplit(craftCsv);
                if(craftIsPossible(*craft, *game)){
                    appendCraft(listCraft, craft);
                } else {
                    freeCraft(craft);
                }
            }
            nbLoop += 1;
        }
        fclose(csv);
        return listCraft;
    } else{
        return NULL;
    }
}

/**
 * Libère un craft de la mémoire
 * @param craft Le craft
 */
void freeCraft(Craft* craft){
    free(craft);
}

/**
 * Libère la liste des crafts de la mémoire
 * @param listCraft La liste des crafts
 */
void freeListCraft(ListCraft* listCraft){
    for(int i = 0; i < listCraft->length; i++){
        free(listCraft->list[i]);
    }
    free(listCraft);
}
