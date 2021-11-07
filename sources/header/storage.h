//
// Created by Admin on 07/11/2021.
//

#ifndef MALLOCWORLD_STORAGE_H
#define MALLOCWORLD_STORAGE_H

typedef struct Storage{
    int id;
    int quantity;
    struct Storage* next;
} Storage;

void appendStorage(Storage storage, int id, int quantity);



#endif //MALLOCWORLD_STORAGE_H
