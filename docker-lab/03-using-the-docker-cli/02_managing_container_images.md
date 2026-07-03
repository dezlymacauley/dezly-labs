# Managing Container Images
_______________________________________________________________________________

To view a list  of container images you've download

```
docker image ls --format "table {{.ID}}\t{{.Repository}}:{{.Tag}}\t{{.Size}}"
```
_______________________________________________________________________________

You should get an ouput like this back:
```
IMAGE ID       REPOSITORY:TAG             SIZE
3ce79a779d23   postgres:16                451MB
99d320a6265d   postgres:18.4-alpine3.24   304MB
```
_______________________________________________________________________________

To delete a Docker image, use use its `IMAGE ID`

E.g. 

```
docker rmi 3ce79a779d23  
```

Note: `docker rmi` is a shorter version of the command `docker image rm`
_______________________________________________________________________________
