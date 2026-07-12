/*

    ABOUT: clap

    To add clap to your project, run this command:
    cargo add clap --features derive

    To run this program:
    cargo run --quiet --bin name_of_this_file_without_the_extension \
        -- pattern file

*/

// This allows you to use the `Parser` macro on a struct
use clap::Parser;

use std::path::PathBuf;

#[derive(Parser)]
struct Cli {
    pattern: String,
    path: PathBuf
}

fn main() {
    let args = Cli::parse();

    println!("pattern: {}", args.pattern);
    println!("path: {:?}", args.path);

    // pattern: pattern
    // path: "file"
}
