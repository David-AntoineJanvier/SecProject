#include "auth.h"
#include "user_data.h"

#include <stdio.h>
#include <string.h>


void auth_init() {
    
    
}

bool auth_checkUser(char *username, char *password) {
    // Check if the username and password match any of the stored users

}

AuthentificationParameters_t auth_login(){
    AuthentificationParameters_t params;
    char bufusrname[8];
    char bufpasswrd[16];
    printf("Username: ");

    fgets(bufusrname, 8, stdin);

    printf("Password: ");
    fgets(bufpasswrd, 16, stdin);

    strcpy(params.username, bufusrname);
    strcpy(params.password, bufpasswrd);
    return params;

}