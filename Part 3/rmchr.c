
/**
 * This program satisfies Part 3 (rmchr) 
 * of Assignment 1.
 *
 * @author Khalil Stemmler
 * @date September 11th, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * rmchr
 *
 * Removes all occurrences of a char value from a char array.
 *
 * @param {char*} str - pointer to char array you wish to remove a char from.
 * @param {char*} c - pointer to the char value that you wish to remove from char array.
 *
 * @return char*
 */

char* rmchr(char* str, char* c) {
    // printf("[Using the string]: %s\n", str);
    // printf("[Removing the char]: %s\n", c);
    // printf("%c\n", str[0]);

    // Visit every address in the char array.
    for (int i = 0; i < strlen(str); i++) {
        // printf("iter %c\n ", str[i]);
        if (c[0] == str[i]) {

            /*
             * memmove. Shifts the specified address blocks over and
             * replaces any overlapping memory spaces.
             */

            memmove(&str[i], &str[i + 1], strlen(str));

            /*
             * If we've shifted over once, we need to revisit
             * the current array index because i+1 is now sitting at
             * i's memory space.
             */

            i--;
        }
    }

    return str;
}

int main (int argc, char** argv) {

    char *str = argv[1];
    char *c = (char*) argv[2];

    str = rmchr(str, c);
    printf("Result '%s'\n", str );

    return 0;
}
