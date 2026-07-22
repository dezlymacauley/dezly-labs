/*
    ABOUT: char (character)

    The char type is a special type of int in C.

    In C all strings are treated as arrays.

    Computers store characters as numbers

    Every character used by a computer corresponds to a unique number,
    and vice versa.

    There are certain characters that are not visible to humans when printed,
    but they have a special meaning to computers,
    such as white space characters. E.g. The space between Dezly and Macauley
    when printing out my name.
    "Dezly Macauley"

    E.g. `\n` is the newline character. The newline character is
    called an `escape character`.


    Different computers use different character encodings so an information
    exchange standard called ASCII was created.

    ASCII = American Standard Code for Information Interchange

    This is what most computers and mobile devices use today.

    `\0` this is the `null` character. It is used to terminate strings.
    It tells C where a string ends.
*/

#include <stdio.h>
int main() {
  // The value must be wrapped in single qoutes
  char a = 'A';

  // If you wanted to store the value ',
  // then you'd use \'
  char single_qoute = '\'';

  printf("a: %c\n", a);
  printf("single_qoute: %c\n", single_qoute);
  // a: A
  // single_qoute: '
}
