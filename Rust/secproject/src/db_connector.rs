use mysql::*;
use mysql::prelude::*;
use crate::auth::AuthenticationParameters;


fn establish_connection() -> Result<PooledConn, Box<dyn std::error::Error>> {
    let url = "mysql://root:root@localhost:3306/projet_sec_db";
    let pool = Pool::new(url)?;
    let conn = pool.get_conn()?;
    Ok(conn)
}

pub fn db_is_access_granted(auth: &AuthenticationParameters) -> bool {
    match establish_connection() {
        Ok(mut conn) => {
            // 👇 This is dangerous: direct string interpolation
            let query = format!(
                "SELECT username FROM users WHERE username = '{}' AND password = '{}'",
                auth.username, auth.password
            );

            let result: Result<Option<(String,)>, _> = conn.query_first(query);

            match result {
                Ok(Some(_)) => true,
                Ok(None) => false,
                Err(e) => {
                    eprintln!("Query error: {}", e);
                    false
                }
            }
        }
        Err(e) => {
            eprintln!("Connection error: {}", e);
            false
        }
    }
}
