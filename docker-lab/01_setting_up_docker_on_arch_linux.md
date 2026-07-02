# Setting up Docker on Arch Linux
_______________________________________________________________________________

Install the Docker engine

```
sudo pacman -S --needed docker
```
_______________________________________________________________________________

Run this command to create a privileged system group called `docker`

```
sudo groupadd -f docker 
```
_______________________________________________________________________________

Add your current user to the docker group.

```
sudo usermod -aG docker $USER
```
_______________________________________________________________________________

Run this command to check if the Docker service is `active` or `inactive`

```
systemctl is-active docker
```
_______________________________________________________________________________

If the service is inactive,
then run this command to start the `Docker service` and `Docker socket`

```
sudo systemctl start docker.service docker.socket
```
_______________________________________________________________________________

Run this command to stop the `Docker service` and `Docker socket`

```
sudo systemctl stop docker.service docker.socket
```
_______________________________________________________________________________
