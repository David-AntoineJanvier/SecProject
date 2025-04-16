# Projet de Session - Sécurité des logiciels

Bienvenue dans notre application de gestion super sécurisée de données privées !  
Ce programme vous permet de vous authentifier, de stocker des données personnelles et de les consulter à tout moment, en mode **local** ou via une **base de données SQL**.

# Utilisation
Au démarrage, vous devez choisir entre deux modes :
```bash
1 - Mode local
2 - Mode SQL (base de données)
```
Une fois authentifié, vous accédez au menu suivant :
```bash
1 - New data              → Ajouter une nouvelle donnée privée
2 - View private data     → Voir les données associées à votre compte
3 - Toggle database mode  → Revenir au menu de sélection de mode
0 - logout                → Se déconnecter
```

---
# Application C
##  Compilation
```bash
gcc -o nom_de_executable main.c user_data.c auth.c db_connector.c -lmysqlclient
```
## Exploitation des vulnérabilitées
Ce programme n'est vraiment pas sécuritaire : voici comment l'exploiter.

### OOBW
Voici la recette à suivre afin de pouvoir écraser le nom d'utilisateur et mot de passe du prochain utilisateur:
| Octets         | Contenu écrit              | But                                     |
|----------------|----------------------------|-----------------------------------------|
| 0 - 25         | `AAAAAAAAAAAAAAAAAAAAAAAAA` | Remplit `data` (24 caractères)         |
| 26 - 58        | `BBBB...BBBB` (33 B)       | Écrase `username` (`USERNAME_LENGTH+1`) |
| 59 - 74        | `CCCC...CCC` (14 C)        | Écrase `password` (`PASSWORD_LENGTH`) |

Exemple de payload à copier coller, ainsi que le nouveau nom d'utilisateur et mot de passe de la personne attaquée :
```bash
AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBnewpasswordslong
username = BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
password = newpasswordslong
```


### NPT
Simplement à vous authentifier avec un nom fictif et un mot de passe valide:
```bash
username = nomFictif
password = test
```
Entrez ensuite l'option 2 (view private data) : l'application devrait ainsi crasher puisque findProfile() retourne un pointeur NULL qui est par la suite déréférencé.

### SQL injection
Pour que le projet fonctionne instaler mariadb et setup un user nommé root avec le password=root
avoir une DB nommé sec_projet_db qui contient une table users avec les champs username et password

Bypass le password du user test
```bash
username = test
password = ' OR 1=1; --
```
DROP la table user
```bash
username = '; DROP TABLE users; -- '
password = aa
```

# Application Rust
## Compilation
```bash
cargo build
```
Ensuite, pour exécuter :
```bash
cargo run
```


# Files
Les deux projets ont une organisation de fichier similaires :
| nom de fichier     | Contenu             | 
|----------------|----------------------------|
| main| 		Logique principale du programme, menu interactif; 	|
| auth|			Authentification pour accéder à la base de donnée;  |
| user_data |	Fonctions qui modifient/accèdent la base de donnée; |

