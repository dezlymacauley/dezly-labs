/*
    ABOUT: floating points

    float
    double
    long double
*/

// floating point numbers (aka floats) are numbers that have a decimal part.

#include <stdio.h>

int main() {

  // single-precision floating point
  // approximately six decimal digits of precision.
  // When using float remember to add `f` to the value
  float account_balance = 0.00f;

  // `%.2f` means that account_balance is a floating point number 
  // that should be printed with 2 decimals
  printf("account_balance %.2f\n", account_balance);

  // double-precision floating point
  // approximately 15 decimal digits of precision.
  double interest_rate = 0.00; 

  // `%.2lf` means that account_balance is a double-precision 
  // floating point number.
  // that should be printed with 2 decimals
  printf("interest_rate %.2lf\n", interest_rate);

  return 0;
}
