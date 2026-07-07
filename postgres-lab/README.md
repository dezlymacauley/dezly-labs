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

Run this command to ensure `pgcli` and `sqruff` are installed,
and to ensure that the `Docker service` is running.

```bash
mise setup
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

## Mise Tasks
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
containers  🚢 View the ID, name, and status of all containers
images      📜 List all downloaded container images
pgl-admin   🔩 Use psql to perform admin tasks on the Postgres cluster
pgl-clean   🧼 Delete the Postgres Lab volume
pgl-down    ❌ Shut down the Postgres Lab
pgl-up      🐘 Set up the Postgres Lab
ports       🔌 View the ID, name, and ports of all containers
status      🚥 Check status of the Docker service
toggle      🔁 Toggle the status of the Docker service
volumes     📦 List container volumes
```
_______________________________________________________________________________

## Using the Postgres Lab
_______________________________________________________________________________

Run this command, to check if the Docker service is active

```bash
mise status
```
_______________________________________________________________________________

If the Docker service is innactive, run this command

```bash
mise toggle
```
_______________________________________________________________________________

Run this command to set up the Postgres Lab

```bash
mise pgl-up
```
_______________________________________________________________________________

Run this command to perform admin tasks on the Postgres cluster

```bash
mise pgl-admin
```
_______________________________________________________________________________

You will be logged into the `psl prompt`, which looks like this

```
psql (18.4)
Type "help" for help.

postgres=#
```
_______________________________________________________________________________

To exit the prompt, type `\q`, and then press the `Enter` key

_______________________________________________________________________________

To make database queries run this command

```bash
mise query
```
_______________________________________________________________________________

When you are done using Postgres Lab,
run this command to shutdown the Docker container.

```sh
mise pgl-down
```

- Note: This command will not delete the container volume,
so when you run `pgl-up` the next time, 
Postgres Lab will you will still have all of your data from the last setup.
_______________________________________________________________________________
