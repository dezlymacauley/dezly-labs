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

If the Docker service is inactive, 
you can start it by running the following command

```
sudo systemctl start docker.service
```
_______________________________________________________________________________
