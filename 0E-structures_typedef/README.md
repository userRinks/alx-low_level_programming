# 0x0E. C - Structures, typedef

Defining and manipulating data structures in C

## Overview

This repository contains C programs that demonstrate the usage of structures and `typedef` in the C programming language. Structures allow you to create user-defined data types that can hold multiple variables of different types. `Typedef`, on the other hand, allows you to create custom type aliases, making your code more readable and maintainable.

## Description

The `dog.h` file introduces the concept of structure typedefs in C. By using the `typedef` keyword, a new name (`dog_t`) is created as an alias for the `struct dog` type. This allows us to conveniently declare variables of type `dog_t` instead of `struct dog`, making the code more readable and concise. The typedef ensures that the `struct dog` and `dog_t` refer to the same type, allowing seamless interchangeability between them. This approach enhances the clarity and simplicity of working with structures, making the code more maintainable and easier to understand.

The repository consists of the following files:

| File              | Description                                                           |
|-------------------|-----------------------------------------------------------------------|
| `dog.h`           | Header file that contains the definition of the `struct dog` and related function prototypes. |
| `1-init_dog.c`    | Function that initializes the members of a `struct dog`.               |
| `2-print_dog.c`   | Function that prints the content of a `struct dog`.                    |
| `4-new_dog.c`     | Function that creates a new `struct dog` and initializes its members.  |
| `5-free_dog.c`    | Function that frees the memory allocated for a `struct dog`.           |


## How to Use

1. Clone the repository:

```
git clone https://github.com/userRinks/alx-low_level_programming.git
```


2. Access the "0x0E. C - Structures, typedef" directory:

```
cd /alx-low_level_programming/
```

3. Compile the C files using your preferred C compiler.

```
gcc -Wall -Werror -Wextra -pedantic main.c <file-name>.c -o output
```

Replace `<file-name>` with the desired C file (e.g., `1-init_dog`, `2-print_dog`, etc.).

4. Run the compiled program:

```
./output
```


## Credits

This repository is maintained by [MistaRinks](https://github.com/userRinks).

Feel free to contribute by submitting a pull request or creating an issue if you encounter any problems. I may include test files later on for quick testing.
