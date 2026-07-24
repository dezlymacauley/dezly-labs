/*
    ABOUT: Simplifying the `.env` file

    ___________________________________________________________________________

    ___________________________________________________________________________
*/

use std::env;
use std::path::PathBuf;
use std::time::Duration;
use sqlx::postgres::PgPoolOptions;

fn load_dot_env() -> Result<(), dotenvy::Error> {
    let project_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let dot_env_file_path: PathBuf = project_root.join(".env");

    dotenvy::from_path(dot_env_file_path)
}

struct Config {
    database_url: String,
}

impl Config {
    fn from_dot_env_file() -> Result<Self, env::VarError> {
        Ok(
            Self {
                database_url: env::var("DATABASE_URL")?,
            }
        )
    }
}

#[tokio::main]
async fn main() {
    //_________________________________________________________________________

    // STEP: 1 => Load the `.env` file variables into the process environment

    if let Err(error_message) = load_dot_env() {
        eprintln!("\n❌ Failed to load `.env` variables: {error_message}\n");
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

    // STEP: 3 => Connect to Postgres

    let _connection_pool = match PgPoolOptions::new()
        .max_connections(10)
        .acquire_timeout(Duration::from_secs(5))
        .connect(&config.database_url)
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
