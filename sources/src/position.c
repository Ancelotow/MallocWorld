#include "../header/position.h"
#include "../header/world.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Position* seekPlayer(World world){
    Position *position = malloc(sizeof(Position));
    position->x = -1;
    position->y = -1;
    for(int i=0; i < NB_ZONE; i++){
        for(int r=0; r < world.world[i]->row; r++){
            for(int c=0; c < world.world[i]->column; c++){
                if(world.world[i]->map[r][c] == 1){
                    position->x = c;
                    position->y = r;
                    position->zone = i;
                    break;
                }
            }
            if(position->x != -1){
                break;
            }
        }
        if(position->x != -1){
            break;
        }
    }
    return position;
}

void freePosition(Position* position){
    free(position);
}