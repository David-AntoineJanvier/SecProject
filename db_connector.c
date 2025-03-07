#include  "db_connector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h> // link sql with compilation through -lmysqlclient

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"
#define DB_NAME "projet_sec_db"

bool db_isAccessGranted(AuthentificationParameters_t* userToCheck) {
    MYSQL *conn;
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[2];
    bool auth_success = false;
    char query [512];
    MYSQL_RES* result;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Erreur d'initialisation MariaDB\n");
        return false;
    }

    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
        fprintf(stderr, "Erreur de connexion à la base de données: %s\n", mysql_error(conn));
        mysql_close(conn);
        return false;
    }
    sprintf(query, "SELECT * FROM users WHERE username='%s' AND password='%s'", userToCheck->username, userToCheck->password);
    mysql_query(conn, query);
    result = mysql_store_result(conn);
    if (result != NULL) {
        auth_success = (mysql_num_rows(result) > 0);
    }
    mysql_free_result(result);
    mysql_close(conn);
    return auth_success;

}
