#include <stdio.h>
#include "user_data.h"

int main()
{
    AuthentificationParameters_t heyKracko = {.username = "kaobilin", .password = "before"};
    printf("%s\n", heyKracko.password);
    UD_changeUserPassword(heyKracko.username, "changed");
    printf("%s\n", heyKracko.password);
    return 0;
}