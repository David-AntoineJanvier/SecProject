#include <stdio.h>
#include "user_data.h"
#include "auth.h"
#include "db_connector.h"

int main()
{
    auth_init();
	int user_menu_choice;
	int logout_flag = 0;
	int mode_choice;

    printf("Bienvenue dans le super systeme de collection des donnees ultra securitaire !\n\n");

    printf("Choisissez votre mode :\n");
    printf("1 - Mode local\n");
    printf("2 - Mode SQL (base de donnees)\n");
    scanf("%d", &mode_choice);
    getchar(); // Pour consommer le '\n' laissé par scanf

	while(1)
	{
	if (mode_choice == 1) {
		printf("Veuillez vous authentifier pour acceder au systeme.\n");
		AuthentificationParameters_t loginInfo = auth_login();
	    printf("Vous essayer de vous connecte en tant que %s.\n", loginInfo.username);
    	if (auth_checkUser(loginInfo))
		{
        	printf("Vous etes bien authentifie.\n");
			char privateData[DATA_LENGTH];


			while (1){
				printf("\r\n");
				printf("  1 - New data \r\n");
				printf("  2 - View private data\r\n");
				printf("  3 - Toggle database mode\r\n");
				printf("  0 - logout\r\n");
				scanf("%d", &user_menu_choice);

				switch(user_menu_choice){
					case 1:
						printf("\r\nEnter the data you want to add : \r\n");
						scanf("%s", privateData);
						UD_addUserData(loginInfo.username, privateData);
						printf("Data Added!\n");
						break;

					case 2 :
						char recoverData[DATA_LENGTH+1];
						UD_getUserData(loginInfo.username, recoverData);
						printf("Your private data is: %s\n", recoverData);
						break;
					case 0:
						printf("Logout successful\r\n");
						logout_flag =1;
						break;
					default :
						printf("Invalid option\r\n");
						break;
				}//switch
				if(logout_flag) break;
			}//while
		}
		else
		{
        	printf("Erreur d'authentification.\n");
		}
		logout_flag = 0;
    }
    else
	{
		printf("Mode base de donnees.\n");
		printf("Veuillez vous authentifier pour acceder au systeme.\n");
		AuthentificationParameters_t loginInfo = auth_loginDB();
    	if (db_auth_check_user(loginInfo))
		{
        	printf("Vous etes bien authentifie.\n");
			char privateData[DATA_LENGTH];


			while (1){
				printf("\r\n");
				printf("  1 - New data \r\n");
				printf("  2 - View private data\r\n");
				printf("  3 - Toggle database mode\r\n");
				printf("  0 - logout\r\n");
				scanf("%d", &user_menu_choice);

				switch(user_menu_choice){
					case 1:
						printf("\r\nEnter the data you want to add : \r\n");
						scanf("%s", privateData);
						UD_addUserData(loginInfo.username, privateData);
						printf("Data Added!\n");
						break;

					case 2 :
						char recoverData[DATA_LENGTH+1];
						UD_getUserData(loginInfo.username, recoverData);
						printf("Your private data is: %s\n", recoverData);
						break;
					case 0:
						printf("Logout successful\r\n");
						logout_flag =1;
						break;
					default :
						printf("Invalid option\r\n");
						break;
				}//switch
				if(logout_flag) break;
			}//while
		}
		else
		{
        	printf("Erreur d'authentification.\n");
		}
		logout_flag = 0;
    }
	}
	return 0;
}
