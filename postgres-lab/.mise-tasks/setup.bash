#!/usr/bin/env bash
#MISE description="👷 Setup pgcli"
#MISE quiet=true

# Ensure that this is a clean build of the virtual environment
rm -rf .venv

# Rebuild the the virtual environment and install pgcli and sqruff
uv sync

# Start the Docker service
sudo systemctl start docker.service docker.socket

# Run the Postgres Lab Docker container
docker compose up -d
