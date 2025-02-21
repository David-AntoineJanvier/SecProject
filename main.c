#include <stdio.h>
#include "user_data.h"

int main()
{
    AuthentificationParameters_t heyKracko = {.username = "kaobilin", .password = "before\0"};
    UD_addUser(&heyKracko);
    printf("%s\n", heyKracko.password);
    UD_changeUserPassword(heyKracko.username, "changed\0");
    char newPassword[PASSWORD_LENGTH];
    UD_getUserPassword(heyKracko.username, newPassword);
    printf("%s\n", newPassword);
    return 0;
}