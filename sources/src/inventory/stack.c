/*
**  Filename : stack.c
**
**  Made by : Owen ANCELOT
**
**  Description : Manage the inventory's stack
*/

#include "../../header/global.h"

/**
 * Création d'une pile d'inventaire
 * @param inventory L'inventaire à empiler
 * @return La pile d'inventaire
 */
Stack *createStack(Inventory inventory) {
    Stack *stack = malloc(sizeof(Stack));
    stack->id = inventory.id;
    stack->maximum = inventory.maxStack;
    stack->length = 0;
    stack->inventory = malloc(sizeof(Inventory *) * stack->maximum);
    return stack;
}

/**
 * Création d'une pile d'inventaire et en ajoute un dans la pile
 * @param inventory L'inventaire à empiler
 * @return La pile d'inventaire
 */
Stack *createStackWithInventory(Inventory *inventory) {
    Stack *stack = createStack(*inventory);
    appendStack(inventory, stack);
    return stack;
}

/**
 * Ajoute un inventaire dans la pile
 * @param inventory L'inventaire
 * @param stack La pile
 * @return Si l'inventaire à été ajouté ou non
 */
int appendStack(Inventory *inventory, Stack *stack) {
    if (stack->length < stack->maximum) {
        stack->inventory[stack->length] = inventory;
        stack->length += 1;
        return 1;
    } else {
        return 0;
    }
}

/**
 * Fonction test pour afficher une pile d'inventaire
 * @param stack La pile
 */
void printStackDebug(Stack stack) {
    Inventory *inv = getInventoryFromId(stack.id);
    printf("\n\n=========== %s : %s  ||  %d/%d ===========\n", getInventoryTypeName(inv->type), inv->name, stack.length,
           stack.maximum);
    for (int i = 0; i < stack.length; i++) {
        printInventory(*stack.inventory[i]);
    }
    freeInventory(inv);
}

/**
 * Affiche une pile d'inventaire
 * @param stack La pile
 */
void printStack(Stack stack) {
    Inventory *inv = getInventoryFromId(stack.id);
    printf("||\n");
    printf("|| id : %d = %s : %s = %d/%d\n", stack.id, getInventoryTypeName(inv->type), inv->name,
           stack.length, stack.maximum);
    for (int i = 0; i < stack.length; i++) {
        printInventory(*stack.inventory[i]);
    }
    freeInventory(inv);
}

/**
 * Suppression d'un inventaire dans la pile
 * @param index L'index de l'inventaire à supprimer
 * @param stack La pile
 */
void deleteStack(int index, Stack *stack) {
    if (stack->length > 0 && index < stack->length) {
        for (int i = index + 1; i < stack->length; i++) {
            stack->inventory[i - 1] = stack->inventory[i];
        }
        freeInventory(stack->inventory[stack->length - 1]);
        stack->length -= 1;
    }
}

/**
 * Libère la pile de la mémoire
 * @param stack La pile
 */
void freeStack(Stack *stack) {
    for (int i = 0; i < stack->length; i++) {
        freeInventory(stack->inventory[i]);
    }
    free(stack);
}
