#!/usr/bin/env bash
#MISE description="📜 List all downloaded Docker images"
#MISE quiet=true

docker image ls --format "table {{.ID}}\t{{.Repository}}:{{.Tag}}\t{{.Size}}"
