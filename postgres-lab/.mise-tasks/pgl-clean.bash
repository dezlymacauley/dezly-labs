#!/usr/bin/env bash
#MISE description="🧼 Delete the Postgres Lab volume"
#MISE quiet=true

printf "\n"
docker volume rm postgres-lab-data
printf "\n"
