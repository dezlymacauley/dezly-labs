
```bash
mise use kubectl@latest
```

`kubectl` is a CLI tool that is used to interact with a Kubernetes cluster.
_______________________________________________________________________________

Run this command

```bash
kubectl version --client
```
_______________________________________________________________________________

You should get something like this back

```
Client Version: v1.36.2
Kustomize Version: v5.8.1
```
_______________________________________________________________________________

```bash
mise use minikube@latest
```
_______________________________________________________________________________

Ensure that Docker is running by using `dezly-labs/docker-lab`
_______________________________________________________________________________

## How to start minikube
_______________________________________________________________________________

Then run this command 

```bash
minikube start
```
_______________________________________________________________________________

```bash
kubectl version
```
_______________________________________________________________________________

This should be the output

```
Client Version: v1.36.2
Kustomize Version: v5.8.1
Server Version: v1.35.1
```
_______________________________________________________________________________

If you run this command, you should see `minikube` printed 

```bash
kubectl config current-context
```
_______________________________________________________________________________

Open up a separate terminal in the directory `dezly-labs/docker-lab`

```bash
mise containers
```
_______________________________________________________________________________

You should see this

```bash
CONTAINER ID   NAMES      STATUS
4e4b5312aaf5   minikube   Up 14 minutes
```
_______________________________________________________________________________

Run this command

```bash
mise images
```
_______________________________________________________________________________

You should see this

```
IMAGE ID       REPOSITORY:TAG                        SIZE
6da180ef5035   gcr.io/k8s-minikube/kicbase:v0.0.50   1.37GB
```
_______________________________________________________________________________

Run this command

```bash
mise ports
```
_______________________________________________________________________________

You should see this

```
CONTAINER ID   NAMES      PORTS
4e4b5312aaf5   minikube   127.0.0.1:32768->22/tcp, 127.0.0.1:32769->2376/tcp, 127.0.0.1:32770->5000/tcp, 127.0.0.1:32771->8443/tcp, 127.0.0.1:32772->32443/tcp
```
_______________________________________________________________________________

Run this command 

```bash
mise volumes
```
_______________________________________________________________________________

You should see this

```
DRIVER    VOLUME NAME
local     minikube
```
_______________________________________________________________________________

## How to stop minikube

_______________________________________________________________________________

Run this command to shut down the minikube container

```bash
minikube stop
```

This will shut down the container, while preserving the image and volume.
_______________________________________________________________________________

If you run the command `mise containers`, you should see this

```
CONTAINER ID   NAMES      STATUS
4e4b5312aaf5   minikube   Exited (130) 6 minutes ago
```
_______________________________________________________________________________

