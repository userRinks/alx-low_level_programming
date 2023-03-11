
# My Static Library

Creating my own static library.

## Description

The libraries `liball.a` and `libmy.a` contain simple scripts that manipulate strings. I first wrote these strings in simple C code, compiled them into object code and included the output in the libraries for future use.

## Ok, so what do these files do?

Pretty much just:
- [x] Set memory values
- [x] Set pointers to variables
- [x] Check if a variable is a digit
- [x] Check if it's an alphanumeric character
- [x] Check for lower case letters
- [x] Check the length of a string
- [x] Print string to standard output
- [x] Concatenate with different strings through:
    - finding pointers
    - locating strings
    - copying
    - comparing values

### Dependencies

* Shell terminal.
* GCC Compiler.
* Dissassembler/delinker.

### Header File
The header file `main.h` is an important script that is included in every `.c` program used in this repository.
It allows my scripts to run with set declared variables that enable me to generate recursive scripts.

For example, for `6-abs.c`

The code:
  ```
  #include "main.h"
  int _abs(int n)
    {
	    return (abs(n));
    }
   ```
   will instruct the compiler to comb through the file `main.h` and find a corresponding call function.
   
   Hypothetically it will go:
   
   ```#ifndef FILE_MAIN
      #define FILE_MAIN

      /*copy list from task*/

      int _putchar(char c);
      int _islower(int c);
      int _isalpha(int c);
      int _abs(int n);
      int _isupper(int c);
   ```
and select
```int_abs(int n);```

which will will now be argued as:
```
  /*From:*/                             /*To:*/
  
  #include "main.h"                     int_abs(int n);
                                        int abs
                                        int n
   int_abs(int n)                       int abs (int n)
    {                                   {
	    return (abs(n));                     return (abs(n));
    }                                   }
 ```
### Static Library

* The library `liball.a` contains all instructions for the `.c` files compiled with header `main.h` included, currently listed as executable programs `.o`
    This is an easier way of running all these scripts on a file concurrently without running them one-by-one manually.
* File `create_static_lib.sh` is a simple shell script that creates a static library called `liball.a` from all the .c files that are in the current directory. In this case, the current/working directory is this repository.

### Executing program/Displaying executable contents

* The programs ending in `.o` can be translated into easily understandable language in most terminals with GCC/GNU compiler and a suitable linker/dissassembler installed.
* If using linux, you can use `objdump` or `hexdump` to test a c file or see the output of a raw file.
    
    Example:
      
      $: gcc -c 6-abs.c
      
      $: objdump -D 6-abs.o
