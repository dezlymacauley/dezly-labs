/*
    ABOUT: Switch statement

    Use this when you want to handle more than 3 potential outcomes.

*/

#include <stdio.h>

int main() {

    unsigned int status = 200;

    switch (status) {
    case 200:
        printf("200 OK - Request successful\n");
        break;
    case 301:
        printf("301 Moved Permanently - Resource relocated\n");
        break;
    case 400:
        printf("400 Bad Request - Client error\n");
        break;
    case 404:
        printf("404 Not Found - Resource does not exist\n");
        break;
    case 500:
        printf("500 Internal Server Error - Server failure\n");
        break;
    default:
        printf("Unknown status code: %d\n", status);
        break;
    }

    return 0;
}
