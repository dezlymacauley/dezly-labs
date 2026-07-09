/*
    ABOUT: Keeping `fn main` tidy

    ___________________________________________________________________________

    1. group the logic of the program into function that perform
    a specific task.

    2. Create a struct for the configuration settings of the program.

    ___________________________________________________________________________
*/

// Standard Library Imports
use std::env;
use std::path::PathBuf;

// This function will attempt to load the variables listed in the `.env` file
// 1. If `load_dot_env` succeeds it will return an empty tuple (aka a unit)
// to the caller.
// 2. If the function fails, it will return `dotenvy::Error`.
fn load_dot_env() -> Result<(), dotenvy::Error> {
    // This is the absolute path to the Cargo.toml file of the project.
    // The Cargo.toml file is always at the root of a Rust project.
    let project_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));

    // The absolute file path of the `.env` file
    let dot_env_file_path: PathBuf = project_root.join(".env");

    // In Rust, the last expression of a function is automatically returned.
    dotenvy::from_path(dot_env_file_path)
}

struct Config {
    database_type: String,
    user_name: String,
    user_password: String,
    host: String,
    port: String,
    database_name: String,
}

impl Config {
    fn from_dot_env_file() -> Result<Self, env::VarError> {
        Ok(Self {
            database_type: env::var("DATABASE_TYPE")?,
            user_name: env::var("USER_NAME")?,
            user_password: env::var("USER_PASSWORD")?,
            host: env::var("HOST")?,
            port: env::var("PORT")?,
            database_name: env::var("DATABASE_NAME")?,
        })
    }
}

fn main() {
    //_________________________________________________________________________

    // STEP: 1 => Load the `.env` file variables into the process environment

    if let Err(error_message) = load_dot_env() {
        eprintln!("\n❌ Failed to load `.env` variables: {error_message}\n");

        // Always remember to add the `return` statement to make the program
        // exit after printing the message to stderr.
        return;
    }

    println!("\n✅ Successfully loaded `.env` variables");

    //_________________________________________________________________________

    // STEP: 2 => Create a configuration for the program

    let config: Config = match Config::from_dot_env_file() {
        Ok(config) => config,
        Err(error_mesage) => {
            eprintln!("\n❌ Failed to create a config:");
            eprintln!("\n{error_mesage}\n");
            return;
        }
    };

    //_________________________________________________________________________

    // STEP: 3 => Create a Postgres connection URI

    // This is the syntax that Postgres expects:
    // database_type://username:password@host:port/database_name

    // Please not that this is not a file path.
    // This is a URI (Uniform Resource Identifier) which is platform
    // independent so you don't need to worry about the `//`.
    // You can just store a URI in a String.

    let postgres_connection_uri: String = format!(
        // database_type://username:password@host:port/database_name
        "{}://{}:{}@{}:{}/{}",
        config.database_type,
        config.user_name,
        config.user_password,
        config.host,
        config.port,
        config.database_name
    );

    println!("\npostgres_connection_uri: {postgres_connection_uri}\n");

    //_________________________________________________________________________
}
