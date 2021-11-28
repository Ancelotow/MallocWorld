//
// Created by Elsa Firmin on 18/11/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "../header/restaure.h"

void Loadmap(char* save){
    FILE* file;
    char chaine[300];
    char restaure[300];

    file = fopen(save, "r+");

    while (fgets(chaine, 50, file) != NULL)
    {
        int i = 0;
        //restaure[i] = chaine;
        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        i++;
    }


    fclose(file);
}