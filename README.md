# 🧑‍🔬   Dezly Labs
_______________________________________________________________________________

## Available Labs

- 🐚 Bash
- ⚙️ C
- 🚢 Docker
- 🐹 Go
- ☸️ Kubernetes
- 🐘 Postgres
- 🐍 Python
- 🦀 Rust
_______________________________________________________________________________

## Setting up the `cargo binstall` install command

Many of the labs I use are managed by `mise` in order to simply the setup
to one command: `mise setup`

To have the best experience when using `Dezly Labs`, 
I recommend installing mise using the `cargo-binstall` command,
since mise is a Rust-based tool.

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

Then set the `stable` version as the default toolchain

```bash
rustup default stable
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

### Step 3: Add the `.cargo/bin` directory to your `PATH` variable

This will allow you to use programs that are globally instaled 
by the `cargo` command.

_______________________________________________________________________________

If you use `fish` shell like I do (which is actually a Rust-based shell),
then add this line...

```bash
fish_add_path "$HOME/.cargo/bin/"
```
...to this file `~/.config/fish/config.fish`
_______________________________________________________________________________

If you use `bash` then add this line...

```bash
export PATH="$HOME/.cargo/bin:$PATH"
```

...to this file `~/.bashrc`

_______________________________________________________________________________

If you use `zsh` then add this line...

```bash
export PATH="$HOME/.cargo/bin:$PATH"
```

...to this file `~/.zshrc`

_______________________________________________________________________________

### Step 4: Use `cargo` to get the `cargo-binstall` command

```bash
cargo install cargo-binstall --locked
```

- Note: Please be patient. This command will take a few minutes to build
`cargo-binstall` from source.

On my machine it took about `5 minutes`

_______________________________________________________________________________

### Step 5: Use `cargo-binstall` to install `mise`

This is what is recommend by the official mise documentation.

```sh
cargo binstall mise
```
_______________________________________________________________________________

### Step 6: Add `mise` to your shell, and restart your machine

_______________________________________________________________________________

If you use `fish` shell like I do, then add these lines...

```bash
if command -q mise
    mise activate fish | source
end
```
...to end this file `~/.config/fish/config.fish`

_______________________________________________________________________________

If you use `bash` then add these lines

```bash
if command -v mise >/dev/null 2>&1; then
    eval "$(mise activate bash)"
fi
```
...to end this file `~/.bashrc`

_______________________________________________________________________________

If you use `zsh` then add these lines

```bash
if command -v mise >/dev/null 2>&1; then
    eval "$(mise activate zsh)"
fi
```
...to end this file `~/.zshrc`

_______________________________________________________________________________

### Step 7: Use `mise` to install `usage` globally

`usage` is required by mise to provide auto completion

```bash
mise use -g usage
```
_______________________________________________________________________________

### Step 8: Add the completion script to your shell

If you use `fish` shell like I do, run this command

```bash
mise completion fish > ~/.config/fish/completions/mise.fish
```
_______________________________________________________________________________

If you use `bash`, run this command

```bash
# This requires bash-completion to be installed
mkdir -p ~/.local/share/bash-completion/completions/
mise completion bash --include-bash-completion-lib \
    > ~/.local/share/bash-completion/completions/mise
```
_______________________________________________________________________________

If you use `zsh`, run this command

```bash
# If you use oh-my-zsh, there is a `mise` plugin. Update your .zshrc file with:
# plugins=(... mise)

# Otherwise, look where zsh search for completions with
echo $fpath | tr ' ' '\n'

# if you installed zsh with `apt-get` for example, this will work:
mkdir -p /usr/local/share/zsh/site-functions
mise completion zsh  > /usr/local/share/zsh/site-functions/_mise
```
_______________________________________________________________________________

Run this command to check that your setup is fine

```bash
mise doctor
```
_______________________________________________________________________________

If you see this output, you are ready to start using `mise`

```
No problems found
```
_______________________________________________________________________________

🧑‍🔬   Enjoy using **Dezly Labs**!
_______________________________________________________________________________
