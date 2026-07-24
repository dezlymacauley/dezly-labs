# Rust Workspace Setup Guide
_______________________________________________________________________________

Cargo allows you to create a Workspace.

This is essentially a directory that contains Rust projects.

Each Rust project in the directory is treated as a standalone project,
with its own dependencies.

However an external package can also be installed to the workspace,
so that all Rust projects in the workspace can use it.

_______________________________________________________________________________

In this guide I will be creating a Rust workspace that contains 
two Rust projects.

- `project-alpha` (a single-binary-project)
- `project-beta`  (a multi-binary-project)

_______________________________________________________________________________

Create the workspace directory

```bash
mkdir rust-workspace
```
_______________________________________________________________________________

Enter the project directory

```bash
cd rust-workspace
```
_______________________________________________________________________________

Initialize the workspace

```bash
cargo init --vcs none
```

The flag `--vcs none` will ensure that no version control system is setup 
in the project. I prefer to setup version control manually.

_______________________________________________________________________________

Your `Cargo.toml` file will look like this

```toml
[package]
name = "rust-workspace"
version = "0.1.0"
edition = "2024"

[dependencies]
```

_______________________________________________________________________________

Add this to the end of the `Cargo.toml` file

```toml
[package]
name = "rust-workspace"
version = "0.1.0"
edition = "2024"

[dependencies]

[workspace]
resolver = "3"
members = []
```
_______________________________________________________________________________

Add the first project

```bash
cargo new project-alpha
```
_______________________________________________________________________________

Add the second project

```bash
cargo new project-beta
```
_______________________________________________________________________________

Cargo will automatically add both projects to the workspace

```toml
[package]
name = "rust-workspace"
version = "0.1.0"
edition = "2024"

[dependencies]

[workspace]
resolver = "3"
members = ["project-alpha","project-beta"]
```
_______________________________________________________________________________

I like to list each project on a separate line.

This will make it easier to read as more projects are added to the workspace.

```toml
[package]
name = "rust-workspace"
version = "0.1.0"
edition = "2024"

[dependencies]

[workspace]
resolver = "3"
members = [
    "project-alpha",
    "project-beta"
]
```
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
# This creates a custom cargo command called `cargo dev`
# `cargo p` is the same as `cargo run --quiet -p`
p = "run --quiet -p"

# This creates a custom cargo command called `cargo dev`
# `cargo dev` is the same as `cargo run --quiet`
dev = "run --quiet"

# This creates a custom cargo command called `cargo bin`
# `cargo bin` is the same as `cargo run --quiet --bin`
bin = "run --quiet --bin"
```
_______________________________________________________________________________

Replace the contents of the `project-alpha/src/main.rs` file with this

```rust
fn main() {
    println!("\nProject Alpha\n");
}
```
_______________________________________________________________________________

Delete the `project-beta/src/main.rs` file

```bash
rm project-beta/src/main.rs
```
_______________________________________________________________________________

Create a `bin` directory inside the `src` directory of `project-beta`

```bash
mkdir -p project-beta/src/bin/
```
_______________________________________________________________________________

Add two programs to the `src/bin/` directory of `project-beta`

```bash
touch project-beta/src/bin/program_01.rs
touch project-beta/src/bin/program_02.rs
```
_______________________________________________________________________________

Add this to the `project-beta/src/bin/program_01.rs` file

```rust
fn main() {
    println!("\nProject Beta - Program 01\n")
}
```
_______________________________________________________________________________

Add this to the `project-beta/src/bin/program_02.rs` file

```rust
fn main() {
    println!("\nProject Beta - Program 02\n")
}
```
_______________________________________________________________________________

`project-alpha` is a `single-binary-project`, 
so there are two ways to run it:

_______________________________________________________________________________

`Method 1`: Run the binary from the root of the workspace

```bash
cargo p project-alpha
```
_______________________________________________________________________________

`Method 2`: Enter the project and run the binary

```bash
cd project-alpha
cargo dev
```
_______________________________________________________________________________

Return to the root of the workspace

```bash
cd ..
```
_______________________________________________________________________________

`project-beta` is a `multi-binary-project`,
so to run a specific binary (aka executable program) from project-beta, 
you need to enter the project directory.


```bash
cd project-beta
```
_______________________________________________________________________________

To run `program_01.rs` of `project-beta`

```bash
cargo bin program_01
```
_______________________________________________________________________________

To run `program_02.rs` of `project-beta`

```bash
cargo bin program_02
```
_______________________________________________________________________________

Return to the root of the workspace

```bash
cd ..
```
_______________________________________________________________________________

Whenever you are not usign the project,
you can delete the target directory to save disk space.

Cargo already has a built-in command for this.

```bash
cargo clean
```
_______________________________________________________________________________
