# C: 0x0D - Preprocessor

## Overview

This repository contains C programs related to preprocessor directives.

## Description

The preprocessor is a part of the C compiler that performs text replacement before the actual compilation process. It allows for code generation, conditional compilation, inclusion of header files, and more. The programs in this repository demonstrate the usage of preprocessor directives and macros in C programming.


The repository consists of the following files:

| File                       | Description                                                                                  |
|----------------------------|----------------------------------------------------------------------------------------------|
| `0-object_like_macro.h`    | Defines a macro named `SIZE` with the value `1024`.                                          |
| `1-pi.h`                   | Defines a macro named `PI` with the value `3.14159265359`.                                   |
| `2-main.c`                 | Program that prints the name of the file it was compiled from, followed by a new line.       |
| `3-function_like_macro.h`  | Contains function-like macros for computing the absolute value, the minimum of two numbers, and the maximum of two numbers. |
| `4-sum.h`                  | Contains a function-like macro for computing the sum of two numbers.                         |

## How to Use

1. Clone the repository:

https://github.com/userRinks/alx-low_level_programming.git


2. Access the "C: 0x0D - Preprocessor" directory:

cd /alx-low_level_programming/C:0x0D-Preprocessor


3. Compile and run the desired C program using your preferred C compiler.

```
gcc -Wall -Werror -Wextra -pedantic main.c <file-name>.c -o output
./output
```

Replace `<file-name>` with the desired C file (e.g., `0-main`, `1-main`, etc.).

## Credits

This repository is maintained by [MistaRinks](https://github.com/userRinks).

Feel free to contribute by submitting a pull request or creating an issue if you encounter any problems.
I may include test files later on for quick testing.

Happy coding!
