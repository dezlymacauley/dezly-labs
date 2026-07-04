# Dezly Labs
_______________________________________________________________________________

## Available Labs

- 🦀 Rust
- 🐚 Bash
- 🐍 Python
- 🚢 Docker
- 🐘 Postgres
_______________________________________________________________________________

## Setting up the `cargo binstall` install command

Many of the labs I use are managed by `mise` in order to simply the setup
to one command: `mise setup`

To have the smoot
I recommend installing mise using 

_______________________________________________________________________________

### Step 1: Get the `rustup` command

If you are an `Arch Linux` user like I am, you can just run this command:

```bash
sudo pacman -S --needed rustup
```
_______________________________________________________________________________

If you are on another operating system, don't worry, 
Rustup is easy to install.

Click the link below and you will see an installation link for your system.

[Install Rustup](https://rustup.rs/)
_______________________________________________________________________________

### Step 2: Use `rustup` to install the necessary Rust tools

Once you have the Rustup command, use it to install / update the lastest
stable Rust toolchain. 

```bash
rustup update stable
```
_______________________________________________________________________________

Add `rust-analyzer` to the `stable` toolchain, 
to get language support for Rust projects.

```bash
rustup component add --toolchain stable rust-analyzer
```
_______________________________________________________________________________

Run this to check that you have everything needed for your Rust setup.

```bash
rustup --version
cargo --version
rustc --version
rustfmt --version
```
_______________________________________________________________________________

### Add the `.cargo/bin` directory to your `PATH` variable

This will allow you to use programs that are globally instaled 
by the `cargo` command.

_______________________________________________________________________________

If you use `fish` shell like I do (which is actually a Rust-powered shell),
then add this line...

```bash
fish_add_path "$HOME/.cargo/bin/"
```
...to this file `~/.config/fish/config.fish`
_______________________________________________________________________________
