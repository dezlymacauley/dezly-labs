#!/usr/bin/env bash
#MISE description="🚢 View the id, name, and status of all containers"
#MISE quiet=true

docker ps -a --format "table {{.ID}}\t{{.Names}}\t{{.Status}}"
