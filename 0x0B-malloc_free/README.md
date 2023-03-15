# 0x0B. C - malloc, free

Using automatic, and dynamic allocation to manipulate functions and allocate/free variables and pointers.

## Description
Generally, we use variables and arrays with a known constant size to write functions and compute logical systems. But sometimes, it is difficult to know the size of the array one has to declare and/or if this size depends on another variable. Where multiple variables are to be used, a successful program has to consider arguments that can accommodate these variables.

By manipulating dynamic and automatic memory allocation, one can allocate size bytes and return a pointer to the allocated memory without needing to initialize a variable on the memory itself.
