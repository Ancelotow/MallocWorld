/*
**  Filename : stack.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'stack.c'. It's used to manage inventory's stacks
*/

#ifndef MALLOCWORLD_STACK_H
#define MALLOCWORLD_STACK_H

#include "inventory.h"

typedef struct Stack{
    int id;
    int maximum;
    int length;
    Inventory** inventory;
} Stack;

Stack* createStack(Inventory inventory);

Stack* createStackWithInventory(Inventory* inventory);

int appendStack(Inventory* inventory, Stack* stack);

void printStackDebug(Stack stack);

void printStack(Stack stack);

void deleteStack(int index, Stack* stack);

void freeStack(Stack* stack);

#endif //MALLOCWORLD_STACK_H
