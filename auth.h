#ifndef auth_h
#define auth_h
#include "user_data.h"

#include <stdbool.h>

/*----- Defines -----*/

/*----- Defines End -----*/


/*---- Structures and types ----*/


/*----- Structures and types End -----*/


/*----- Functions declaration -----*/
/*bool UD_addUser(AuthentificationParameters_t* newUser);*/
void auth_init(void);
AuthentificationParameters_t auth_login();
AuthentificationParameters_t auth_loginDB();


bool auth_checkUser(AuthentificationParameters_t authParams);
bool db_auth_check_user(AuthentificationParameters_t authParams);


/*----- Functions declaration End -----*/


#endif
