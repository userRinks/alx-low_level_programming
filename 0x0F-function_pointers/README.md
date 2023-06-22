# 0x0F - Function Pointers

## Overview

The "0x0F - Function Pointers" project introduces the concept of function pointers in the C programming language. Function pointers allow us to store and invoke functions dynamically at runtime, providing flexibility and extensibility to our programs. This project explores various use cases and applications of function pointers, highlighting their importance in implementing callback mechanisms, dispatch tables, and dynamic behavior.

## Description

The "0x0F - Function Pointers" project contains several files that demonstrate different aspects of function pointers and their practical usage. Each file focuses on a specific use case and showcases the power and flexibility of function pointers in C programming.

The files included in this project are:

| File Name             | Description                                                       |
|-----------------------|-------------------------------------------------------------------|
| `0-print_name.c`      | Implements the `print_name` function, which invokes a provided function on a given name. |
| `1-array_iterator.c`  | Defines the `array_iterator` function, which applies a given function to each element in an array. |
| `3-calc.h`            | Header file containing function prototypes and structure definitions for a simple calculator program. |
| `3-main.c`            | Main entry point for the calculator program, showcasing the use of function pointers for arithmetic operations based on user input. |
| `function_pointers.h` | Header file that includes function prototypes for the project's functions. |
| `100-main_opcodes.c`  | Program that prints the opcodes of its own `main` function. |
| `2-int_index.c`       | Contains the `int_index` function, which searches for an integer within an array and returns the index of the first occurrence. |
| `3-get_op_func.c`     | Implements the `get_op_func` function, which selects the appropriate arithmetic function based on the operator passed. |
| `3-op_functions.c`    | Contains the implementations of arithmetic functions used in the calculator program. |

Each file provides a practical example of utilizing function pointers in different scenarios. By studying and experimenting with these files, you will gain a solid understanding of how function pointers work and their versatility in solving various programming problems.

## Usage

To explore and utilize the function pointers demonstrated in this project, follow these steps:

1. Clone the repository to your local machine.

```
git clone https://github.com/userRinks/alx-low_level_programming.git
```


2. Compile the source files using a C compiler:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o function_pointers
```


3. Run the executable:

```
./function_pointers
```


Follow the on-screen prompts to interact with the different functionalities and observe the behavior of function pointers in action.

Feel free to explore and modify the code to gain a deeper understanding of function pointers and their applications.
