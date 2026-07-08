#!/usr/bin/env bash
#MISE description="🔩 Use psql to perform admin tasks on the Postgres cluster"
#MISE quiet=true

printf "\n"
docker exec -it postgres-lab-database psql -U postgres
printf "\n"
