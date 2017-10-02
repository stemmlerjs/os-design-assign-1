
/**
 * This program satisfies Part 2 (Euler-phi function) 
 * of Assignment 1.
 *
 * @author Khalil Stemmler
 * @date September 11th, 2017
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 /*
  * computeEulers
  *
  * @desc Compute Eulers Phi (n), printing all the positive integers not exceeding
  * n that are relatively prime to n (means that the only positive integer that divides both)
  * of them is 1.
  *
  * @param {Int} n
  */

 void computeEulers(int n) {

     // Start from 2, go up to n- we'll call this x

        // For each x:
        // 1. check if x / 2 a whole number

        // use ceilf(f) == f to see if the result is a whole number
    
    /*
     * 1 is relatively prime to itself, technically.
     */

    if (n == 1) {
        printf("Eulers Phi of [1]: 1 is relatively prime\n");
    }

    /*
     * Iterate through each number
     */
    
    for (int i = 2; i < n; i++) {

        int isDivisorFound = 0;

        // decrement to 1
        for (int j = i; j > 1; j--) {

            //printf("----: [%d]", j);

            float res1 = (float) n / j;
            float res2 = (float) i / j;

            if ((ceil(res1) == res1) && (ceil(res2) == res2)) {
                isDivisorFound = 1;
            }
        }

        // If GCD was not found between the two (not including 1), then the two numbers
        // are relatively prime.
        if (isDivisorFound == 0) {
            printf("Eulers Phi of [%d]: [%d] is relatively prime\n", n, i);
        }
        
    }

 }

 int main () {
    
    char userInputString [80];
    int newLineIndex;

    printf("Enter a sequence of integers: ");
    fgets(userInputString, 80, stdin);

    // Remove the newline
    newLineIndex = strlen(userInputString) -1;
    if( userInputString[newLineIndex] == '\n') 
        userInputString[newLineIndex] = '\0';

    // Now, get all the tokens from the string using String Tokenizer
    char *ptr = strtok (userInputString, " ");

    while(ptr != NULL)
    {
        // To get the value of ptr, just dereference the pointer
        char val = *ptr;

        // Convert the char into an int.
        int x = (int) atoi(ptr);

        // Compute Eulers for only valid input greater than 0
        if (x > 0) {
            computeEulers(x);
        }

        // Tokenize the next item
        ptr = strtok(NULL, " ");
    }

     return 0;
 }