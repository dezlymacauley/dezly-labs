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

In simple terms, the compiler knows exactly how much memory to allocate for
that data before the program runs (this is when the kernel loads the program
into memory) 

The Stack is much smaller than the Heap.

Functions are handled according to LI-FO (Last In, First Out).

Memory allocated to variables is automatically freed.
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

This is for storing data with a size that can only be determined at runtime,
or would be too wasteful to store on the Heap.

Unlike the Stack, the Heap does not follow LI-FO. When data is allocated
on the Heap the kernel has to search for a free block of space that is large
enough to fit the data.

The means that using data from the Heap is much slower than 
the data from the Stack.

Another major difference with the Heap is that memory allocated on the heap
is not automatically freed (aka released back to the Operating system).

If you are programming in a garbage-collected language like Go, Python,
and TypeScript then a garbage collector for that specific programming language
will free the memory allocated on the heap for you.

If you are using a language with manual memory management like C or C++, 
then you have to remember to free up the memory when writing your code.

If you are using Rust, Rust uses a unique ownership model to free the memory
allocated once there are no owners using that memory.
_______________________________________________________________________________

### How different programming languges handle Stack and Heap alllocation

- Note: 1 byte = 8 bits. So 32 bits = 4 bytes.
- Signed means that the number can be positive or negative.
- integer means that the number is not allowed to have decimal places.
_______________________________________________________________________________

#### Rust
_______________________________________________________________________________

Declaring a 32 bit signed integer on the Stack.

```rust
fn main() {
    let x: i32 = 42;

    // The value of x
    println!("x = {x}");

    // The memory address of x
    println!("address of x = {:p}", &x);
}
```
_______________________________________________________________________________

Declaring a 32 bit signed integer on the Heap.

```rust
fn main() {
    let y: Box<i32> = Box::new(42);

    // The memory address stored by y
    println!("{:p}", y); 

    // The value stored by y
    println!("{}", *y);    
}
```
_______________________________________________________________________________

#### C++

_______________________________________________________________________________

Declaring a 32-bit signed integer on the Stack.
```cpp
#include <iostream>

int main() {
    int x = 42;

    // The value of x
    std::cout << "x = " << x << std::endl;

    // The memory address of x
    std::cout << "address of x = " << &x << std::endl;

    return 0;
}
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap (Classic Version)

```cpp
#include <iostream>

int main() {
    int* y = new int(42);

    // The memory address stored by y
    std::cout << y << std::endl;

    // The value stored by y
    std::cout << *y << std::endl;

    // must free manually — no ownership system or GC
    delete y;   
    return 0;
}
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap (C++23 version)

```cpp
#include <print>
using std::print;

#include <memory>
using std::unique_ptr;
using std::make_unique;

int main() {
    unique_ptr<int> y = make_unique<int>(42);

    // The memory address stored by y
    print("{}\n", (void*)y.get());

    // The value stored by y
    print("{}\n", *y);

    // No delete needed — memory is freed automatically
    // when y goes out of scope, just like Rust's Box<i32>
    return 0;
}
```
_______________________________________________________________________________

#### C
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Stack.

```c
#include <stdio.h>

int main() {
    int x = 42;

    // The value of x
    printf("x = %d\n", x);

    // The memory address of x
    printf("address of x = %p\n", (void*)&x);

    return 0;
}
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap.

```c

// Required to use `printf`
#include <stdio.h>

// Required to use `malloc`
#include <stdlib.h>

int main() {

    // Request Heap memory
    int* y = malloc(sizeof(int));

    // Store the value on the heap
    *y = 42;

    // The memory address stored by y
    printf("%p\n", (void*)y);

    // The value stored by y
    printf("%d\n", *y);

    // Remember to free the memory you requested.
    free(y);   

    return 0;
}
```
_______________________________________________________________________________

#### Zig
_______________________________________________________________________________


Declaring a 32-bit signed integer on the Stack.

```zig
const std = @import("std");

pub fn main() !void {
    // Stack allocation
    var x: i32 = 42;
    std.debug.print("x = {}\n", .{x});
    std.debug.print("address of x = {*}\n", .{&x});

    // Heap allocation — must explicitly choose an allocator
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    const y = try allocator.create(i32);
    y.* = 42;

    std.debug.print("address stored by y = {*}\n", .{y});
    std.debug.print("value stored by y = {}\n", .{y.*});

    allocator.destroy(y);   // must free manually — no GC, no ownership system
}
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap.

```zig
const std = @import("std");

pub fn main() !void {
    // Choose an allocator
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    const y = try allocator.create(i32);
    y.* = 42;

    std.debug.print("address stored by y = {*}\n", .{y});
    std.debug.print("value stored by y = {}\n", .{y.*});

    // Free the memory
    allocator.destroy(y);   
}
```
_______________________________________________________________________________
#### Go
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Stack.

```go
package main

import "fmt"

func main() {
	var x int32 = 42

	// The value of x
	fmt.Println("x =", x)

	// The memory address of x
	fmt.Printf("address of x = %p\n", &x)
}
```
_______________________________________________________________________________

#### Go doesn't let you choose Stack vs. Heap directly. 

- The compiler decides for you using something called `escape analysis`

- If the compiler can prove a variable is only used inside that function 
and never referenced outside it, it stays on the Stack (fast, auto-cleaned).

- If the compiler detects the variable's address "escapes" the 
function (e.g. returned, stored in a struct, passed to a goroutine), 
it automatically places it on the Heap instead — even if you wrote 
it exactly like a normal variable.

- You never have to free memory because Go's garabage collector does 
this for you.

- This makes Go code much simpler to write than Rust, C++ and C,
but at the cost of control and performance.

_______________________________________________________________________________

"Declaring" a 32-bit signed integer on the Heap.

```go
package main

import "fmt"

func main() {
	y := new(int32)
	*y = 42

	// The memory address stored by y
	fmt.Printf("%p\n", y)

	// The value stored by y
	fmt.Println(*y)
}
```
_______________________________________________________________________________

#### Python

Python doesn't really give you the power to choose Stack vs. Heap when
declaring variable.

In CPython (the standard Python interpreter), 
everything is an object that is stored on the Heap.

Even if you create a basci type like an integer in Python,
that integer is stored as an object on the Heap.

```python
x = 42

# The value of x
print(f"x = {x}")

print(f"object id of x = {hex(id(x))}")
```

Python also does not allow you to print the memory address of a variable,
the best you can do is.
_______________________________________________________________________________

#### Mojo
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Stack

```python
def main():
    var x: Int32 = 42
    print("x =", x)
    print("address of x =", Pointer(to=x))
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap 

```python
def main():

    var y = alloc[Int32](1)
    y.init_pointee_copy(42)

    print("address stored by y =", y)
    print("value stored by y =", y[])
    y.free()
```
_______________________________________________________________________________

Declaring a 32-bit signed integer on the Heap

```python
from memory import UnsafePointer, alloc

def main():
    # Stack allocation
    var x: Int32 = 42

    # The value of x
    print("x =", x)

    # A pointer to the existing Stack variable
    var x_ptr = UnsafePointer(to=x)
    print("value pointed to by x_ptr =", x_ptr[])

    # Heap allocation
    var y = alloc[Int32](1)

    # Initialize the allocated memory
    y.init_pointee_copy(42)

    # The value stored by y
    print("value stored by y =", y[])

    # Free the heap memory manually — no GC, no ownership auto-drop for UnsafePointer
    y.free()
```
_______________________________________________________________________________

#### TypeScript (Deno)

TypeScript is transpiled to JavaScript, 
and Deno runs on V8 (Chrome's JS engine), which manages all memory itself. 

You don't get to choose Stack vs. Heap.

V8's garbage collector decides everything.

TypeScript as No built-in way to get the memory address of a variable.

```typescript
const x: number = 42;

// The value of x
console.log(`x = ${x}`);
```

#### Fun fact
- V8 is written in C++
- And Deno has Rust binding for V8, called Rusty V8, 
which is written in Rust and C++.
_______________________________________________________________________________
