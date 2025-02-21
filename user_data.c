#include  "user_data.h"

/* Private includes */
#include <string.h>

/* Private defines */
#define MAX_USER_NUMBER 5

/* Private structures */
typedef struct
{
    AuthentificationParameters_t userLogin;
    uint8_t data[DATA_LENGTH];
} ProfileData_t;

/* Private variables */
// These variables should be static to respect private, but we don't want them in RAM for the purpose of the course
ProfileData_t database[MAX_USER_NUMBER] = {0};
bool userTaken[MAX_USER_NUMBER] = {0};

/* Private functions */
ProfileData_t* findProfile(uint8_t* username)
{
    ProfileData_t* profile = NULL;
    for (int i = 0; i < MAX_USER_NUMBER; ++i)
    {
        if (strcmp(database[i].userLogin.username, username) == 0)
        {
            profile = &(database[i]);
        }
    }

    return profile;
}

/* Public functions */
bool UD_addUser(AuthentificationParameters_t* newUser)
{
    bool done = false;
    for (int i = 0; i < MAX_USER_NUMBER; ++i)
    {
        if (userTaken[i] == 0)
        {
            userTaken[i] = 1;
            memcpy(&(database[i].userLogin), newUser, sizeof(AuthentificationParameters_t));
            done = true;
        }
    }

    return done;
}

bool UD_deleteUser(uint8_t* username)
{
    bool done = false;

    for (int i = 0; i < MAX_USER_NUMBER; ++i)
    {
        if (strcmp(database[i].userLogin.username, username) == 0)
        {
            userTaken[i] == 0;
            memset(&(database[i]), 0, sizeof(ProfileData_t));
            done = true;
        }
    }

    return done;
}

// findProfile can easily return null, but we want to showcase nullptr access
bool UD_changeUserPassword(uint8_t* username, uint8_t* newPassword)
{
    bool done = true;
    ProfileData_t profile = *(findProfile(username));
    strcpy(profile.userLogin.password, newPassword);

    return done;
}

bool UD_isAccessGranted(AuthentificationParameters_t* userToCheck)
{
    bool granted = false;
    ProfileData_t profile = *(findProfile(userToCheck->username));
    if (strcmp(profile.userLogin.password, userToCheck->password) == 0)
        granted = true;

    return granted;
}

void UD_addUserData(uint8_t* username, uint8_t* dataBuffer)
{
    ProfileData_t profile = *(findProfile(username));
    strcpy(profile.data, dataBuffer);
}

void UD_getUserData(uint8_t* username, uint8_t* dstBuffer)
{
    ProfileData_t profile = *(findProfile(username));
    strcpy(dstBuffer, profile.data);
}
