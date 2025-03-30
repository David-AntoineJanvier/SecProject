use crate::user_data;
use std::io::{self, Write};

#[derive(Debug, Clone)]
pub struct AuthenticationParameters {
    pub username: String,
    pub password: String,
}

pub fn auth_init() -> bool {
    let local1 = AuthenticationParameters {
        username: "Admin".to_string(),
        password: "password".to_string(),
    };
    let local2 = AuthenticationParameters {
        username: "test".to_string(),
        password: "test".to_string(),
    };
    let local3 = AuthenticationParameters {
        username: "Hello".to_string(),
        password: "World".to_string(),
    };
    let local4 = AuthenticationParameters {
        username: "user".to_string(),
        password: "password".to_string(),
    };

    user_data::ud_add_user(&local1);
    user_data::ud_add_user(&local2);
    user_data::ud_add_user(&local3);
    user_data::ud_add_user(&local4);

    true
}
pub fn auth_check_user(auth_params: &AuthenticationParameters) -> bool {
    return user_data::ud_is_access_granted(auth_params);
}
pub fn db_auth_check_user() -> bool {
    println!("pas implementer gang de rat");

    true
}

pub fn auth_login() -> AuthenticationParameters {
    let mut username = String::new();
    let mut password = String::new();
    print!("Username: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut username).expect("Failed to read line");
    print!("Password: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut password).expect("Failed to read line");

    AuthenticationParameters {
        username: username.trim_end_matches('\n').to_string(),
        password: password.trim_end_matches('\n').to_string(),
    }
}