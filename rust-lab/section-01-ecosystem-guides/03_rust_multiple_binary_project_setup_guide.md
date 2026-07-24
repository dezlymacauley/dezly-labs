# Rust Multiple Binary Project Setup Guide
_______________________________________________________________________________

Create the project directory

```bash
mkdir rust-multiple-binary-project
```
_______________________________________________________________________________

Enter the project directory

```bash
cd rust-multiple-binary-project
```
_______________________________________________________________________________

Initialize the project

```bash
cargo init --vcs none
```

The flag `--vcs none` will ensure that no version control system is setup 
in the project. I prefer to setup version control manually.

_______________________________________________________________________________

Create a `rustfmt.toml` file

```bash
touch rustfmt.toml
```
_______________________________________________________________________________

Add this to the `rustfmt.toml` file

```toml
# To learn how to change the default values for various options, 
# use the guide below:
# https://rust-lang.github.io/rustfmt

# Maximum width of each line
# Default value: 100
max_width = 80
```
_______________________________________________________________________________

Create a `.gitignore` file

```bash
touch .gitignore
```
_______________________________________________________________________________

Add this to the file

```gitignore
# Build output
target/
```
_______________________________________________________________________________

Create a `rust-toolchain.toml` file

```bash
touch rust-toolchain.toml
```
_______________________________________________________________________________

Add this to the `rust-toolchain.toml` file

```toml
[toolchain]
channel = "stable"
components = [ "rust-analyzer" ]
```

This will ensure that your project always uses the `stable toolchain`,
and that it automatically downloads the version of `rust-analyzer` for 
that version of the Rust compiler.
_______________________________________________________________________________

If you want your project to use a specific version of Rust, then do this:

```toml
[toolchain]
channel = "1.96.1"
components = [ "rust-analyzer" ]
```
_______________________________________________________________________________

Then build the project

```toml
cargo build
```

When you run the `cargo build` command, 
rustup will check the `rust-toolchain.toml` file and ensure that the
project is using the specific channel that was specified in the file 
and that `rust-analyzer` is installed for that specific toolchain. 
_______________________________________________________________________________

Create a `.cargo` directory

```bash
mkdir .cargo  
```
_______________________________________________________________________________

Create a `config.toml` file inside the `.cargo` directory. 

This will allow you to create aliases for cargo commands.

```bash
touch .cargo/config.toml
```
_______________________________________________________________________________

Add this to the `.cargo/config.toml` file

```toml
[alias]
# This creates a custom cargo command called `cargo bin`
# `cargo bin` is the same as `cargo run --quiet --bin`
bin = "run --quiet --bin"
```
_______________________________________________________________________________

Delete the `src/main.rs` file

```bash
rm src/main.rs
```
_______________________________________________________________________________

Create a `bin` directory inside the `src` directory

```bash
mkdir -p src/bin/
```
_______________________________________________________________________________

Add two programs to the `src/bin/` directory

```bash
touch src/bin/program_01.rs
touch src/bin/program_02.rs
```
_______________________________________________________________________________

Add this to the `src/bin/program_01.rs` file

```rust
fn main() {
    println!("\nProgram 01\n");
}
```
_______________________________________________________________________________

Add this to the `src/bin/program_01.rs` file

```rust
fn main() {
    println!("\nProgram 02\n");
}
```
_______________________________________________________________________________

To run program use the `cargo bin` alias with this syntax:

cargo dev name_of_program

#### Note: 
- Don't add the `.rs` file extension. Only use the name of the file.

_______________________________________________________________________________

To run the file `src/program_01.rs`

```bash
cargo bin program_01
```
_______________________________________________________________________________

To run the file `src/program_02.rs`

```bash
cargo bin program_02
```
_______________________________________________________________________________

Whenever you are not working on your project,
you can delete the target directory to save disk space.

Cargo already has a built-in command for this.

```bash
cargo clean
```
_______________________________________________________________________________
