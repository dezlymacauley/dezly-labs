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

### RAM

To check the size of the RAM, run this command

```bash
free -h
```

_______________________________________________________________________________
