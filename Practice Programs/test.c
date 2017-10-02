#include <stdio.h>
#include <string.h>

int main()
{       
  char middleInitial;
  printf("What is the middle initial of your name?: ");

 /*
  * scanf comes from stdio.h
  * It takes in input from the user and it only accepts exactly
  * the types and lengths that you've specified.
  */

  scanf(" %c", &middleInitial);
  printf("You said your middle initial was %c \n\n", middleInitial);

  char firstName[30], lastName[30];

  printf("What is your name?: ");

 /*
  * We use & to signify "where in memory" we're writing to.
  */

  scanf(" %s %s", &firstName, &lastName);

  printf("Your name is %s %c %s", firstName, middleInitial, lastName);

  // --> Your name is Khalil D Stemmler

  return 0;
}