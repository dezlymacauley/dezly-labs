/*
    ABOUT: Creating a connection string

    ___________________________________________________________________________

    Install the following dependencies:

    cargo add sqlx --features postgres,runtime-tokio

    cargo add tokio --features full

    cargo add dotenvy

    ___________________________________________________________________________

    Create a `.env` file at the root of this project

    Use the file `.env.example` as a guide for what should be in the `.env`
    file

    ___________________________________________________________________________
*/

use std::path::PathBuf;

use dotenvy::Error;

use std::env;

fn main() {
    //_________________________________________________________________________

    // STEP: 1 => Use `dotenvy` to load the variables listed in the
    // `.env` file into the process environment

    // This is how you get the absolute file path in Rust
    let project_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));

    // This is how you get the absolute file path of the `.env` file
    let dot_env_file_path: PathBuf = project_root.join(".env");

    let dotenvy_status: Result<(), Error> =
        dotenvy::from_path(dot_env_file_path);

    match dotenvy_status {
        Ok(()) => {
            println!("\nSuccessfully loaded `.env` variables");
        }
        Err(error_message) => {
            println!("\nFailed to load `.env` variables: {error_message}\n");
            // Exit the program after showing the error message above.
            return;
        }
    }

    //_________________________________________________________________________

    // STEP: 2 => Use `env::var()` save environment variables from
    // the process environment into Rust variables.

    let database_type =
        env::var("DATABASE_TYPE").expect("DATABASE_TYPE is not set");

    let user_name = env::var("USER_NAME").expect("USER_NAME is not set");

    let user_password =
        env::var("USER_PASSWORD").expect("USER_PASSWORD is not set");

    let port = env::var("PORT").expect("PORT is not set");

    let host = env::var("HOST").expect("HOST is not set");

    let database_name =
        env::var("DATABASE_NAME").expect("DATABASE_NAME is not set");

    //_________________________________________________________________________

    // STEP: 3 => Create a Postgres connection URI
    
    // This is the syntax that Postgres expects:
    // database_type://username:password@host:port/database_name

    // Please not that this if not a file path.
    // This is a URI (Uniform Resource Identifier) which is platform
    // independent so you don't need to worry about the `//`.
    // You can just store a URI in a String.

    let postgres_connection_uri: String = format!(
        // database_type://username:password@host:port/database_name
        "{}://{}:{}@{}:{}/{}",
        database_type,
        user_name,
        user_password,
        host,
        port,
        database_name
    );

    println!("\nconnection_string: {postgres_connection_uri}\n");

    //_________________________________________________________________________
}
