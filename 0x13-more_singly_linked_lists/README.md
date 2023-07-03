# 0x14: C - More Singly Linked Lists

This repository builds upon the previous repository on Singly Linked Lists and provides additional functionality and operations for working with linked lists in the C programming language. Linked lists are a fundamental data structure that allow for efficient storage and manipulation of data elements. This collection of files showcases various operations and tasks that can be performed on linked lists, expanding on the concepts introduced in the previous repository.

## Overview

Linked lists offer a dynamic and flexible way to organize and manage data. Unlike arrays, linked lists do not require contiguous memory allocation, allowing for efficient insertion and deletion of elements at any position. Each element in a linked list, known as a node, contains a data field and a reference to the next node. This structure enables traversing the list by following the next pointers from one node to another.

The provided functions in this repository cover essential operations on linked lists, including printing the elements, adding nodes at the beginning or end, deleting nodes, finding loops, and more. These functions can be used to manipulate linked lists based on specific requirements and provide a foundation for building more complex data structures and algorithms.


# Files
By exploring the files in this repository, you will gain a deeper understanding of linked lists and enhance your skills in working with them in the C programming language. Each file focuses on a specific operation or task, providing clear implementations and usage examples to assist you in incorporating these functionalities into your own projects.

Below is a table summarizing the function of each file:

| File Name              | Function                                                          |
|------------------------|-------------------------------------------------------------------|
| **Simple**             |                                                                   |
| `1-listint_len.c`      | Get the number of elements in a linked list                        |
| `2-add_nodeint.c`      | Add a new node at the beginning of a linked list                   |
| `3-add_nodeint_end.c`  | Add a new node at the end of a linked list                         |
| `4-free_listint.c`     | Free a linked list                                                |
| `5-free_listint2.c`    | Free a linked list and set the head to NULL                        |
| `6-pop_listint.c`      | Remove the head node and return its value                          |
| `7-get_nodeint.c`      | Get the nth node of a linked list                                  |
| `8-sum_listint.c`      | Calculate the sum of all the elements in a list                    |
| `9-insert_nodeint.c`   | Insert a new node at a given position in the list                  |
| `10-delete_nodeint.c`  | Delete a node at a given position in the list                      |
| **Advanced**           |                                                                   |
| `100-reverse_listint.c`      | Reverse a linked list                                            |
| `101-print_listint_safe.c`   | Safely print all elements of a linked list                         |
| `102-free_listint_safe.c`    | Safely free a linked list                                         |
| `103-find_loop.c`            | Find if a loop exists in a linked list                             |
| **Header**             |                                                                   |
| `lists.h`                   | Header file containing function prototypes                         |

## Usage

To use these functions, follow the steps below:

1. Include the `lists.h` header file in your C program.

2. Compile your program along with the necessary source files.

3. Create a linked list by declaring a pointer to the head of the list.

4. Initialize the list by assigning NULL to the head pointer.

5. Use the provided functions to perform operations on the linked list.

### Example 1: Printing a `listint_t` list

The file `0-print_listint.c` contains a function `print_listint` that prints all elements of a `listint_t list`.

File: `0-print_listint.c`
```c
#include "lists.h"
#include <stdio.h>

/**
 * print_listint - print all elements of a 'listint_t' list
 * @h: head of linked list
 * Return: # of nodes
 */

size_t print_listint(const listint_t *h)
{
        const listint_t *c;
        size_t count;

        for (c = h, count = 0; c != NULL; count++, c = c->next)
                printf("%d\n", c->n);

        return (count);
}
```

Let's assume we have the following linked list:
```c
listint_t *head = NULL;
listint_t *node1, *node2, *node3;

node1 = malloc(sizeof(listint_t));
node1->n = 1;
node1->next = NULL;

node2 = malloc(sizeof(listint_t));
node2->n = 2;
node2->next = NULL;

node3 = malloc(sizeof(listint_t));
node3->n = 3;
node3->next = NULL;

head = node1;
node1->next = node2;
node2->next = node3;
```

To print the elements of this linked list, we can use the `print_listint` function as follows:
```c
#include "lists.h"
#include <stdio.h>

int main(void)
{
    listint_t *head = NULL;
    listint_t *node1, *node2, *node3;

    node1 = malloc(sizeof(listint_t));
    node1->n = 1;
    node1->next = NULL;

    node2 = malloc(sizeof(listint_t));
    node2->n = 2;
    node2->next = NULL;

    node3 = malloc(sizeof(listint_t));
    node3->n = 3;
    node3->next = NULL;

    head = node1;
    node1->next = node2;
    node2->next = node3;

    size_t node_count = print_listint(head);
    printf("Number of nodes: %lu\n", node_count);

    return 0;
}
```

To compile and run the code, you can use the following commands:
```bash
gcc -Wall -Wextra -Werror -pedantic 0-print_listint.c main.c -o print_listint
./print_listint
```

Expected output:
```shell
1
2
3
Number of nodes: 3
```

In this example, we created a linked list with three nodes, each containing an integer value. The `print_listint` function is used to print the elements of the linked list, and the total number of nodes is then displayed. The expected output shows the elements `1`, `2`, and `3` printed on separate lines, followed by the number of nodes in the list, which is `3`.

### Example 2: Freeing a `listint_t` list and setting the head to `NULL`

Let's assume we have the following linked list, as before:

```c
listint_t *head = NULL;
listint_t *node1, *node2, *node3;

node1 = malloc(sizeof(listint_t));
node1->n = 1;
node1->next = NULL;

node2 = malloc(sizeof(listint_t));
node2->n = 2;
node2->next = NULL;

node3 = malloc(sizeof(listint_t));
node3->n = 3;
node3->next = NULL;

head = node1;
node1->next = node2;
node2->next = node3;
```

To free the memory allocated for the linked list, we can use the `free_listint2` function as follows:

```c
#include "lists.h"
#include <stdlib.h>

int main(void)
{
    listint_t *head = NULL;
    listint_t *node1, *node2, *node3;

    node1 = malloc(sizeof(listint_t));
    node1->n = 1;
    node1->next = NULL;

    node2 = malloc(sizeof(listint_t));
    node2->n = 2;
    node2->next = NULL;

    node3 = malloc(sizeof(listint_t));
    node3->n = 3;
    node3->next = NULL;

    head = node1;
    node1->next = node2;
    node2->next = node3;

    free_listint2(&head);

    return 0;
}
```

To compile and run the code, you can use the following commands:
```shell
gcc -Wall -Wextra -Werror -pedantic 5-free_listint2.c main.c -o free_listint2
./free_listint2
```

In this example, we created a linked list with three nodes, each containing an integer value.

The `free_listint2` function is used to free the memory allocated for the linked list. After calling the function, the memory used by the linked list will be freed.

### Example 3: Example 3: Finding a loop in a `listint_t` list

The file `103-find_loop.c` contains a function `find_listint_loop` that finds a loop in a `listint_t` list.

File: `103-find_loop.c`
```c
#include "lists.h"

/**
 * find_listint_loop - finds loop in 'listint_t' list
 * @head: linked list to search for
 * Return:
 *      (If successful) Address of new element
 *      (If unsuccessful) NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
        listint_t *slow = head;
        listint_t *fast = head;

        if (!head)
                return (NULL);

        while (slow && fast && fast->next)
        {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                {
                        slow = head;
                        while (slow != fast)
                        {
                                slow = slow->next;
                                fast = fast->next;
                        }
                        return (fast);
                }
        }

        return (NULL);
}
```

Example application:

1. We create a linked list with a loop. Let's assume the list has the following nodes: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop back to node 3).
2. We call the find_listint_loop function, passing the head of the linked list as an argument.
3. The function detects the loop in the linked list and returns the address of the node where the loop starts.
4. We can use this returned address for further analysis or operations.

```c
#include "lists.h"
#include <stdio.h>

int main(void)
{
    /* Create the linked list with a loop */
    listint_t *head = NULL;
    listint_t *node1 = add_nodeint_end(&head, 1);
    listint_t *node2 = add_nodeint_end(&head, 2);
    listint_t *node3 = add_nodeint_end(&head, 3);
    listint_t *node4 = add_nodeint_end(&head, 4);
    listint_t *node5 = add_nodeint_end(&head, 5);
    node5->next = node3; // Create a loop by connecting node 5 to node 3

    /* Find the loop in the linked list */
    listint_t *loop_start = find_listint_loop(head);

    if (loop_start != NULL)
    {
        printf("Loop detected! Loop starts at address: %p\n", (void *)loop_start);
    }
    else
    {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
```
Expected Output:
```shell
Loop detected! Loop starts at address: 0xADDRESS_OF_NODE3
```

In this example, we demonstrate how to use the `find_listint_loop` function to detect a loop in a linked list. By creating a linked list with a loop and calling the function, we are able to identify the starting point of the loop.
