/*
**  Filename : storage.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'storage.c'. It's used to manage the PNJ's storage
*/


#ifndef MALLOCWORLD_STORAGE_H
#define MALLOCWORLD_STORAGE_H

typedef struct Storage{
    int id;
    int quantity;
    struct Storage* next;
} Storage;

void appendStorage(Storage storage, int id, int quantity);



#endif //MALLOCWORLD_STORAGE_H
