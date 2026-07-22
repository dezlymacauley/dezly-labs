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
  // six decimal digits of precision.
  float account_balance = 0.00;

  // double-precision floating point
  // 15 decimal digits of precision.
  double interest_rate = 0.00; 

  // `%.2f` means that account_balance is a floating point number 
  // that should be printed with 2 decimals
  printf("account_balance %.2f\n", account_balance);

  return 0;
}
