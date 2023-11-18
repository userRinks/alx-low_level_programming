#!/bin/bash
gcc *.c -c -fpic
gcc -Wall -Werror -Wextra -pedantic -shared -o liball.so *.o
