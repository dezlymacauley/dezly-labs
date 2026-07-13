# Rust Workspace Setup Guide
_______________________________________________________________________________

## Setting up the Rust workspace
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
```
_______________________________________________________________________________

The project structure will look like this

```
.
├── .cargo
│   └── config.toml
├── .gitignore
├── Cargo.toml
├── rustfmt.toml
└── rust-toolchain.toml
```
_______________________________________________________________________________

Add this to the `.cargo/config.toml` file

```toml
[alias]
dev = "run --quiet"
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

## How to add your first Rust project to the workspace

_______________________________________________________________________________

Add the name of the project to the `members` section of the `Cargo.toml` file

For this example, I will be adding a project called `project-01`

```toml
[workspace]
resolver = "3"
members = [
    "project-01"
]
```
_______________________________________________________________________________

Create the project

```bash
cargo new --vcs none project-01
```

`--vcs none` will create the project without creating a `.git` directory.
_______________________________________________________________________________

## How to add another Rust project to the workspace

In this example, I'm adding another project called `project-02`

```toml
[workspace]
resolver = "3"
members = [
    "project-01",
    "project-02"
]
```
_______________________________________________________________________________

Create the second project

```bash
cargo new --vcs none project-02
```
_______________________________________________________________________________

The workspace structure should look like this now

```
.
├── .cargo
│   └── config.toml
├── .gitignore
├── project-01
│   ├── Cargo.toml
│   └── src
│       └── main.rs
├── project-02
│   ├── Cargo.toml
│   └── src
│       └── main.rs
├── Cargo.toml
├── rustfmt.toml
└── rust-toolchain.toml
```
_______________________________________________________________________________

To run a project, cd to project directory and run this command:

```bash
cargo dev
```
_______________________________________________________________________________

Whenever you are not working on your project,
you can delete the target directory to save disk space on your machine.

```bash
cargo clean
```
_______________________________________________________________________________

To rebuild the project after cleaning it, 
or if you have just cloned the repo from GitHub, just run this command:

```bash
cargo build
```
_______________________________________________________________________________

## Creating a project with multiple binaries

In this example, I'm adding another project called `project-03`

```toml
[workspace]
resolver = "3"
members = [
    "project-01",
    "project-02",
    "project-03"
]
```
_______________________________________________________________________________

Create the third project

```bash
cargo new --vcs none project-03
```
_______________________________________________________________________________

The project structure should look like this now

```
.
├── .cargo
│   └── config.toml
├── .gitignore
├── project-01
│   ├── Cargo.toml
│   └── src
│       └── main.rs
├── project-02
│   ├── Cargo.toml
│   └── src
│       └── main.rs
├── project-03
│   ├── Cargo.toml
│   └── src
│       └── main.rs
├── Cargo.lock
├── Cargo.toml
├── rustfmt.toml
└── rust-toolchain.toml
```
_______________________________________________________________________________

Delete the `project-03/src/` directory

```bash
rm -rf project-03/src/
```
_______________________________________________________________________________

Run the following command 

```bash
mkdir -p project-03/src/bin/
touch project-03/src/bin/01_program_one.rs
touch project-03/src/bin/02_program_two.rs
```
_______________________________________________________________________________

Add this to the `project-03/src/bin/01_program_one.rs` file

```rust
fn main() {
    println!("Program One")
}
```
_______________________________________________________________________________

Add this to the `project-03/src/bin/02_program_two.rs` file

```rust
fn main() {
    println!("Program Two")
}
```
_______________________________________________________________________________

To run `project-03/src/bin/02_program_one.rs`, do this:

First make sure that you are in the `project-03` directory

```bash
cd project-03
```
_______________________________________________________________________________

Then run this command

```bash
cargo run --quiet --bin 01_program_one
```
_______________________________________________________________________________
