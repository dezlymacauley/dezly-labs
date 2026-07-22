/*
  = equal
  + addition
  - subtraction
  * multiplication
  / division
  % remainder (aka modulus)

  Remember to watch out for zero division error

  Brackets/Parentheses
  Orders/Exponents
  Division
  Multiplication
  Addition
  Subtraction

  compound assignment operator (or compound assignment expression).
  += value
  -= value
  *= value
  /= value

*/

#include <stdio.h>

int main(void) {

  int a = 7;
  int b = 2;

  int remainder = a % b;
  printf("remainder is %d\n", remainder);
  // remainder is 1

  return 0;
}
