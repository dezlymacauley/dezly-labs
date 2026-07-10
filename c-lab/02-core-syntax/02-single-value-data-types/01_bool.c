/*
    ABOUT: bool

*/

#include <stdio.h>

int main(void) {

    bool is_connected = true;
    bool has_admin_access = false;
    
    //_________________________________________________________________________

    printf("is_connected: %i\n", is_connected);
    printf("has_admin_access: %i\n", has_admin_access);
    // is_connected: 1
    // has_admin_access: 0

    // 1 means true
    // 0 means false

    //_________________________________________________________________________
    
    // If you want to print out true and false then you'd use this.
   
    printf("is_connected: %s\n", is_connected ? "true" : "false");
    printf("has_admin_access: %s\n", has_admin_access ? "true" : "false");
    // is_connected: true
    // has_admin_access: false 
    
    //_________________________________________________________________________
    return 0;
}
