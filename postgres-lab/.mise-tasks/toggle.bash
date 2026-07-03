#!/usr/bin/env bash
#MISE description="🔁 Toggle the status of the Docker service"
#MISE quiet=true

if [[ "$(systemctl is-active docker)" == "active" ]]; then
    printf "\nShutting down Docker service...\n"

    sudo systemctl stop docker.service docker.socket

    printf "\n⬛ Docker is now inactive\n\n"
else
    printf "\nActivating Docker service...\n"

    sudo systemctl start docker.service docker.socket

    printf "\n✅ Docker is now active\n\n"
fi
