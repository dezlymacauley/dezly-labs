#!/usr/bin/env bash
#MISE description="🦀 Compile and run a program from src/bin"
#MISE quiet=true

# Stores the first cli argument as the file name
# For example, if you run:
#
# mise dev 01_the_main_function.rs
#
# Then file_name="01_the_main_function.rs"
file_name="$1"

# `%.rs` is used to remove the `.rs` file extension at the end
# So compiled_binary_name="01_the_main_function" 
compiled_binary_name="${file_name%.rs}"

# Runs the .rs file:
#
# Use the `cd` command to navigate to the directory where the file is,
# and then run this command:
# mise dev file_name.rs
#
# `--quiet` ensures that the only output shown in the terminal 
# is from the program
cargo run --quiet --bin "${compiled_binary_name}"
