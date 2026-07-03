# 🐘 Postgres Lab
_______________________________________________________________________________

## Setup Guide
_______________________________________________________________________________

Use the `pwd` command to confirm that you are in this directory
ensure that you are in this directory: 

Check that this is the ending of the output

```bash
dezly-labs/postgres-lab
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

```bash
mise tasks
```
_______________________________________________________________________________

You can use this to manage the Docker service, 
and run Docker compose commands

```
Name        Description
containers  🚢 View the id, name, and status of all containers
images      📜 List all downloaded container images
pgl-clean   🧼 Delete the Postgres Lab volume
pgl-down    🐘 Setup the Postgres Lab Docker container
pgl-up      ❌ Shutdown the Postgres Lab Docker container
ports       🔌 View the id, name, and port of all containers
status      🚥 Check if the Docker service is active
toggle      🔁 Toggle the status of the Docker service
volumes     📦 List container volumes
```
_______________________________________________________________________________

Run this command, to check i the Docker service is active

```bash
mise status
```
_______________________________________________________________________________

If the Docker service is innactive, then run:

```bash
mise toggle
```
_______________________________________________________________________________

To run the `compose.yaml` file

```bash
docker compose up -d
```
_______________________________________________________________________________

When you are done with the `postgres-lab`, 
you can run this command to shut down the service.

```sh
docker compose down
```
_______________________________________________________________________________
