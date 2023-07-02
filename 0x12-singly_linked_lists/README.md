# C: Singly Linked Lists

This repository contains several files that demonstrate the concepts of Singly Linked Lists in the C programming language. Singly linked lists are fundamental data structures used to store and manipulate collections of data.

## Overview

A singly linked list is a linear data structure composed of nodes, where each node contains a value and a pointer to the next node. The last node in the list points to NULL, indicating the end of the list.

In this repository, you will find the following files related to singly linked lists:

| File Name                | Functionality                                                 |
|--------------------------|--------------------------------------------------------------|
| **Simple**    |                                                                   |
| `0-print_list.c`           | Prints all elements of a linked list                          |
| `1-list_len.c`             | Returns the number of elements in a linked list               |
| `2-add_node.c`             | Adds a new node at the beginning of a linked list             |
| `3-add_node_end.c`         | Adds a new node at the end of a linked list                   |
| `4-free_list.c`            | Frees the memory allocated for a linked list                  |
| **Advanced**  |                                                                   |
| `100-first.c`   | Function executed before main, demonstrating attribute usage  |
| `101-hello_holberton.asm`  | Assembly code to print "Hello, Holberton"                     |
| **Header**    |                                                                   |
| lists.h                  | Header file with function prototypes and struct declarations  |

## Usage

To use the functionalities provided by the linked list files, follow these steps:

1. Clone this repository to your local machine:
```
$ git clone https://github.com/userRinks/alx-low_level_programming.git
```

2. Include the `lists.h` header file in your C program:
```c
#include "lists.h"
```

3. Compile your C program with the required source files:
```
$ gcc your_program.c 0-print_list.c 1-list_len.c 2-add_node.c 3-add_node_end.c 4-free_list.c -o your_program
```

4. Execute your program:
```
$ ./your_program
```

5. Implement the specific functionality based on the file you want to use, such as printing a linked list or adding nodes.


## Examples

### Example 1: Printing a Linked List

The `0-print_list.c` file contains the `print_list` function, which allows you to print all elements of a linked list.

File: `0-print_list.c`

```c
#include "lists.h"

/**
 * print_list - Print all elements of a linked list
 * @h: Pointer to the head of the linked list
 * Return: The number of elements in the linked list
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;
    const list_t *tmp = h;

    while (tmp != NULL)
    {
        if (tmp->str == NULL)
        {
            printf("[%lu] %s\n", count, "(nil)");
        }
        else
        {
            printf("[%lu] %s\n", count, tmp->str);
        }

        tmp = tmp->next;
        count++;
    }

    return count;
}

```

To use the `print_list` function with an example, follow these steps:

1. Include the lists.h header file in your C program.
2. Create a linked list of student names and populate it with elements.
3. Call the `print_list` function, passing the head of the linked list as an argument.
4. The function will print all the elements of the linked list, along with their corresponding indices.

Example usage:
```
#include <stdio.h>
#include "lists.h"

int main(void)
{
    list_t *head = NULL;
    list_t *node1, *node2, *node3;

    /* Create and populate the linked list */
    node1 = create_node("Alice");
    node2 = create_node("Bob");
    node3 = create_node("Charlie");

    head = add_node_end(head, node1);
    head = add_node_end(head, node2);
    head = add_node_end(head, node3);

    size_t count = print_list(head);
    printf("Number of elements in the list: %lu\n", count);

    return 0;
}
```

Output:
```
[0] Alice
[1] Bob
[2] Charlie
Number of elements in the list: 3
```

### Example 2: Executing a Function before `main`

The `100-first.c` file contains the `before_main` function, which is executed before the `main` function. In this example, let's print a motivational message before the program starts.

File: `100-first.c`

```
#include "lists.h"

/**
 * before_main - Function executed before main
 * Return: void
 */
void before_main(void)
{
    printf("Welcome to My Program!\n");
    printf("Get ready to explore the world of C programming!\n");
}
```

To use the `before_main` function, follow these steps:

1. Include the `lists.h` header file in your C program.
2. Call the `before_main` function before the main function in your program.
3. The function will be executed automatically when the program starts.

Example usage:
```
#include <stdio.h>
#include "lists.h"

void before_main(void);

int main(void)
{
    before_main();

    printf("\n !This is the main function!\n");

    return 0;
}
```

Output:
```
Welcome to My Program!
Get ready to explore the world of C programming!

 !This is the main function!
```

Feel free to modify and explore these examples further to understand the functionality of the respective functions and adapt them to your specific project needs.
