# 0x09. C - Static libraries

This repository serves as a guide for understanding and working with static libraries in the C programming language. 

## Overview

Static libraries are collections of pre-compiled object files that can be linked with other programs to provide additional functionality. They are an essential tool for code organization, reuse, and modular development.

Static libraries offer several advantages:

- *Code Reusability*: Static libraries allow you to encapsulate commonly used functions and code snippets into a single library, promoting code reuse across different projects.
- *Modularity*: By dividing code into separate libraries, you can manage and maintain different functionalities independently, making it easier to update and modify specific components without affecting the entire codebase.
- *Optimized Compilation*: Static libraries are compiled into executables during the linking phase, resulting in faster program execution as the library functions are already incorporated into the binary file.
- *Distribution*: Static libraries simplify the distribution of code by bundling related functions and resources into a single package, allowing other developers to easily include and utilize your library.

## Functions and Scripts

Below is a table summarizing the purpose and functionality of each necessary file in this repository:

| File Name        | Use                                    |
|------------------|----------------------------------------|
| **Libraries**    |                                        |
| `libmy.a`        | Contains all functions below           |
| `liball.a`       | Library created by `create_static_lib.sh` | 
| **Functions**    |                                        |
| `0-isupper.c`    | Checks if a character is uppercase     |
| `0-memset.c`     | Fills memory with a constant byte      |
| `0-strcat.c`     | Concatenates two strings               |
| `100-atoi.c`     | Converts a string to an integer        |
| `1-isdigit.c`    | Checks if a character is a digit       |
| `1-memcpy.c`     | Copies memory area                     |
| `1-strncat.c`    | Concatenates two strings               |
| `2-strchr.c`     | Locates a character in a string        |
| `2-strlen.c`     | Calculates the length of a string      |
| `2-strncpy.c`    | Copies a string                        |
| `3-islower.c`    | Checks if a character is lowercase     |
| `3-puts.c`       | Prints a string                        |
| `3-strcmp.c`     | Compares two strings                   |
| `3-strspn.c`     | Gets the length of a prefix substring  |
| `4-isalpha.c`    | Checks if a character is alphabetic    |
| `4-strpbrk.c`    | Searches a string for any set of bytes |
| `5-strstr.c`     | Locates a substring within a string    |
| `6-abs.c`        | Computes the absolute value of an integer |
| `9-strcpy.c`     | Copies a string                        |
| **Test file**  |                                        |
| `main.c`         | Test file to demonstrate library usage  |
| **Other**      |                                        |    
| `create_static_lib.sh` | Creates a static library from C files |


## Use

To use the static library, follow these steps:

1. Compile all the C files, excluding `main.c`, using the appropriate compiler command, such as `gcc -c file.c`.
2. Create the static library `libmy.a` by running the provided `create_static_lib.sh` script. This script automatically collects all the compiled object files and creates the library.
3. Link the library with your program by including `libmy.a` during the compilation step. For example, `gcc main.c -L. -lmy -o program`.
4. Execute the compiled program.

## Example

Here's an example of how to compile and use the static library:

1. Compile the C files and create object files:

```shell
gcc -c 0-isupper.c
gcc -c 1-isdigit.c
gcc -c 2-strlen.c
gcc -c 3-strcmp.c
gcc -c 5-strstr.c
gcc -c _putchar.c
```
2. Create the static library `libmy.a`:

```shell
./create_static_lib.sh
```

3. Compile and link your program with the static library:

```shell
gcc main.c -L. -lmy -o your_program
```

4. Execute the program:

```shell
./your_program
```

## Other files

### create_static_lib.sh

The `create_static_lib.sh` script is a convenient utility that automatically creates a static library called `liball.a` from all the `.c` files in the current directory, excluding `main.c`. It performs the necessary compilation and archiving steps to generate the library.

To use the script, simply execute it in the terminal:

```shell
./create_static_lib.sh
```

The resulting library `liball.a` can then be linked with other programs as needed.
You can clone the folder and files, and edit the script to create a static library of your own.
