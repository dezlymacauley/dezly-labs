#!/usr/bin/env bash
#MISE description="🔌 View the id, name, and port of all containers"
#MISE quiet=true

printf "\n"
docker ps -a --format "table {{.ID}}\t{{.Names}}\t{{.Ports}}"
printf "\n"
