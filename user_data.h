#ifndef USER_DATA__
#define USER_DATA__

#include <stdint.h>
#include <stdbool.h>

/*----- Defines -----*/
#define USERNAME_LENGTH 8
#define PASSWORD_LENGTH 16
#define DATA_LENGTH     24
/*----- Defines End -----*/


/*---- Structures and types ----*/

typedef struct
{
    uint8_t username[USERNAME_LENGTH];
    uint8_t password[PASSWORD_LENGTH];
} AuthentificationParameters_t;

/*----- Structures and types End -----*/


/*----- Functions declaration -----*/
bool UD_addUser(AuthentificationParameters_t* newUser);
bool UD_deleteUser(uint8_t* username);
bool UD_changeUserPassword(uint8_t* username, uint8_t* newPassword);

bool UD_isAccessGranted(AuthentificationParameters_t* userToCheck);
void UD_addUserData(uint8_t* username, uint8_t* dataBuffer);
void UD_getUserData(uint8_t* username, uint8_t* dstBuffer);
void UD_getUserPassword(uint8_t* username, uint8_t* dstBuffer);
/*----- Functions declaration End -----*/


#endif