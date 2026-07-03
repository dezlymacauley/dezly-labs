#!/usr/bin/env bash
#MISE description="🚥 Check if Docker is active"
#MISE quiet=true

if [[ "$(systemctl is-active docker)" == "active" ]]; then
    echo "✅ Docker is active"
else
    echo "⬛ Docker is inactive"
fi
