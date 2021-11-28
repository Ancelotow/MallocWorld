/*
**  Filename : global.c
**
**  Made by : Owen ANCELOT
**
**  Description : It's the global functions which can be called anywhere in this project.
*/

#include "../header/global.h"

/**
 * Permet de dupliquer une chaîne de charactère
 * @param string La chaîne de charactère à dupliquer
 * @return La chaîne de charactère dupliquer
 */
char* copyString(char* string){
    int length = 1;
    for(int i=0; string[i] != '\0'; i++){
        length += 1;
    }
    char* newString = malloc(sizeof(char) * length);
    for(int i=0; i < length; i++){
        newString[i] = string[i];
    }
    return newString;
}

/**
 * Affiche le titre du jeu : "Malloc World"
 */
void printTitle(){
    printf("############################################################################################################\n");
    printf("############################################################################################################\n");
    printf("||#||                                                                                                   ||#||\n");
    printf("||#||   ##          ##       ####       ##              ##             ##############  ##############   ||#||\n");
    printf("||#||   ####      ####      ##  ##      ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##  ##  ##  ##     ##    ##     ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##    ##    ##    ##########    ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##          ##    ##      ##    ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##          ##   ##        ##   ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##          ##   ##        ##   ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##          ##  ##          ##  ##              ##             ##          ##  ##               ||#||\n");
    printf("||#||   ##          ##  ##          ##  ##############  #############  ##############  ##############   ||#||\n");
    printf("||#||                                                                                                   ||#||\n");
    printf("||#||           ##          ##  ##############  ############    ##             ###########              ||#||\n");
    printf("||#||           ##          ##  ##          ##  ##          ##  ##             ##        ##             ||#||\n");
    printf("||#||           ##          ##  ##          ##  ##          ##  ##             ##          ##           ||#||\n");
    printf("||#||           ##          ##  ##          ##  ##          ##  ##             ##          ##           ||#||\n");
    printf("||#||           ##          ##  ##          ##  ############    ##             ##          ##           ||#||\n");
    printf("||#||           ##    ##    ##  ##          ##  ##       ##     ##             ##          ##           ||#||\n");
    printf("||#||           ##  ##  ##  ##  ##          ##  ##        ##    ##             ##          ##           ||#||\n");
    printf("||#||           ####      ####  ##          ##  ##         ##   ##             ##        ##             ||#||\n");
    printf("||#||           ##          ##  ##############  ##          ##  #############  ###########              ||#||\n");
    printf("||#||                                                                                                   ||#||\n");
    printf("############################################################################################################\n");
    printf("############################################################################################################\n");
}

/**
 * Retourne un nombre aléatoire
 * @param min La valeur minimum du nombre aléatoir
 * @return Un nombre aléatoire
 */
int getRandomNumber(int min){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int divisor = (tm.tm_sec == 0) ? 1 : tm.tm_sec;
    return (rand() % divisor) + min;
}

/**
 * Récupère la taille d'un fichier
 * @param file Le fihier
 * @return La taille d'un fichier
 */
int getFileLength(FILE* file){
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);
    return length;
}

/**
 * Affiche les actions possible en jeu
 */
void printAction(){
    printf("\n====================================  ACTION  =====================================\n");
    printf("||                                      ||                                       ||\n");
    printf("||  [Z] -> deplacement haut             ||   [M] -> afficher la carte            ||\n");
    printf("||  [Q] -> deplacement gauche           ||   [J] -> afficher mon personnage      ||\n");
    printf("||  [S] -> deplacement bas              ||   [L] -> sauvegarde la partie         ||\n");
    printf("||  [D] -> deplacement droite           ||   [P] -> sauvegarder et quitter       ||\n");
    printf("||  [I] -> regader mon inventaire       ||   [C] -> quitter sans sauvegarder     ||\n");
    printf("||                                      ||                                       ||\n");
    printf("===================================================================================\n");
}

/**
 * Affiche les actions possible en combat
 */
void printActionFight(){
    printf("\n===============================  ACTION DE COMBAT  ================================\n");
    printf("||                                      ||                                       ||\n");
    printf("||  [A] -> Attaquer                     ||   [E] -> Fuir                         ||\n");
    printf("||  [H] -> Utiliser une potion          ||   [W] -> Changer d'arme               ||\n");
    printf("||  [P] -> Changer d'armure             ||                                       ||\n");
    printf("||                                      ||                                       ||\n");
    printf("===================================================================================\n");
}

/**
 * Affiche les actions que peux effectuer le PNJ
 */
void printActionPNJ(){
    printf("\n=============================== ACTIONS AVEC LE PNJ  ==============================\n");
    printf("||                                      ||                                       ||\n");
    printf("||  [R] -> Reparer mon equipement       ||   [C] -> Crafter de l'equipement      ||\n");
    printf("||  [A] -> Stocker dans le coffre       ||   [T] -> Recuperer du coffre          ||\n");
    printf("||  [S] -> Voir le coffre               ||   [Q] -> Quitter                      ||\n");
    printf("||                                      ||                                       ||\n");
    printf("===================================================================================\n");
}

/**
 * Libère un tableau de 'int' en 2 dimensions
 * @param tab Tableau en 2 dimensions
 * @param row Nombre de lignes
 */
void freeTab2D(int** tab, int row){
    for(int i = 0; i < row; i++){
        free(tab[i]);
    }
    free(tab);
}