# 0x14: C - Bit Manipulation

This repository contains a collection of files that demonstrate various operations on bits and bitwise manipulation in the C programming language.

The provided functions allow you to perform common tasks, such as converting binary to unsigned integers, printing binary representation, getting and setting bits, clearing bits, flipping bits, and more.

## Overview

Bit manipulation is a fundamental concept in computer programming that involves the manipulation and extraction of individual bits within binary data. It provides powerful tools to efficiently perform operations at the bit level, allowing for compact representation of data, optimization of algorithms, and implementation of advanced functionalities.

Understanding bit manipulation is crucial for low-level programming, embedded systems, cryptography, network protocols, and other areas where fine-grained control over individual bits is necessary. This repository aims to provide a practical introduction to bit manipulation techniques and serves as a reference for implementing common bit manipulation operations.

Some key concepts related to bit manipulation include:

- **Binary representation**: Bits are the building blocks of binary representation, where each digit can be either 0 or 1. Binary numbers form the basis for bit manipulation operations, as they represent data at the lowest level.

- **Bitwise operators**: Bitwise operators are used to perform operations on individual bits. The most common bitwise operators include AND (`&`), OR (`|`), XOR (`^`), NOT (`~`), and shift operators (`<<`, `>>`).

- **Bitwise logical operations**: Bitwise logical operations such as AND, OR, and XOR allow combining and modifying bits based on specific conditions. These operations are fundamental for performing complex bit manipulations.

- **Bit shifting**: Bit shifting involves moving the bits of a binary number to the left or right by a specified number of positions. Left shifting (`<<`) multiplies the number by 2, while right shifting (`>>`) divides the number by 2.

- **Bit masks**: Bit masks are used to select or manipulate specific bits within a binary number. By combining bitwise operators and masks, it is possible to extract, modify, or check the values of individual bits or groups of bits.


## Files

This repository provides a set of functions that demonstrate practical applications of bit manipulation techniques. The files cover both simple and advanced operations, allowing you to gain a comprehensive understanding of manipulating bits in the C programming language.

Below is a table summarizing the function of each file:

| File Name            | Function                                                   |
|----------------------|------------------------------------------------------------|
| **Simple**           |                                                            |
| `0-binary_to_uint.c` | Convert binary to unsigned integer                          |
| `1-print_binary.c`   | Print binary representation of a number                     |
| `2-get_bit.c`        | Get the value of a bit at a given index                      |
| `3-set_bit.c`        | Set the value of a bit at a given index                      |
| `4-clear_bit.c`      | Clear the value of a bit at a given index                    |
| `5-flip_bits.c`      | Count the number of bits needed to flip to convert numbers  |
| **Advanced**         |                                                            |
| `100-get_endianness.c`| Check the endianness of the system                          |
| `crackme3`           | Crackme program, challenge to solve (available at https://github.com/alx-tools/0x13.c)                                            |
| `101-password`       | Password to the crackme program                             |
| `crackme3_hacker.c`  | File to extract the password to crackme3                    |
| **Header**           |                                                            |
| `main.h`             | Header file for function prototypes and declarations        |


Feel free to explore the files and examples provided to deepen your knowledge of bit manipulation and enhance your programming skills.

## Usage

To use the functions in this repository, follow the steps below:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/userRinks/alx-low_level_programming.git
   ```

2. Compile the C files using your preferred compiler. For example, using `gcc`:
    ```bash
    gcc -Wall -Wextra -Werror -pedantic -o program <filename.c>
    ```
Replace `<filename.c>` with the name of the file you want to compile.

3. Run the compiled program:
    ```bash
    ./program
    ```

### Example 1: Printing a Binary Number

The file `1-print_binary.c` contains functions `print_binary_helper` and `print_binary` that can be used to print a binary representation of a number.

File: `1-print_binary.c`
```c
#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * print_binary_helper - prevent stack overflow, print most significant bits
 * @n: integer
 * @msb: most significant bits
 */

void print_binary_helper(unsigned long int n, int msb)
{
    if (n == 0 || msb == -1)
    {
        return;
    }
    print_binary_helper(n >> 1, msb - 1);
    putchar((n & 1) ? '1' : '0');
}

/**
 * print_binary - prevent stack overflow, print most significant bits
 * @n: integer
 */

void print_binary(unsigned long int n)
{
    int msb = -1;
    unsigned long int tmp = n;

    while (tmp > 0)
    {
        tmp >>= 1;
        msb++;
    }
    if (msb == -1)
    {
        putchar('0');
    }
    else
    {
        print_binary_helper(n, msb);
    }
}
```

You can use the `print_binary` function to print the binary representation of a number as follows:

Example file: `answer.c`
```c
    unsigned int num = 42;
    printf("Binary representation of %u: ", num);
    print_binary(num);
    printf("\n");
```

```bash
gcc -Wall -Wextra -Werror -pedantic -o print_bin 1-print_binary.c answer.c
```

Expected Output:
```bash
./print_bin
Binary representation of 42: 101010
```

In this example, we have a variable num assigned the value `42`. We then call the `print_binary` function to print its binary representation. The expected output is `101010`, which is the binary representation of `42`.

### Example 2: Checking Endianness

The file `100-get_endianness.c` contains a function `get_endianness` that can be used to check if your system is Big Endian or Little Endian.

File: `100-get_endianness.c`
```c
#include <stdio.h>
#include "main.h"

/**
 * get_endianness - check if your system is Big or Little endian
 * Return:
 *      (1) if Big Endian
 *      (0) if Little Endian
 */

int get_endianness(void)
{
    unsigned int x = 1;
    char *c = (char *)&x;

    return ((int)*c);
}
```

You can use the `get_endianness` function to check the endianness of your system as follows:

```c
int endian = get_endianness();
if (endian == 1)
    {
        printf("Big Endian\n");
    }

    else
    {
        printf("Little Endian\n");
    }
```

The output will depend on the endianness of your system. If your system is Big Endian, it will print:
```bash
Big Endian
```

If your system is Little Endian, it will print:
```bash
Little Endian
```

In the above example, we call the `get_endianness` function to check the endianness of the system. If the return value is `1`, it means the system is Big Endian, and if the return value is `0`, it means the system is Little Endian. The corresponding message is then printed accordingly.

You can run this code on your system to determine its endianness.

### Example 3: Cracking the Password

The file `crackme3_hacker.c` contains a function `crack_password` that cracks a 4-digit password and prints it.

File: `crackme3_hacker.c`
```c
#include <stdio.h>

/**
 * main - run crack_password
 * Return: 0
 */

void crack_password(void);

int main(void)
{
    crack_password();
    return (0);
}


/**
 * crack_password - crack the 4-digit password and print it
 * Return: 0
 */

void crack_password(void)
{
    int i = 0;
    int operand;

    char password[] = "Foob";

    while (i <= 3)
    {
        operand = i << 3;
        int shifted = 0x46c6f48 >> operand;
        int masked = 0xff & shifted;

        password[i] = masked;
        i++;
    }

    printf("%s\n", password);
}
```

When the `crackme3_hacker.c` file is compiled and run successfully, it will crack the 4-digit password and print it.

The password is extracted using bitwise operations on the hexadecimal value `0x46c6f48`. The password is then stored in the password array.

The expected output when running the program will be the cracked password.

After compiling and running `crackme3_hacker.c`, you can copy the password to a file named `101-password`.
Example:
```bash
gcc crackme3_hacker.c -o cracked_pass

./cracked_pass > 101-password
```

Then, you can run the `crackme3` program with the password as an argument:

```bash
$ ./crackme3 `cat 101-password`
Congratulations!
```

You can run this code to see the cracked password on your system.


That concludes the usage examples for this repository. Feel free to explore the provided functions further and incorporate them into your own projects.
