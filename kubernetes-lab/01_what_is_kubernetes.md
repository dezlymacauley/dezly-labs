Kubernetes also known as K8s was built by Google based on their experience
running containers in production.

It is an open source container orchestration technology.

_______________________________________________________________________________

E.g. You have an application

- Web server: Express (JavaScript framework)
- Database: MongoDB
- Messaging System: Redis
- Orchestration: Ansible

_______________________________________________________________________________

Docker allow you to run each component of the application in a separate 
Docker container that all of the dependencies and libraries needed for that
application to work.
_______________________________________________________________________________


An operating system is made up of an OS kernel and a set of software that
runs on that operating systems.
_______________________________________________________________________________

Docker utilizes LXC containers.
_______________________________________________________________________________

A container is an isolated environment.

It can have its own processes, services, its own network interfaces,
and its own mounts, just like virtual machines, except they all share the
same operating system kernel.

_______________________________________________________________________________

Docker can run any Linux distro on top of it as long that Linux distro
is based on the same kernel that Docker is running on.

E.g. The operating system on my host machine is Arch Linux, 
which uses the Linux kernel.

I have Docker installed on Arch Linux,
then I have Docker running a container that has the operating system Alpine
Linux.

The container running Alpine linux, will share the same kernel as my Arch
Linux host machine.

_______________________________________________________________________________

I want be able to run a container with Windows because Windows and Linux
don't share the same kernel.

For that you will require Docker on a Windows server.

_______________________________________________________________________________

If your host machine is Windows and you install a Docker on it,
and then try to run a Linux container, 
Windows will run a Linux virtual machine, 
and then run the container on that virtual machine.

_______________________________________________________________________________

Unlike hyprvisors, Docker is not meant to run different operating systems
and kernels on the same hardware.

_______________________________________________________________________________
