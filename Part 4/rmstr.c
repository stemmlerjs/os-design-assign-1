
/**
 * This program satisfies Part 4 (rmstr) 
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
 * Removes all occurrences of a sequence of characters from a char array.
 *
 * @param {char*} str1 - pointer to char array you wish to remove a char from.
 * @param {char*} str2 - pointer to the char array containing a sequence of characters to remove
 *                       from str1.
 *
 * @return char*
 */

char* rmstr (char* str1, char *str2) {

    // printf("%s\n", strstr(str1, str2));
    
    /*
     * Loop through the entirety of str1
     */
     
    for (int i = 0; i < strlen(str1); i++) {

        // If any element of str1 has the same character as the first
        // element of str2, we'll start a loop to detect if that sequence
        // occurs in str1.

        if (str1[i] == str2[0]) {
            int count = 0;
            for (int j = i; j < i + strlen(str2); j++) {
                count++;
            }
            
            // Sequence found. Perform a memmove, similar to rmchr only this time,
            // we must move a substring of str1's affected values over a number 
            // of spaces equal to the length of str2 (the character sequence to remove).
            
            if (count == strlen(str2)) {
                memmove(&str1[i], &str1[i + strlen(str2)], 1 + strlen(str1 +strlen(str2)) );
                i--;
            }
        }
    }
    

    return str1;
}

int main (int argc, char** argv) {

    char *str1 = argv[1];
    char *str2 = argv[2];

    str1 = rmstr(str1, str2);
    printf("Result '%s' \n", str1 );

    return 0;
}