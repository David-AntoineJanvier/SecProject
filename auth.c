#include "auth.h"
#include "db_connector.h"
#include <string.h>
#include <stdio.h>

void auth_init() {
    AuthentificationParameters_t test = {.username = "kaobilin", .password = "before\0"};
    AuthentificationParameters_t test2 = {.username = "test", .password = "test\0"};
    AuthentificationParameters_t test3 = {.username = "admin", .password = "passwordadmin\0"};
    AuthentificationParameters_t test4 = {.username = "user", .password = "password\0"};
    UD_addUser(&test);
    UD_addUser(&test2);
    UD_addUser(&test3);
    UD_addUser(&test4);
}

bool auth_checkUser(AuthentificationParameters_t authParams) {
    return UD_isAccessGranted(&authParams);
}
bool db_auth_check_user(AuthentificationParameters_t authParams) {
    return db_isAccessGranted(&authParams);
}

AuthentificationParameters_t auth_login(){

    AuthentificationParameters_t params;
    char bufusrname[USERNAME_LENGTH + 1];
    char bufpasswrd[PASSWORD_LENGTH + 1];
    printf("Username: ");

    scanf("%s", bufusrname);

    printf("Password: ");
    scanf("%s", bufpasswrd);

    strcpy(params.username, bufusrname);
    strcpy(params.password, bufpasswrd);
    return params;

}
AuthentificationParameters_t auth_loginDB(){
    AuthentificationParameters_t params;
    char bufusrname[USERNAME_LENGTH + 24];
    char bufpasswrd[PASSWORD_LENGTH + 1];
    printf("Username: ");

    fgets(bufusrname, sizeof(bufusrname) + 1, stdin);
    bufusrname[strcspn(bufusrname, "\n")] = '\0';

    printf("Password: ");
    fgets(bufpasswrd, sizeof(bufpasswrd) + 1, stdin);
    bufpasswrd[strcspn(bufpasswrd, "\n")] = '\0';

    strcpy(params.username, bufusrname);
    strcpy(params.password, bufpasswrd);
    return params;

}

