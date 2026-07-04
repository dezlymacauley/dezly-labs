#!/usr/bin/env bash
#MISE description="❌ Shut down the Postgres Lab"
#MISE quiet=true

printf "\n"
docker compose down
printf "\n"
