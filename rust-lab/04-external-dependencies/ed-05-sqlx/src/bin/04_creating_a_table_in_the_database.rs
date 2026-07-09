/*
    ABOUT: Creating a table in the database

    ___________________________________________________________________________

    I want to create a table called `tags`

    One of the things I've always wanted to build is a high-performance
    tag-centric image board.
    ___________________________________________________________________________

    Imagine an art gallery website that has millions of images.

    Each image has multiple tags, including the artist name, 
    as well as some words to describe that image, 
    so that it has a higher chance of being shown to a user searching
    for the image.

    E.g. There is a artwork by an artist called sakimichan,
    that has a white-haired woman with blue eyes, wearing a chinese dress.

    This image would have tags like:
    `white-haired_woman`, `blue-eyes`

    ___________________________________________________________________________
*/

// Standard Library Imports
use std::env;
use std::path::PathBuf;
use std::time::Duration;

// External Dependencies
use sqlx::postgres::PgPoolOptions;

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

#[tokio::main]
async fn main() {
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

    let connection_uri: String = format!(
        // database_type://username:password@host:port/database_name
        "{}://{}:{}@{}:{}/{}",
        config.database_type,
        config.user_name,
        config.user_password,
        config.host,
        config.port,
        config.database_name
    );

    //_________________________________________________________________________
    
    // STEP: 4 => Connect to Postgres

    // An asynchronous pool of SQLx database connections for Postgres
    let _connection_pool = match PgPoolOptions::new()
        .max_connections(10)
        .acquire_timeout(Duration::from_secs(5))
        .connect(&connection_uri)
        .await
    {
        Ok(pool) => pool,
        Err(error) => {
            eprintln!("\n❌ Failed to connect to Postgres:");
            eprintln!("{error}\n");
            return;
        }
    };

    println!("\n✅ Connected to Postgres\n");

    //_________________________________________________________________________
    
}
