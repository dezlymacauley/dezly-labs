/*
    ABOUT: signed integers

    short
    int
    long
    long long
*/

// integers are numbers that don't have a fractional part.

#include <stdio.h>

int main() {
  // The correct format specifier is %d which
  // means `decimal integer` (base 10)

  // `%o` mean `octal integer` (base 8)
  // `%x` mean `hexadecimal integer` (also refered to as `hex`) (base 16)

  // and `%i` is just a general format specifier for an integer.
  // When you use this with `scanf()`,
  // C will try to work out whether the integer is
  // base 10, base 8, or base 16 based on its value.

  int user_age = 32;

  // 0 followed by the three numbers
  // The value printed will only show 775,
  // the 0 at the start will be left out.
  int file_permissions = 0775;

  // `70008B` is purple color
  // In frontend development, more specifically CSS,
  // you'd use `#` to indicate that it is a hex value like this:
  // color: #70008B;
  //
  // In C, an integer value can't start with `#`,
  // so you'd use `0x` to indicate that it is a hex value like this:
  // The value printed will only show 70008B,
  // the 0x at the start will be left out.
  int color = 0x70008B;

  printf("user_age: %d\n", user_age);
  printf("file_permissions: %o\n", file_permissions);
  printf("color: %x\n", color);
  // user_age: 32
  // file_permissions: 775
  // color: 70008b
}
