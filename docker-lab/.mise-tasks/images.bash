#!/usr/bin/env bash
#MISE description="📜 List all downloaded container images"
#MISE quiet=true

printf "\n"
docker image ls --format "table {{.ID}}\t{{.Repository}}:{{.Tag}}\t{{.Size}}"
printf "\n"
