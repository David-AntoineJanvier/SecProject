use crate::auth;

const MAX_USER_NUMBER: u8 = 5;

#[derive(Debug, Clone)]
pub struct ProfileData
{
    pub user_login : auth::AuthenticationParameters,
    pub data : String,
}

static mut DATABASE : Vec<ProfileData> = Vec::new();

fn find_profile(username: &String, dst: &mut ProfileData) -> bool
{
    let mut success = false;
    unsafe
    {
        for profile in DATABASE.iter()
        {
            if profile.user_login.username.trim() == username.trim()
            {
                success = true;
                *dst = profile.clone();
            }
        }
    }
    success
}

pub fn ud_add_user(user: &auth::AuthenticationParameters) -> bool 
{
    let mut success = false;
    unsafe
    {
        if DATABASE.len() < MAX_USER_NUMBER as usize
        {
            let profile = ProfileData{user_login:user.clone(), data:"".to_string()};
            DATABASE.push(profile);
            success = true;
        }
    }
    success
}

pub fn ud_is_access_granted(auth_params: &auth::AuthenticationParameters) -> bool 
{
    let mut success = false;
    let mut user_profile = ProfileData{user_login:auth::AuthenticationParameters{username:"dbg".to_string(), password:"dbg".to_string()},
                                        data:"dbg".to_string()};
    let found = find_profile(&(auth_params.username), &mut user_profile);
    if found
    {
        success = auth_params.password.trim() == user_profile.user_login.password.trim();
    }

    success
}

pub fn ud_add_user_data(username: &String, data_buffer: String) 
{
    let mut user_profile = ProfileData{user_login:auth::AuthenticationParameters{username:"dbg".to_string(), password:"dbg".to_string()},
                                        data:"dbg".to_string()};
    let found = find_profile(&username, &mut user_profile);
    if found
    {
        user_profile.data = data_buffer.trim().to_string().clone();
        unsafe
        {
            let index = DATABASE.iter().position(|x| x.user_login.username.trim() == username.trim()).unwrap();
            DATABASE[index] = user_profile;
        }
    }
}

pub fn ud_get_user_data(username: &String) -> String
{
    let mut return_string = "".to_string();
    let mut user_profile = ProfileData{user_login:auth::AuthenticationParameters{username:"dbg".to_string(), password:"dbg".to_string()},
                                        data:"dbg".to_string()};
    let found = find_profile(&username, &mut user_profile);
    if found
    {
        return_string = user_profile.data;
    }

    return_string
}
