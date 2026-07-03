# Setting up a Postgres Workflow
_______________________________________________________________________________

Create a `compose.yaml` file at the root of the project directory.

```
touch compose.yaml
```
_______________________________________________________________________________

Add this to the file

```yaml
services:
  postgres-lab-service:
    container_name: postgres-lab-database
    image: postgres:18.4-alpine3.24
    environment:
      POSTGRES_PASSWORD: postgres
    ports:
      - "127.0.0.1:5432:5432"
    volumes:
      - postgres-lab-postgres-data:/var/lib/postgresql

volumes:
  postgres-lab-postgres-data:
```
_______________________________________________________________________________

Start the Docker service and Docker socket

```
sudo systemctl start docker.service docker.socket
```
_______________________________________________________________________________

Ensure that you are at the root of the project directory 
and then run this command:

```
docker compose up -d
```

The `-d` means detach. This means that after you run `docker compose up`,
you will still be able to use the terminal.
_______________________________________________________________________________

When you are done, run this command to remove the contai
```
docker compose down
```

_______________________________________________________________________________

You can also use the `-v` flag to remove the volume as well.

**Warning:** Don't run this command for a database like Postgres,
unless you want to delete all of the data in the database.

```
docker compose down -v
```
_______________________________________________________________________________

Run this command to remove the leftover volumes

```
docker volume prune -f
```
_______________________________________________________________________________

Stop the Docker service and Docker socket

```
sudo systemctl stop docker.service docker.socket
```
_______________________________________________________________________________
