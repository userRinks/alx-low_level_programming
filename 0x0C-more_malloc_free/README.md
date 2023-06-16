# 0x0C: More malloc, free

This repository contains the solutions to various tasks related to dynamic memory allocation and deallocation in the C programming language. The tasks cover concepts such as memory allocation using `malloc`, `calloc`, and `realloc`, as well as freeing allocated memory using free.

The files in this repository serve as examples to demonstrate the usage of these functions and their applications in different scenarios.

## Overview

Dynamic memory allocation is a crucial aspect of programming, allowing us to allocate memory for data structures whose size may not be known at compile time. The `malloc` function is used to allocate a block of memory dynamically, while free is used to release that memory once it is no longer needed. Additionally, `calloc` and `realloc` provide alternative ways of allocating and reallocating memory, respectively.

The tasks in this repository aim to enhance your understanding and proficiency in working with dynamic memory allocation. By completing these tasks and studying the provided solutions, you will gain a solid foundation in memory management and the proper use of `malloc`, `free`, `calloc`, and `realloc`.

## Use

These files provide various functionalities related to dynamic memory allocation, string manipulation, and numerical operations. Each file serves a specific purpose and contributes to the overall understanding and implementation of these concepts.

Below is a table summarizing the function of each file:
| File Name             | Function                                                                         |
|-----------------------|----------------------------------------------------------------------------------|
| **Simple**            |                                                                                  |
| `0-malloc_checked.c`  | Allocates memory using `malloc` and checks if the allocation was successful       |
| `1-string_nconcat.c`  | Concatenates two strings up to a specified number of characters                  |
| `2-calloc.c`          | Allocates and initializes an array of elements using `calloc`                     |
| `3-array_range.c`     | Creates an array of integers containing a range of values                         |
| **Advanced**          |                                                                                  |
| `100-realloc.c`       | Reallocates memory for a previously allocated block with a new size               |
| `101-mul.c`           | Multiplies two positive numbers and prints the result                             |
| **Header**            |                                                                                  |
| `main.h`              | Header file containing function prototypes and shared definitions                |

To use these files, you can follow these steps:

1. Clone the repository to your local machine using the following command:

```
git clone https://github.com/userRinks/alx-low_level_programming.git
```

2. Navigate to the repository's directory:

```
cd 0x0C-more_malloc_free
```

3. Compile the desired file using a C compiler. For example, to compile `0-malloc_checked.c`:

```
gcc -Wall -Werror -Wextra -pedantic 0-malloc_checked.c -o malloc_checked
```

4. Run the compiled executable:

```
./malloc_checked
```

The compilation and execution steps may vary depending on your development environment and operating system.

## Examples

Here are a few examples that demonstrate the usage of the files in this repository:

### Example 1: Allocating Memory Safely

The file `0-malloc_checked.c` contains a function `malloc_checked` that safely allocates memory using `malloc`. It checks if the allocation was successful and terminates the program if not.


File: `0-malloc_checked.c` 

```xxxxxxxxxxxx
#include "main.h"

/**
 * malloc_checked - allocate memory using malloc func
 * @b: bytes
 * Return: ptr
 */

void *malloc_checked(unsigned int b)
{
        void *ptr;

        ptr = malloc(b);
        if (ptr == NULL)
                exit(98);
        return (ptr);
}
```

To use this function, you can call it with the desired size and assign the returned pointer to a variable:

```
#include "main.h"

int main(void)
{
    unsigned int size = 10;
    int *ptr = malloc_checked(size * sizeof(int));

    // Rest of the code

    return 0;
}
```


### Example 2: Reallocating Memory

The file `100-realloc.c` contains a function `_realloc` that allows you to reallocate a memory block using `malloc` and `free`. The function takes three parameters: `ptr` (pointer to the memory block), `old_size` (size of the old memory block), and `new_size` (new size of the memory block).

File: `100-realloc.c`

```xxxxxxxxxxxx
#include "main.h"

/**
 * _realloc -  reallocate memory block using malloc and free
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        char *clone, *relloc;
        unsigned int i;

        if (ptr != NULL)
            clone = ptr;
        else
        {
            return (malloc(new_size));
        }

        if (new_size == old_size)
        {
            return (ptr);
        }

        if (new_size == 0 && ptr != NULL)
        {
            free(ptr);
            return (0);
        }

        relloc = malloc(new_size);
        if (relloc == NULL)
        {
            return (0);
        }

        for (i = 0; i < (old_size || i < new_size); i++)
        {
            *(relloc + i) = clone[i];
        }

        free(ptr);
        return (relloc);
}
```

When we call `_realloc` with a memory block, old size, and new size, we can expect the memory block to be reallocated accordingly.

```
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    int *arr;
    int old_size = 5;
    int new_size = 10;
    int i;

    arr = malloc(sizeof(int) * old_size);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    for (i = 0; i < old_size; i++)
    {
        arr[i] = i + 1;
    }

    printf("Before reallocation:\n");
    printf("arr = ");
    for (i = 0; i < old_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = _realloc(arr, sizeof(int) * old_size, sizeof(int) * new_size);
    if (arr == NULL)
    {
        printf("Memory reallocation failed\n");
        return (1);
    }

    printf("After reallocation:\n");
    printf("arr = ");
    for (i = 0; i < new_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return (0);
}
```

We can expect the following output:
```Terminal
Before reallocation:
arr = 1 2 3 4 5 
After reallocation:
arr = 1 2 3 4 5 0 0 0 0 0 
```

In this example, we first allocate a memory block of size `old_size` and populate it with values. Then, we use `_realloc` to reallocate the memory block to a new size of `new_size`. The values from the original memory block are preserved, and additional memory is allocated if necessary. Finally, we print the contents of the reallocated memory block to verify the changes.

Feel free to modify and explore this example further to understand the functionality of the `_realloc` function.

Feel free to modify and explore these examples further to understand the functionality of the respective functions.
