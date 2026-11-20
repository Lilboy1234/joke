#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define JOKEAMOUNT 3 // DEFINES ARE "DEFINED" IN COMPILE TIME

int main(int argc, char *argv[]) {

  char *jokes[JOKEAMOUNT] = {"The Frog's car broke down it had to get TOWED to the repair shop.\n",
                            "Why did the chicken cross the road? To get to the OTHER SIDE.\n",
                            "Knock Knock. Who's there? The Interrupting Cow. The Interruptin-. MOO!\n"};
  // it is a pointer table because in C strings are just a char table so you need a pointer
  //
  // example:
  //
  // char hi[2] = "hi"; is just a string so you need pointers for individual character
  //

  if (argc == 2) {
    if (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0) {
      char jokesStr[1000] = ""; // size depends so just make it a big number

      for (int i = 0; i < JOKEAMOUNT; i++) {
        strcat(jokesStr,jokes[i]);
      }

      printf("Type just 'joke' for a random joke\nor type 'joke' then a number for a joke out of these (1-joke amount)\n\n%s\n",jokesStr);
      return 0;
    }
    int ui = atoi(argv[1]); // converts argument from user to interger

    if (ui == 0) {
      printf("invalid input\n"); // checks if converting argument from user to interger is successful
      return 1;
    }
    
    if (ui > JOKEAMOUNT || ui < 1) {
      printf("invalid input\n"); // checks if user input is within range 1-JOKEAMOUNT aka 3
      return 1;
    }

    printf("%s",jokes[ui-1]); // look at line 39
  }else {
    srand(time(NULL)); // creates a seed for random

    int r = (rand()%JOKEAMOUNT); // rand() creates a random interger
    // modulus divides and takes the remainder so it chosses a random number from 0 to JOKEAMOUNT-1 which is perfect for tables which start at 0

    printf("%s",jokes[r]); // %s takes an input from the corresponding argument in the function %s stands for string

    return 0; // returns 0 to show program is successful
  }
}
