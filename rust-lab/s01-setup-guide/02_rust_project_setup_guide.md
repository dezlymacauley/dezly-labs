# Rust Project Setup Guide
_______________________________________________________________________________

Create the project directory

```sh
mkdir rust-project
```
_______________________________________________________________________________

Enter the project directory

```sh
cd rust-project
```

_______________________________________________________________________________

Initialize the project

```sh
cargo init --vcs none
```

The flag `--vcs none` will ensure that no version control system is setup 
in the project. I prefer to setup the `git` version control system myself.

_______________________________________________________________________________

Create a `rustfmt.toml` file

```sh
touch rustfmt.toml
```
_______________________________________________________________________________

Add this to the rustfmt.toml file
```toml
max_width = 80
tab_spaces = 4
```
_______________________________________________________________________________

Create a `.gitignore` file
```sh
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
```sh
touch rust-toolchain.toml
```
_______________________________________________________________________________

Add this to the `rust-toolchain.toml` file
```toml
[toolchain]
channel = "stable"
components = [ "rust-analyzer" ]
```

This will ensure that your project always uses the latest version 
of the Rust compiler and that it automatically downloads the version 
of `rust-analyzer` for that version of the Rust compiler.
_______________________________________________________________________________

If you want a specific version of Rust,
do this:

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
rustup will have a check the `rust-toolchain.toml` file and ensure that the
project is using the specific channel that was specified in the file 
and that `rust-analyzer` is installed for that specific toolchain. 

_______________________________________________________________________________

Create a `.cargo` directory

```sh
mkdir .cargo  
```
_______________________________________________________________________________

Create a `config.toml` file inside the `.cargo` directory. 

This will allow you to create aliases for cargo commands.

```sh
touch .cargo/config.toml
```

Add this to the file to create an alias called `dev`,
```toml
[alias]
dev = "run --quiet"
```
_______________________________________________________________________________

Replace the contents of the `src/main.rs` file with this
```rust
fn main() {
    println!("\nRust Project\n");
}
```
_______________________________________________________________________________

To run you project use the `dev` alias from your Cargo config

```sh
cargo dev
```
_______________________________________________________________________________

Whenever you are not working on your project,
you can delete the target directory to save disk space.

Rust already has a built-in command for this.
```sh
cargo clean
```
_______________________________________________________________________________

To rebuild the project after cleaning it, 
or if you have just cloned the repo from GitHub, 
all you have to do is run `cargo build`

_______________________________________________________________________________
