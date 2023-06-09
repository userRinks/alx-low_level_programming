# Command Line Arguments in C

This repository contains C programs that demonstrate the usage of command line arguments (`argc` and `argv`).

## Overview
The `argc` and `argv` are parameters commonly used in C programming to handle command line arguments. These parameters allow you to pass values to a program when it is executed from the command line.

    - `argc` stands for "argument count" and represents the number of command line arguments passed to the program.
    - `argv` stands for "argument vector" and is an array of strings that holds the actual command line arguments.

When the user runs a C program from the command line, the first argument (`argv[0]`) is always the name of the program itself. The subsequent arguments, if any, are passed as additional elements in the `argv` array.

Below is a table summarizing the function of the important files in this repository:

| File Name          | Function                                                      |
|--------------------|---------------------------------------------------------------|
| **Simple**         |                                                               |
| 0-whatsmyname.c    | Prints the name of the program                                 |
| 1-args.c           | Prints the number of command line arguments passed             |
| 2-args.c           | Prints all the command line arguments passed                   |
| 3-mul.c            | Multiplies two numbers provided as command line arguments       |
| 4-add.c            | Adds a variable number of integers provided as command line arguments |
| **Advanced**       |                                                               |
| 100-change.c       | Calculates the minimum number of coins needed for change       |

## Usage

To compile and run the programs, use the following steps:

1. Open a terminal or command prompt.
2. Navigate to the directory containing the desired program file.
3. Compile the program using a C compiler (e.g., gcc) with the following command:

   ```bash
   gcc -o program_name program_file.c
   ```

Replace `program_name` with the desired name for the executable and `program_file.c` with the corresponding source file.

Run the program by executing the generated executable:
    ```bash
    ./program_name [arguments]
    ```

## Examples

### Simple Programs

Running `0-whatsmyname.c`:

```bash
./0-whatsmyname Hello World

```

Output:
```
Program name: ./0-whatsmyname
```


Running 1-args.c:
```
./1-args Hello World
```

Output:
```
Number of arguments: 3
```

### Advanced Programs

Running 100-change.c:

```
./100-change 97
```

Output:
```
97 cents: 4 coins
```
The files in this repo have been modified to further explore the usage of `argc` and `argv`.
