# Managing Volumes
_______________________________________________________________________________

The filesystem of a container is temporary (stored in memory).

When you restart or delete a container, all of its data is lost.

For some containers that don't store data, that's fine.

However for a database, that's a problem.
_______________________________________________________________________________

- A volume is persistent storage that is placed outside a container.

- Think of a volume as a save file that can be used by all the services,
in your `compose.yaml` setup.

- This allows your containerized application to start with existing data.
_______________________________________________________________________________

- A volume is linked to a specific directory path, 
inside a specific container.

It's like how ports are linked. 

E.g. This means that port 5432 of my machine, 
is linked to port 5432 of the container.

```yaml
ports:
  - "127.0.0.1:5432:5432"
```

When it comes to volumes, its the same concept. Except this time,
its not a a linkage of network access, but a linkage of storage space.

```
volumes:
  - some_volume_name:/var/lib/postgresql
```
_______________________________________________________________________________

To list container volumes

```bash
docker volume ls
```
_______________________________________________________________________________

Here's an example of the output

```
DRIVER    VOLUME NAME
local     postgres-from-zero_pgdata
```
_______________________________________________________________________________

How to remove a volume

```
docker volume rm postgres-from-zero_pgdata
```
_______________________________________________________________________________
