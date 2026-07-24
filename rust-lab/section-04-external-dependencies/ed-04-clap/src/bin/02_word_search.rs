/*

    ABOUT: Word search

    cargo run --quiet --bin 02_word_search \
        -- hello example.txt

*/

// This allows you to use the `Parser` macro on a struct
use clap::Parser;

use std::fs::read_to_string;
use std::path::PathBuf;

#[derive(Parser)]
struct Cli {
    pattern: String,
    path: PathBuf,
}

fn main() {
    let args = Cli::parse();

    let content = read_to_string(&args.path).expect("could not read file");

    for line in content.lines() {
        if line.contains(&args.pattern) {
            println!("{}", line);
        }
    }
    // hello world
    // Another line with hello in it.
}
