# Recursion

Learning and manipulating recursive functions.

## Overview

Recursion is a concept in programming where a function calls itself to solve a problem. It can be thought of as a process of solving a complex problem by breaking it down into smaller, simpler instances of the same problem.

Recursion is particularly useful when working with problems that have a recursive structure or can be expressed in terms of smaller subproblems.

## Use
This repository contains a collection of files related to recursion. Each file serves a specific purpose and contributes to the overall understanding of recursion.

Below is a table summarizing the function of each file:
| File Name                | Function                                                      |
|--------------------------|---------------------------------------------------------------|
| **Simple**               |
| 0-puts_recursion.c       | Prints a string recursively                                    |
| 1-print_rev_recursion.c  | Prints a string in reverse using recursion                     |
| 2-strlen_recursion.c     | Calculates the length of a string recursively                  |
| 3-factorial.c            | Calculates the factorial of a number recursively               |
| 4-pow_recursion.c        | Calculates the power of a number recursively                   |
| 5-sqrt_recursion.c       | Calculates the square root of a number recursively             |
| 6-is_prime_number.c      | Checks if a number is prime using recursion                    |

| **Advanced**             |
| 100-is_palindrome.c      | Checks if a string is a palindrome using recursion             |
| 101-wildcmp.c            | Compares two strings and returns 1 if they are identical, 0 otherwise |


## Examples

### Example 1: Printing a String in Reverse

The file `1-print_rev_recursion.c` contains a function `print_rev_recursion` that takes a string as input and prints it in reverse order. It achieves this by using recursion to print the last character of the string, and then recursively calling itself with the remaining substring excluding the last character. This process continues until the entire string is printed in reverse order.

**File:** `1-print_rev_recursion.c`

```c
#include "main.h"

/**
 * _print_rev_recursion - reverse string
 * @s: pointer to string
 * Return: void
 */

void _print_rev_recursion(char *s)
{
        if (*s > '\0')
        {
                _print_rev_recursion(s + 1);
                _putchar(*s);
        }

}

```
When we call `_print_rev_recursion` with a phrase such as "Hello, World!" we can
expect an output :

```Terminal
!dlroW ,olleH
```

### Example 2: Recursive String Comparison with Wildcards

**File:** `101-wildcmp.c`

```c
#include "main.h"

/**
 * wildcmp - Compare strings, with wildcard function
 * @s1: pointer to first string
 * @s2: pointer to second string
 * Return: 0
 */

int wildcmp(char *s1, char *s2)
{
        if (*s1 == '\0')
        {
                if (*s2 != '\0' && *s2 == '*')
                {
                        return (wildcmp(s1, s2 + 1));
                }
                return (*s2 == '\0');
        }

        if (*s2 == '*')
        {
                return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
        }
        else if (*s1 == *s2)
        {
                return (wildcmp(s1 + 1, s2 + 1));
        }
        return (0);
}
```

The `wildcmp()` function recursively compares the characters in the strings. It checks if the current character in `s1` matches the current character in `s2` or if `s2` contains a wildcard character ('*').

If the character in `s1` is '\0' (end of the string), the function checks if `s2` is also at its end or if `s2` has a wildcard character following it. If so, the function recursively calls itself with `s2` shifted by one character to match the wildcard.

If the character in `s2` is a wildcard, the function makes two recursive calls: one with `s1` shifted by one character to match the wildcard, and another with `s2` shifted by one character to skip the wildcard.

If the current characters in `s1` and `s2` match, the function recursively calls itself with both pointers shifted by one character.

The function returns `1` if the strings are identical, and `0` if the strings do not match.
