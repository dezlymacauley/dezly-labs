#!/usr/bin/env bash
#MISE description="🧼 Delete the .venv directory and Postgres Lab volume"
#MISE quiet=true

printf "\n"
rm -rf .venv
docker volume rm postgres-lab-data
printf "\n"
