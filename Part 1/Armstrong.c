
/*
 * This program satisfies Part 1 (Armstrongs Numbers) 
 * of Assignment 1.
 *
 * @author Khalil Stemmler
 * @date Sept 11th, 2017
 */

#include <stdio.h>
#include <string.h>
#include <math.h>       // required to use pow()

/*
 * getArmstrongResult
 * 
 * @desc Computes the Armstrong result for number.
 *
 * @param {Int} number - number being queried if it's an Armstrong Number
 * @param {Int} order - Armstrong order
 */

int getArmstrongResult(int number, int order) {
    double result = 0;

    while (number) {
        double digit = pow(number % 10, order);
        result += digit;
        number /= 10;
    }

    return (int) result;
}

/*
 * armstrongProcess
 *
 * @desc Check every number within the specified range if it is an
 * Armstrong Number or not.
 *
 * @param {Int} k - armstrong order
 * @param {Int} p - lower bound
 * @param {Int} q - upper bound
 */

void armstrongProcess(int k, int p, int q) {
    for (int i = p; i <= q; i++) {
        
        int arm = getArmstrongResult(i, k);
        if (arm == i) {
            printf("Found an Armstrong Number: [%d]\n", i);
        }
    }
}

int main () {

    int k; // ARMSTRONG ORDER
    int p; //     LOWER BOUND
    int q; //     UPPER BOUND

    printf("============================\n");
    printf("      ARMSTRONGS NUMBER\n");
    printf("============================\n\n");

    printf("Enter the Armstrong Order value [k]: ");
    scanf(" %d", &k);
    
    printf("\nEnter the lower bound interval [p]: ");
    scanf(" %d", &p);

    printf("\nEnter the upper bound interval [q]: ");
    scanf(" %d", &q);

    printf("\n");

    // Solve
    armstrongProcess(k, p, q);

    return 0;
}