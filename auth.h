#ifndef auth_h
#define auth_h
#include "user_data.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*----- Defines -----*/
#define USERNAME_LENGTH 8
#define PASSWORD_LENGTH 16
#define TOKEN_LENGTH    16
/*----- Defines End -----*/


/*---- Structures and types ----*/

/*typedef struct excemple
{
    char username[USERNAME_LENGTH+1];
    char password[PASSWORD_LENGTH+1];
} AuthentificationParameters_t;*/


/*----- Structures and types End -----*/


/*----- Functions declaration -----*/
/*bool UD_addUser(AuthentificationParameters_t* newUser);*/
void auth_init(void);
AuthentificationParameters_t auth_login();


bool auth_checkUser(AuthentificationParameters_t authParams);


/*----- Functions declaration End -----*/


#endif