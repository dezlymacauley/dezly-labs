/*
_______________________________________________________________________________

  ABOUT: scanf

  `scanf` mean `scan formatted`.

_______________________________________________________________________________
*/

#include <stdio.h>

int main() {

  int raw_input = 0;
  
  // The newline character is left out so that the user enters a number
  // on the same line.
  printf("Enter a number: ");
  scanf("%d", &raw_input);

  printf("raw_input: %d\n", raw_input);
}
