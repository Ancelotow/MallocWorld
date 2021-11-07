#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header/stack.h"
#include "../header/inventory.h"

Stack* createStack(Inventory inventory){
    Stack* stack = malloc(sizeof(Stack));
    stack->id = inventory.id;
    stack->maximum = inventory.maxStack;
    stack->length = 0;
    stack->inventory = malloc(sizeof(Inventory*) * stack->maximum);
    return stack;
}

Stack* createStackWithInventory(Inventory* inventory){
    Stack* stack = createStack(*inventory);
    appendStack(inventory, stack);
    return stack;
}

int appendStack(Inventory* inventory, Stack* stack){
    if(stack->length < stack->maximum){
        stack->inventory[stack->length] = inventory;
        stack->length += 1;
        return 1;
    } else {
        return 0;
    }
}

void printStack(Stack stack){
    Inventory* inv = getInventoryFromId(stack.id);
    printf("\n\n=========== %s : %s  ||  %d/%d ===========\n", getInventoryTypeName(inv->type), inv->name, stack.length, stack.maximum);
    for(int i =0; i < stack.length; i++){
        printInventory(*stack.inventory[i]);
    }
    freeInventory(inv);
}

void deleteStack(int index, Stack* stack){
    if(stack->length > 0 && index < stack->length){
        for(int i = index + 1; i < stack->length; i++){
            stack->inventory[i - 1] = stack->inventory[i];
        }
        freeInventory(stack->inventory[stack->length - 1]);
        stack->length -= 1;
    }
}

void freeStack(Stack* stack){
    for(int i = 0; i < stack->length; i++){
        freeInventory(stack->inventory[i]);
    }
    free(stack);
}
