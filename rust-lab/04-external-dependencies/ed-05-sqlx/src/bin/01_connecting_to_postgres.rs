/*
    ABOUT: Connecting to Postgres
    
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

fn main() {

    // This is how you get the absolute file path in Rust
    let project_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));

    // This is how you get the absolute file path of the `.env` file
    let dot_env_file_path: PathBuf = project_root.join(".env");

    println!("Does .env file exist? {}", dot_env_file_path.exists());

    // assert!();

}
