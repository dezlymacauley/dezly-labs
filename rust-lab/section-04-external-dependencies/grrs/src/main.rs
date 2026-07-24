/*
    ABOUT: Getting the arguements

    To run this program:
    cargo dev -- pattern path
*/

use std::path::PathBuf;
use std::env::args;

fn main() {
    let pattern: String = args().nth(1).expect("no pattern given");
    let path: PathBuf = PathBuf::from(args().nth(2).expect("no path given"));

    println!("pattern: {pattern}, path: {path:?}");
}
