# Setting up a Python project with Mise and uv  
_______________________________________________________________________________

Create the project directory

```bash
mkdir python-project
```
_______________________________________________________________________________

Enter the project directory

```bash
cd python-project
```
_______________________________________________________________________________

Create a `mise.toml` file

```bash
touch mise.toml
```
_______________________________________________________________________________

Give mise permission to read the `mise.toml` file in the directory

```bash
mise trust
```
_______________________________________________________________________________

Install the following tools with mise

```bash
mise use uv@latest
mise use ruff@latest
```
_______________________________________________________________________________

Your `mise.toml` file should look like this now:

```toml
[tools]
ruff = "latest"
uv = "latest"
```
_______________________________________________________________________________

Add this to the end your `mise.toml` file,
to make working with Python virtual environments more convinient.

```toml
[settings]
python.uv_venv_auto = "source"
```
_______________________________________________________________________________

Normally when you enter a Python project that has a virtual environment,
you need to run the command `source .venv/bin/activate` to activate
the Python virtual environment when you enter the directory.

And then when you exit the project directory you'd hav to 
run the command `deactivate`

Now you don't have to do that. `mise` will use `uv` to automatically run
those commands for you.

A Python virtual environment will be created later in this guide using uv.
_______________________________________________________________________________

Create a `.gitignore` file

```sh
touch .gitignore
```
_______________________________________________________________________________

Add this to the `.gitignore` file. 

```gitignore
# The Python virtual environment
# This is where uv will install the project dependencies
.venv/

# Used by ruff to speed up code formatting
.ruff_cache/ 

# Created by Python to speed up importing of modules
__pycache__/
```
_______________________________________________________________________________

Create a `ruff.toml` file

```bash
touch ruff.toml
```
_______________________________________________________________________________

Add this to the file:

```toml
line-length = 80
```
_______________________________________________________________________________

#### Note: 

- Do not use mise to set the Python version for your project,
that should be set by **uv**

- Simply use `mise` to check what versions of Python are available 
on Python.org

_______________________________________________________________________________

Use `mise` to view a list of available Python versions

```bash
mise ls-remote python
```
_______________________________________________________________________________

or simply run this to check what the latest version of Python is:

```bash
mise latest python
```
_______________________________________________________________________________

Use uv to set a specific version of Python for your project:

```bash
uv init --bare -p 3.14.6
```

The `--bare` flag will create a minimal Python project setup that only
has a `pyproject.toml` file.

The `-p` flag just means Python version,
and it is followed by a specific version number of Python that you want
your project to use.
_______________________________________________________________________________

This will create a `pyproject.toml` file that looks like this

```toml
[project]
name = "python-project"
version = "0.1.0"
requires-python = ">=3.14.6"
dependencies = []
```
_______________________________________________________________________________

Create a `.python-version` file that has the same version number as your
pyproject.toml file.

```bash
echo 3.14.6 > .python-version
```

This will be used by `uv` to keep track of what version of Python will be
used in the Python virtual environment.
_______________________________________________________________________________

Use `uv` to create a Python virtual environment using 
the `.python-version` file

```bash
uv venv
```

This will create a `.venv` directory in your project.

When you add dependencies to your project
This is where `uv` will install those dependencies to the `.venv` directory.

_______________________________________________________________________________

You will see a message like this. Do not run the activate command

```
Using CPython 3.14.6
Creating virtual environment at: .venv
Activate with: source .venv/bin/activate.fish
```
_______________________________________________________________________________

Run this command instead.

```bash
uv sync
```
_______________________________________________________________________________

Then exit the project directory

```bash
cd ..
```
_______________________________________________________________________________

And re-enter the project directory

```bash
cd python-project
```
_______________________________________________________________________________

Now run this command to confirm that your project is using the Python from
your virtual enviroment.

```bash
which python | sed "s|$PWD/||"
```

If you see this at the end of your path,
then that means that your project is using the virtual enviroment 
that was set by uv.

```
.venv/bin/python
```
_______________________________________________________________________________

Create an `src` directory. 

```bash
mkdir src
```

`src` stands for source.  This directory will keep your project neat by
separating your source files (aka project code) from the configuration files
and the `.venv` directory at the root of the project
_______________________________________________________________________________

Inside the `src` directory, 
create a directory that has the same name as the project, 
but uses `underscores` to separate the name.

```bash
mkdir -p src/python_project
```

So `python_project` inside of `python-project`
_______________________________________________________________________________

Create an `dunder init` file to let Python know that the directory
`python_project`, is a module.

```bash
touch src/python_project/__init__.py
```

#### Note
- It's two underscores on both side. 
- That's why you'll sometimes hear people refer to this file 
as dunder init (short for double undercore init).
_______________________________________________________________________________

Create a `dunder main` file to create the entry point of the package.

```bash
touch src/python_project/__main__.py
```
_______________________________________________________________________________

Create lib.py file

```bash
touch src/python_project/lib.py
```

#### Note
`lib` is short for library. 
_______________________________________________________________________________

Add this to the `src/python_project/lib.py` file

```python
def print_hello_world() -> None:
    print("Hello world")
```
_______________________________________________________________________________

Add this to the `src/python_project/__main__.py` file

```python
from python_project.lib import print_hello_world

def main() -> None:
    print_hello_world()

if __name__ == "__main__":
    main()
```
_______________________________________________________________________________


Create a `.mise-tasks` directory
```sh
mkdir .mise-tasks
```

This is a special directory that mise uses to create
custom commands using the name of a script that you place inside it.
_______________________________________________________________________________

Then create the following bash scripts:
```sh
touch .mise-tasks/clean.bash
touch .mise-tasks/format.bash
touch .mise-tasks/setup.bash
```
_______________________________________________________________________________

Make the bash scripts in mise-tasks executable
```sh
chmod +x .mise-tasks/*.bash
```
_______________________________________________________________________________

Add this to the `.mise-tasks/clean.bash` file

```sh
#!/usr/bin/env bash
#MISE description="🧼 Remove venv and caches directories"
#MISE quiet=true

rm -rf __pycache__
rm -rf .ruff_cache
rm -rf .venv
```

Note: `rm -rf` will only work on Linux and MacOS.
_______________________________________________________________________________

Add this to the `.mise-tasks/format.bash` file:

```sh
#!/usr/bin/env bash
#MISE description="📜 Format all Python files using ruff"
#MISE quiet=true

ruff format .
```
_______________________________________________________________________________

Add this to the `.mise-tasks/setup.sh` file
```sh
#!/usr/bin/env bash
#MISE description="👷 Setup the project"
#MISE quiet=true

# Ensure that this is a clean build of the virtual environment
rm -rf __pycache__
rm -rf .ruff_cache
rm -rf .venv

# Rebuild the the virtual environment and install the dependencies
uv sync
```
_______________________________________________________________________________
