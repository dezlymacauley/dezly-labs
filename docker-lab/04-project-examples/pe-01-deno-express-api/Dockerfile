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
# After setting this line, you can refer to the WORKDIR using `./`
WORKDIR /app

# Copy the these three files from this directory, into the Docker container
COPY deno.json deno.lock package.json ./

# https://docs.deno.com/runtime/reference/cli/ci/
# Uses Deno to perform a reproducible install for CI environments
RUN deno ci

# Copy the source code from this directory into the Docker container
COPY src/main.ts ./src/main.ts

# This line does not perform any actions. It is documentation for the user
# of this Dockerfile. 
# It tells the user what ports the application requires to function.
EXPOSE 3000

# Run the `start` task from deno.json to start the API
CMD [ "deno", "task", "start" ]

# To use this file run this command
# The dot at the end is required. 
# This tells Docker that the current directory is the root of your project
# docker build -t pe-01-deno-express-api:1.0.0 .
