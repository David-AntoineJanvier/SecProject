#ifndef DB_CONNECTOR__
#define DB_CONNECTOR__

#include "user_data.h"
#include <stdbool.h>

void db_setup();
bool db_isAccessGranted(AuthentificationParameters_t* userToCheck);

#endif // DB_CONNECTOR__
