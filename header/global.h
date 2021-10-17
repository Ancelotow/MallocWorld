//
// Created by Admin on 16/10/2021.
//

#ifndef MALLOCWORLD_GLOBAL_H
#define MALLOCWORLD_GLOBAL_H

/**
 * Created a copy of string. It's used to initialize new string
 * @param string Source string
 * @return The string's copy
 */
char* copyString(char* string);

/**
 * Printed the game's title
 */
void printTitle();

/**
 * Get a random number
 * @param min Minimum value
 * @return Random number
 */
int getRandomNumber(int min);

#endif //MALLOCWORLD_GLOBAL_H
