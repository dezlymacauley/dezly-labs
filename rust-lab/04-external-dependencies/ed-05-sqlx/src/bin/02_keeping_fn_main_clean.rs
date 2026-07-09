/*
    ABOUT: Keeping `fn main` clean

    ___________________________________________________________________________

    ___________________________________________________________________________
*/

// Standard Library Imports
use std::path::PathBuf;
use std::env;

// External Dependencies
use dotenvy::Error;

fn load_dot_env() -> Result<(), Error> {

    // This is the absolute path to the Cargo.toml file of the project.
    // The Cargo.toml file is always at the root of a Rust project.
    let project_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));

    // The absolute file path of the `.env` file
    let dot_env_file_path: PathBuf = project_root.join(".env");

    // In Rust, the last expression of a function is automatically returned.
    // `from_path` returns a Result enum.
    // Result <(), Error> 
    dotenvy::from_path(dot_env_file_path)
}

fn main() {

    //_________________________________________________________________________

    // STEP: 1 => Load the variables listed in the `.env` file into the
    // process environment of the program


    // let dotenvy_status: Result<(), Error> =
    //     dotenvy::from_path(dot_env_file_path);
    //
    // match dotenvy_status {
    //     Ok(()) => {
    //         println!("\nSuccessfully loaded `.env` variables");
    //     }
    //     Err(error_message) => {
    //         println!("\nFailed to load `.env` variables: {error_message}\n");
    //         // Exit the program after showing the error message above.
    //         return;
    //     }
    // }

    //_________________________________________________________________________

    // STEP: 2 => Use `env::var()` save environment variables from
    // the process environment into Rust variables.

    let database_name =
        env::var("DATABASE_NAME").expect("DATABASE_NAME is not set");

    let host = env::var("HOST").expect("HOST is not set");

    let port = env::var("PORT").expect("PORT is not set");

    let user_name = env::var("USER_NAME").expect("USER_NAME is not set");

    let user_password =
        env::var("USER_PASSWORD").expect("USER_PASSWORD is not set");

    //_________________________________________________________________________

    // STEP: 3 => Use the Rust variables to create a connection string
    // that will be used to connect to the database

    // This is the syntax that Postgres expects:
    // database_type://username:password@host:port/database_name

    // This is known as URI (Uniform Resource Identifier)
    // It is not a file path, so you don't need to worry about the `//`,
    // because the URI is platform independent.

    let connection_string: String = format!(
        // database_type://username:password@host:port/database_name
        "postgres://{user_name}:{user_password}@{host}:{port}/{database_name}"
    );

    println!("\nconnection_string: {connection_string}\n");

    //_________________________________________________________________________
    





    //_________________________________________________________________________
}
