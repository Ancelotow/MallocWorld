/*
**  Filename : storage.h
**
**  Made by : Elsa FIRMIN
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

Storage* createStorage(int id, int quantity); //FAIT

void appendStorage(Storage* storage, int id, int quantity); //FAIT

void deleteElement(Storage* storage, int id, int newQuantity);

void printStorage(Storage* storage);    //FAIT

void freeStorage(Storage* storage); //FAIT



#endif //MALLOCWORLD_STORAGE_H


/**
* tu peux supprimer un un élément (donc  tu  baisse la  quantité de 1 ou de N élement  pour un id inventaire donné)
 et tu peux aussi ajouter :
   - si l'inventaire existe, tu fait +1 à la quantité X
*/