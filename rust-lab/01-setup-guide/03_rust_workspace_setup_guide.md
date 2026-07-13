# Rust Workspace Setup Guide
_______________________________________________________________________________

Create the workspace directory

```bash
mkdir rust-workspace
```
_______________________________________________________________________________

Enter the workspace directory

```bash
cd rust-workspace
```
_______________________________________________________________________________

Create the workspace structure

```bash
touch .gitignore
touch Cargo.toml
touch rust-toolchain.toml
touch rustfmt.toml

mkdir -p .cargo
touch .cargo/config.toml

mkdir -p project-01/src/bin/
touch project-01/src/bin/01_program_one_of_project_one.rs
touch project-01/src/bin/01_program_two_of_project_one.rs

mkdir -p project-02/src/bin/
touch project-02/src/bin/01_program_one_of_project_two.rs
touch project-02/src/bin/01_program_two_of_project_two.rs
```
_______________________________________________________________________________

The project structure will look like this

```
.
├── .cargo
│   └── config.toml
├── .gitignore
├── project-01
│   └── src
│       └── bin
│           ├── 01_program_one_of_project_one.rs
│           └── 01_program_two_of_project_one.rs
├── project-02
│   └── src
│       └── bin
│           ├── 01_program_one_of_project_two.rs
│           └── 01_program_two_of_project_two.rs
├── Cargo.toml
├── rust-toolchain.toml
└── rustfmt.toml
```
_______________________________________________________________________________

Add this to the `.cargo/config.toml` file

```toml

```
_______________________________________________________________________________

Add this to the `.gitignore` file

```gitignore
# Build output
target/
```
_______________________________________________________________________________

Add this to the `Cargo.toml` file

```toml
[workspace]
resolver = "3"
members = [
    "project-01",
    "project-02"
]
```
_______________________________________________________________________________

Add this to the `rust-toolchain.toml` file

```toml
[toolchain]
channel = "stable"
components = [ "rust-analyzer" ]
```
_______________________________________________________________________________

Add this to the `rustfmt.toml` file

```toml
max_width = 80
tab_spaces = 4
```
_______________________________________________________________________________

Add this to `project-01/src/bin/01_program_one_of_project_one.rs`

```bash

```
_______________________________________________________________________________

Add this to `project-01/src/bin/01_program_two_of_project_one.rs`

_______________________________________________________________________________

Add this to `project-02/src/bin/01_program_one_of_project_two.rs`

_______________________________________________________________________________

Add this to `project-02/src/bin/01_program_two_of_project_two.rs`

_______________________________________________________________________________

Here's how to run a program




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
