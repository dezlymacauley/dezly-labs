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
this means that the kernel has peformed the following:

1. Loaded the process into RAM

2. Given the process a `process id` (to distiguish between multiple instances
of the same program).

If you open a program twice, then two processes will be opened.

One process for each instance of the program.

E.g. Opening two terminal windows.

3. Given the process it own `virtual address space`,
which includes the `Stack` for that process, and the `Heap` for that process.

The virtual address is like a range of all the available 
stack and heap adresses that are for that are reserved for that process.

#### Note
- This does not mean that a process is using every available address in that
space. It is simply reserved for when the program needs to use it.

You can think of it as a private parking lot. Only cars belonging to the
process are allowed to be parked in that parking lot, however the parking
spots are allowed to be empty if they are not being used.
_______________________________________________________________________________

### Stack

The Stack is a region of a process's Virtual Address Space used for
function calls and local variables. The important thing to take note of is
that the Stack is for data that has a known sized at compile time.

In simple terms, the ??? knows exactly how much memory to allocate for
that data before the program runs (this is when the kernel loads the program
into memory) 

The Stack is much smaller than the Heap.

Functions are handled according to LI-FI (Last In, First Out).
_______________________________________________________________________________

To check how much stack memory the kernel allocates to each process on your
machine, run this command

```bash
ulimit -s
```
_______________________________________________________________________________

You should get an output like this

```
16384
```

This means that the kernal allocates only 16384 KB (16 MB) of RAM 
for every process. If a process every hits, that limit, then it will crash.

This is known as a stack overflow.
_______________________________________________________________________________

### Heap

There is no fixed starting size for the Heap it will grow as needed.

_______________________________________________________________________________
