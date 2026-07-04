#!/usr/bin/env bash
#MISE description="🚥 Check status of the Docker service"
#MISE quiet=true

if [[ "$(systemctl is-active docker)" == "active" ]]; then
    printf "\n✅ Docker is active\n\n"
else
    printf "\n⬛ Docker is inactive\n\n"
fi
