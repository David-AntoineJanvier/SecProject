#include <stdio.h>
#include "user_data.h"
#include "auth.h"

int main()
{
    auth_init();
    printf("Bienvenu dans le super systeme de collection des donnée ultra securitaire !\n\n");
    printf("Veuillez vous authentifier pour acceder au systeme.\n");
	int flag;

	while(1)
	{
		AuthentificationParameters_t loginInfo = auth_login();
	    printf("Vous essayer de vous connecte en tant que %s.\n", loginInfo.username);
    	if (auth_checkUser(loginInfo))
		{
        	printf("Vous etes bien authentifie.\n");
			char privateData[DATA_LENGTH];
			printf("Data? :)\n");
			scanf("%d", &flag);
			if (flag)
			{
				printf("Enter please\n");
				scanf("%s", privateData);
				UD_addUserData(loginInfo.username, privateData);
				printf("Data Added!\n");
			}
			else
			{
				char recoverData[DATA_LENGTH+1];
				UD_getUserData(loginInfo.username, recoverData);
				printf("Your private data is %s\n", recoverData);
			}
    	}
		else
		{
        	printf("Erreur d'authentification.\n");
		}
    }


    return 0;
}
