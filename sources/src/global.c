#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

int getRandomNumber(int min){
    time_t t = time(NULL);

    struct tm tm = *localtime(&t);
    return (rand() % tm.tm_sec) + min;
}

int getFileLength(FILE* file){
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);
    return length;
}

void printAction(){
    printf("====================================  ACTION  =====================================\n");
    printf("||                                      ||                                       ||\n");
    printf("||  [Z] -> deplacement haut             ||   [B] -> retour au menu principal     ||\n");
    printf("||  [Q] -> deplacement gauche           ||   [L] -> sauvegarde la partie         ||\n");
    printf("||  [S] -> deplacement bas              ||   [P] -> sauvegarder et quitter       ||\n");
    printf("||  [D] -> deplacement droite           ||   [C] -> quitter sans sauvegarder     ||\n");
    printf("||  [I] -> regader mon inventaire       ||                                       ||\n");
    printf("||                                      ||                                       ||\n");
    printf("===================================================================================\n");
}