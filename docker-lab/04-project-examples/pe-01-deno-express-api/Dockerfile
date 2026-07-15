# Using a Docker Hardened Image

# Login to your DockerHub account

# docker login dhi.io

# Go to this link
# https://hub.docker.com/hardened-images/catalog/dhi/deno/images

# This is the image I'm using
# https://hub.docker.com/hardened-images/catalog/dhi/deno/images/deno%2Fdebian-13%2F2-dev/sha256-cf176bf6da737e00f9f3b3eab728b0e5de3e0e358ca2be742532d48b4e10f540

# If you click: `Use this image`, you'll see something like this
# docker pull dhi.io/deno:2-debian-dev

# This sets the base image to use for the Docker container
FROM dhi.io/deno:2-debian-dev

# This will create a directory called `app` at the root 
# of the Docker container, and set the `app` directory as the WORKDIR of
# the container.
# After setting 
WORKDIR /app

COPY deno.json deno.lock package.json ./
