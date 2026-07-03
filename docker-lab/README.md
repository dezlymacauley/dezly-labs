# 🚢 Docker Lab
_______________________________________________________________________________

## Setup Guide
_______________________________________________________________________________

Use the `pwd` command to confirm that you are in this directory
ensure that you are in this directory: 

Check that this is the ending of the output

```bash
dezly-labs/docker-lab
```
_______________________________________________________________________________

Give mise permission to read from the `mise.toml` file 

```bash
mise trust
```
_______________________________________________________________________________

Make the bash scripts in the `.mise-tasks` directory executable,
so that `mise` can create `mise tasks` using those scripts.

```bash
chmod +x .mise-tasks/*.bash
```

_______________________________________________________________________________

`mise-tasks` are a functionality in mise that allows you to create custom
commands from the name of a file that contains a script 
and display all of them in a cool terminal menu.

E.g. `.mise-taks/status.bash`

Will create the command `mise status`.

Note: 
- Do not create a file like `run.bash` because `run` is a reserved 
word in the `mise` cli

_______________________________________________________________________________

To view a list of mise-tasks, run this command:

```
mise tasks
```
_______________________________________________________________________________
