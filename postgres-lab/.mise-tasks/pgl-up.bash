#!/usr/bin/env bash
#MISE description="❌ Shutdown the Postgres Lab Docker container"
#MISE quiet=true

printf "\n"
docker compose down
printf "\n"
