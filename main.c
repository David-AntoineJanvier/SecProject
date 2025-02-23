#include <stdio.h>
#include "user_data.h"
#include "auth.h"

int main()
{
    auth_init();
    printf("Bienvenu dans le super systeme de collection des donnée ultra securitaire !\n\n");
    printf("Veuillez vous authentifier pour acceder au systeme.\n");
    AuthentificationParameters_t test = auth_login();
    printf("Vous essayer de vous connecte en tant que %s.\n", test.username);
    if (auth_checkUser(test)){
        printf("Vous etes bien authentifie.\n");
    } else {
        printf("Erreur d'authentification.\n");
    }




    /*
    AuthentificationParameters_t heyKracko = {.username = "kaobilin", .password = "before\0"};
    UD_addUser(&heyKracko);
    printf("%s\n", heyKracko.password);
    UD_changeUserPassword(heyKracko.username, "changed\0");
    char newPassword[PASSWORD_LENGTH];
    UD_getUserPassword(heyKracko.username, newPassword);
    printf("%s\n", newPassword);*/
    return 0;
}