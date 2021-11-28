/*
**  Filename : stack.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'stack.c'. It's used to manage inventory's stacks
*/

#ifndef MALLOCWORLD_STACK_H
#define MALLOCWORLD_STACK_H

typedef struct Inventory Inventory;

typedef struct Stack{
    int id;
    int maximum;
    int length;
    Inventory** inventory;
} Stack;

/**
 * Création d'une pile d'inventaire
 * @param inventory L'inventaire à empiler
 * @return La pile d'inventaire
 */
Stack* createStack(Inventory inventory);

/**
 * Création d'une pile d'inventaire et en ajoute un dans la pile
 * @param inventory L'inventaire à empiler
 * @return La pile d'inventaire
 */
Stack* createStackWithInventory(Inventory* inventory);

/**
 * Ajoute un inventaire dans la pile
 * @param inventory L'inventaire
 * @param stack La pile
 * @return Si l'inventaire à été ajouté ou non
 */
int appendStack(Inventory* inventory, Stack* stack);

/**
 * Fonction test pour afficher une pile d'inventaire
 * @param stack La pile
 */
void printStackDebug(Stack stack);

/**
 * Affiche une pile d'inventaire
 * @param stack La pile
 */
void printStack(Stack stack);

/**
 * Suppression d'un inventaire dans la pile
 * @param index L'index de l'inventaire à supprimer
 * @param stack La pile
 */
void deleteStack(int index, Stack* stack);

/**
 * Libère la pile de la mémoire
 * @param stack La pile
 */
void freeStack(Stack* stack);

#endif //MALLOCWORLD_STACK_H
