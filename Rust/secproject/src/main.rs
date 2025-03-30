mod user_data;
mod auth;
mod db_connector;

use std::io;

fn main() {
    auth::auth_init();
    println!("");
    println!("Bienvenue dans le super systeme de collection des donnees ultra securitaire !\n\n");
    
    let mut choice = false;

    while !choice{
        println!("Choisissez votre mode :\n");
        println!("1 - Mode local\n");
        println!("2 - Mode SQL (base de donnees)\n");
        println!("0 - EXIT\n");

        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("Failed to read line");
        let mode_choice: i32 = buf.trim().parse().expect("Please enter an integer");


        if mode_choice == 0 {
            println!("EXIT SUCCESSFUL");
            std::process::exit(0);
        }
        else if mode_choice == 1 {
            println!("Veuillez vous authentifier pour acceder au systeme local.\n");
            let auth_params: auth::AuthenticationParameters = auth::auth_login();
            if auth::auth_check_user(auth_params){
                println!("Vous etes bien authentifie.");
            }
            choice = true;
        }
        else if mode_choice == 2 {
            println!("Veuillez vous authentifier pour acceder à la base de données.\n");
            println!("choice 1 pas implementer gang de rat");
            choice = true;
        }
        else{
            println!("Please enter a valid choice");

        }
    }
}