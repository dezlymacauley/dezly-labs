# Managing the Status of the Docker Service
_______________________________________________________________________________

To check if the Docker service is `active` or `inactive`

```
systemctl is-active docker
```

- If it is active, you'll see the output `active`
- If it is inactive, you'll see the output `inactive`
_______________________________________________________________________________

If the service is `inactive`,
then run this command to start the `Docker service` and `Docker socket`

```
sudo systemctl start docker.service docker.socket
```
_______________________________________________________________________________

If the service is `active` and you want to shut it down, 
run this command to stop the `Docker service` and `Docker socket`

```
sudo systemctl stop docker.service docker.socket
```
_______________________________________________________________________________
