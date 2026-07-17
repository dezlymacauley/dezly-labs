# Memory
_______________________________________________________________________________

```
Your Machine
│
├── Hard Drives (Persistent Storage)
│   ├── Built-in
│   └── External
│
└── RAM (Temporary storage)
    │
    ├── Kernel space (protected region — the OS's core, manages everything else)
    │
    ├── Process A's Virtual Address Space
    │   ├── Stack
    │   └── Heap
    │
    └── Process B's Virtual Address Space
        ├── Stack
        └── Heap
```
_______________________________________________________________________________

### Hard Drives (Persistent Storage)

A hard drive is a physical device used to store data. 

Data is preserved if your computer is switched off.

There are two main types of hard drives:
1. Internal hard drive - This is a drive that is always connected 
to the computer. The computer becomes unusable without it because this drive
contains the operating system kernel, and the operating system.

2. External drive - This is a drive that is can be added to the computer,
or removed from the system, while the computer is already running.
_______________________________________________________________________________

To check the size of the hard drives connected to your machine, 
use this command

```bash
lsblk -d -o name,size
```

You'll get an ouput like this

```
NAME      SIZE
zram0     3.7G
nvme0n1 238.5G
```
_______________________________________________________________________________

### RAM (Temporary Storage)

To check the size of the RAM, run this command

```bash
free -h
```
_______________________________________________________________________________

You'll get an ouput like this

```
               total        used        free      shared  buff/cache   available
Mem:           7.4Gi       2.6Gi       2.6Gi       507Mi       2.6Gi       4.8Gi
Swap:          3.7Gi          0B       3.7Gi
```

So I have 7.4 Gibibytes of RAM, available for the `Stack` and `Heap` of all
processes running on my machine.

1 Gibibytes = (2^30 bytes = 1,073,741,824 bytes)
_______________________________________________________________________________

#### Note:
- When RAM is sold, it usually listed a Gigabytes of RAM.
- 1 Gigabyte = (10^9 bytes = 1,000,000,000 bytes)
_______________________________________________________________________________

### RAM

_______________________________________________________________________________

### Kernel space

This is section of RAM is reserved for the kernel.
The kernel is the core of the operating system.

_______________________________________________________________________________

### Program vs Process

- A program is a set of instructions.
- A process is a program that is running. To be more specific,
this means that the kernel has loaded the process into RAM, and allocated
some Stack memory, Heap memory, a process ID, and CPU time for that program.

If you open a program twice, then two processes will be opened.

E.g. Opening two terminal windows.

_______________________________________________________________________________
