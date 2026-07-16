/*
    ABOUT: The `Command` struct

    The is a data type used for creating variables that give your Rust
    program the ability to run a program on your system.

    E.g.

    The `mkdir` command is used tot create a new directory.

    The `touch` command is used to create files.

    The `ls` command will list all files in a directory.
*/

// Brings the `Command` struct into scope.
use std::process::Command;

fn main() {
    Command::new("mkdir")
        .args(["-p", "log-files"])
        .status()
        .unwrap();

    Command::new("touch")
        .args([
            "log-files/log_a.txt",
            "log-files/log_b.txt",
            "log-files/log_c.txt",
        ])
        .status()
        .unwrap();

    println!();
    Command::new("ls").status().unwrap();
    println!();
}
