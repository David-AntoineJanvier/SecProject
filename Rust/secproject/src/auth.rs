use crate::user_data;
use std::io::{self, Write};

pub fn auth_init() -> bool {
    let local1 = user_data::AuthenticationParameters {
        username: "Admin".to_owned(),
        password: "password".to_owned(),
    };
    let local2 = user_data::AuthenticationParameters {
        username: "test".to_owned(),
        password: "test".to_owned(),
    };
    let local3 = user_data::AuthenticationParameters {
        username: "Hello".to_owned(),
        password: "World".to_owned(),
    };
    let local4 = user_data::AuthenticationParameters {
        username: "user".to_owned(),
        password: "password".to_owned(),
    };

    user_data::ud_add_user(&local1);
    user_data::ud_add_user(&local2);
    user_data::ud_add_user(&local3);
    user_data::ud_add_user(&local4);

    return true;
}
pub fn auth_check_user(auth_params: user_data::AuthenticationParameters) -> bool {
    return user_data::ud_is_access_granted(auth_params);
}
pub fn db_auth_check_user() -> bool {
    println!("pas implementer gang de rat");
    return true;
}

pub fn auth_login() -> user_data::AuthenticationParameters {
    let mut username = String::new();
    let mut password = String::new();
    print!("Username: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut username).expect("Failed to read line");
    print!("Password: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut password).expect("Failed to read line");
    return user_data::AuthenticationParameters {
        username: username.trim_end_matches('\n').to_owned(),
        password: password.trim_end_matches('\n').to_owned(),
    };
}