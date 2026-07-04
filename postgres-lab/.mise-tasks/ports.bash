#!/usr/bin/env bash
#MISE description="🔌 View the ID, name, and ports of all containers"
#MISE quiet=true

printf "\n"
docker ps -a --format "table {{.ID}}\t{{.Names}}\t{{.Ports}}"
printf "\n"
