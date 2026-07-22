/*
    ABOUT: ternary operator

    Use this when you have only two potential outcomes.

*/

#include <stdio.h>

int main() {

    int status_code = 200;

    // If status_code = 200, the value of response will be set 
    // to "Successful", otherwise it will be set to "Failed"
    char* response = (status_code == 200) ? "Successful" : "Failed";

    printf("response: %s\n", response);

    return 0;
}
