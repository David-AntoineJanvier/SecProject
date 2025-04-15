mod user_data;
mod auth;
mod db_connector;

use std::io;

fn main() {
    auth::auth_init();
    println!("");
    println!("Bienvenue dans le super systeme de collection des donnees ultra securitaire !\n\n");

    loop
    {
        println!("Choisissez votre mode :\n");
        println!("1 - Mode local\n");
        println!("2 - Mode SQL (base de donnees)\n");

        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("Failed to read line");
        let mut mode_choice: i32 = buf.trim().parse().expect("Please enter an integer");
        buf.clear();


        match mode_choice
        {
            1 =>
            {
                println!("Veuillez vous authentifier pour acceder au systeme local.\n");
                let auth_params: auth::AuthenticationParameters = auth::auth_login();
                if auth::auth_check_user(&auth_params)
                {
                    println!("Vous etes bien authentifie.");
                    loop
                    {
                        println!("\nChoisissez votre action :\n");
                        println!("1 - Insérer vos données\n");
                        println!("2 - Lire vos données\n");

                        io::stdin().read_line(&mut buf).expect("Failed to read line");
                        mode_choice = buf.trim().parse().expect("Please enter an integer");
                        buf.clear();
                        match mode_choice
                        {
                            1 =>
                            {
                                println!("Entrez vos données: ");
                                let mut data = String::new();
                                io::stdin().read_line(&mut data).expect("Failed to read line");
                                user_data::ud_add_user_data(&(auth_params.username), data);
                                println!("Données bien ajoutées!");
                                break;
                            },
                            2 =>
                            {
                                let recovered_data = user_data::ud_get_user_data(&(auth_params.username));
                                println!("Vos données sont: ");
                                println!("{}", recovered_data);
                                break;
                            },
                            _ => 
                            {
                                println!("Please enter a valid choice");
                                break;
                            }
                        }
                    }
                }
            },
            2 =>
            {
                println!("Veuillez vous authentifier pour acceder à la base de données.\n");
                let auth_params: auth::AuthenticationParameters = auth::auth_login();
                if auth::db_auth_check_user(&auth_params)
                {
                    println!("Vous etes bien authentifie.");
                    loop
                    {
                        println!("\nChoisissez votre action :\n");
                        println!("1 - Insérer vos données\n");
                        println!("2 - Lire vos données\n");

                        io::stdin().read_line(&mut buf).expect("Failed to read line");
                        mode_choice = buf.trim().parse().expect("Please enter an integer");
                        buf.clear();
                        match mode_choice
                        {
                            1 =>
                                {
                                    println!("Entrez vos données: ");
                                    let mut data = String::new();
                                    io::stdin().read_line(&mut data).expect("Failed to read line");
                                    user_data::ud_add_user_data(&(auth_params.username), data);
                                    println!("Données bien ajoutées!");
                                    break;
                                },
                            2 =>
                                {
                                    let recovered_data = user_data::ud_get_user_data(&(auth_params.username));
                                    println!("Vos données sont: ");
                                    println!("{}", recovered_data);
                                    break;
                                },
                            _ =>
                                {
                                    println!("Please enter a valid choice");
                                    break;
                                }
                        }
                    }
                }
            },
            _ =>
            {
                println!("Please enter a valid choice");
            }
        }
    }
}