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
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} AuthentificationParameters_t;

/*----- Structures and types End -----*/


/*----- Functions declaration -----*/
bool UD_addUser(AuthentificationParameters_t* newUser);
bool UD_deleteUser(char* username);
bool UD_changeUserPassword(char* username, char* newPassword);

bool UD_isAccessGranted(AuthentificationParameters_t* userToCheck);
void UD_addUserData(char* username, char* dataBuffer);
void UD_getUserData(char* username, char* dstBuffer);
void UD_getUserPassword(char* username, char* dstBuffer);
/*----- Functions declaration End -----*/


#endif