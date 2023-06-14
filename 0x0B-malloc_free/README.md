# 0x0B. C - malloc, free

Using automatic, and dynamic allocation to manipulate functions and allocate/free variables and pointers.

## Overview
Generally, we use variables and arrays with a known constant size to write functions and compute logical systems. But sometimes, it is difficult to know the size of the array one has to declare and/or if this size depends on another variable. Where multiple variables are to be used, a successful program has to consider arguments that can accommodate these variables.

By manipulating dynamic and automatic memory allocation, one can allocate size bytes and return a pointer to the allocated memory without needing to initialize a variable on the memory itself.

## Use
This repository contains several files that demonstrate the concepts of dynamic memory allocation using malloc and memory deallocation using free in the C programming language. These concepts are essential when working with dynamic data structures such as arrays and strings.

Below is a table summarizing the function of each file:
| File Name                | Function                                                      |
|--------------------------|---------------------------------------------------------------|
| **Simple**               |                                                               |C
| `0-create_array.c`         | Creates an array of characters and initializes it with a specific character  |
| `1-strdup.c`               | Duplicates a string using dynamic memory allocation                          |
| `2-str_concat.c`           | Concatenates two strings dynamically                                         |
| `3-alloc_grid.c`           | Dynamically creates a 2-dimensional array (grid) of integers                 |
| `4-free_grid.c`            | Frees the memory allocated for a 2-dimensional array                         |
| **Advanced**               |                                                                |
| `100-argstostr.c`          | Concatenates all the arguments passed to the program as strings              |
| `101-strtow.c`             | Splits a string into words and stores them in an array of strings            |
| **Header**                 |                                                                |
| `main.h`                   | Header file containing all necessary function prototypes for compilation     |

## Examples

### Example 1: Creating an array

The file `0-create_array.c` contains a function `create_array` that allows you to create an array of characters and initialize it with a specific character. The function takes two parameters: `size` and `c`.

File: `0-create_array.c`

```c
#include "main.h"

/**
 * create_array - Creates an array of characters and initializes it with a specific character
 * @size: The size of the array
 * @c: The character to initialize the array with
 * Return: The pointer to the created array, or NULL if the size is 0 or if memory allocation fails
 */

char *create_array(unsigned int size, char c)
{
        char *buffer;
        unsigned int position;

        if (size == 0)
        {
                return (NULL);
        }

        /* Define values with malloc */
        buffer = (char *) malloc(size * sizeof(c));

        if (buffer == 0)
        {
                return (NULL);
        }

        else
        {
                position = 0;
                while (position < size) /*While for array*/
                {
                        *(buffer + position) = c;
                        position++;
                }

                return (buffer);
        }

}
```

When we call create_array with a size of 5 and the character 'A', we can expect the following output:

```Terminal
$ ./a.out
Array created: [A A A A A]
```

### Example 2: Concatenating arguments to strings

The file `100-argstostr.c` contains a function `argstostr` that concatenates all the arguments passed to it as strings, separated by a new line character. The function takes two parameters: `ac` (argument count) and `av` (argument vector).

File: `100-argstostr.c`

```c
#include "main.h"

/**
 * argstostr - print arguments to strings
 * @ac: width of grid
 * @av: height of grid
 * Return: arguments line by line
 */

char *argstostr(int ac, char **av)
{
    char *str;
    int count = 0, a = 0, b = 0, c = 0;

    // Check if `ac` is 0 or `av` is NULL
    if (ac == 0 || av == NULL)
        return (NULL);

    // Calculate the total number of characters needed for the resulting string
    while (a < ac)
    {
        b = 0;
        while (av[a][b] != '\0')
        {
            count++;
            b++;
        }
        a++;
    }

    // Add the number of lines (`ac`) and extra character for the newline character
    count = count + ac + 1;

    // Allocate memory for the resulting string
    str = malloc(sizeof(char) * count);
    if (str == NULL)
    {
        return (NULL);
    }

    // Copy the characters from `av` into `str` with newline characters between each line
    for (a = 0; a < ac; a++)
    {
        for (b = 0; av[a][b] != '\0'; b++)
        {
            str[c] = av[a][b];
            c++;
        }
        str[c] = '\n';
        c++;
    }

    // Return the resulting string
    return (str);
}
```

When we call `argstostr` with the following arguments:

```Terminal
$ ./a.out ALX School #cisfun
```

We can expect the following output:
```Terminal
ALX
School
#cisfun
```



Feel free to modify and explore these examples further to understand the functionality of the respective functions.
