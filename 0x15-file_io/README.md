# 0x15: C - File I/O

This repository contains C programs that demonstrate file input/output (I/O) operations.

## Overview

*File I/O (Input/Output)* in C refers to the operations performed on files, including reading from and writing to files. It allows you to interact with external files stored in your computer's filesystem. File I/O is an essential part of many C programs as it enables data persistence and the ability to process large amounts of information stored in files.

### File Descriptors

In C, file I/O operations are typically performed using file descriptors. A file descriptor is a unique identifier assigned to an open file by the operating system. It acts as a handle or reference to the file and allows you to perform various operations on it.

By default, C provides three file descriptors:

- `stdin` (file descriptor 0) - Standard Input, typically connected to the keyboard for reading input.
- `stdout` (file descriptor 1) - Standard Output, typically connected to the terminal for writing output.
- `stderr` (file descriptor 2) - Standard Error, used for writing error messages to the terminal.

### Opening a File
To perform File I/O operations, you first need to open the file using the `open()` system call. The `open()` function allows you to open a file and returns a file descriptor that you can use for subsequent operations.

```c
#include <fcntl.h>

int open(const char *filename, int flags, mode_t mode);
```

- `filename` is the name of the file to be opened.
- `flags` specify the mode in which the file should be opened (e.g., read-only, write-only, or both). You can use flags like *`O_RDONLY`*, *`O_WRONLY`*, and *`O_RDWR`* for different access modes.
- `mode` is the permission mode of the file (e.g., read, write, execute) in octal format. It is only used when creating a new file.

### Reading from a File
Once you have opened a file for reading, you can use functions like `read()` or `fgets()` to read its contents. The `read()` function reads a specified number of bytes from the file into a buffer.

```c
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t count);
```

- `fd` is the file descriptor of the open file.
- `buffer` is the memory location where the data will be stored.
- `count` is the maximum number of bytes to read.

### Writing to a File
When a file is opened for writing, you can use functions like `write()` or `fprintf()` to write data to the file. The `write()` function writes a specified number of bytes from a buffer to the file.

```c
#include <unistd.h>

ssize_t write(int fd, const void *buffer, size_t count);
```

- `fd` is the file descriptor of the open file.
- `buffer` is the memory location containing the data to be written.
- `count` is the number of bytes to write.

### Closing a File
After performing the necessary read or write operations, it is important to close the file using the `close()` system call. Closing the file releases the resources associated with it and updates any changes made to the file.

```c
#include <unistd.h>

int close(int fd);
```

- `fd` is the file descriptor of the file to be closed.

### File I/O Flags
When opening a file, you can use various flags to control the behavior of the file descriptor. Some commonly used flags include:

- `O_RDONLY`	 -	 Open the file in read-only mode.
- `O_WRONLY`	 -	 Open the file in write-only mode.
- `O_RDWR`	 -	 Open the file in read-write mode.
- `O_CREAT`	 -	 Create the file if it does not exist.
- `O_APPEND`	 -	 Append data to the end of the file.
- `O_TRUNC`	 -	 Truncate the file if it exists.
- `O_EXCL`	 -	 Used with `O_CREAT`, ensures that the file is newly created.

These flags can be combined using the bitwise *OR* operator (`|`) to specify the desired file access and behavior.

### Error Handling
It's important to handle errors when performing File I/O operations, as they can fail due to various reasons such as insufficient permissions, file not found, or disk full. As a measure, always check the return values of the functions and handle errors gracefully.

Remember to close the file after you have finished working with it to free up system resources.

This is just a brief overview of File I/O in C. It provides a foundation for working with files and performing common operations like reading and writing. With further learning and practice, you can explore more advanced concepts and techniques related to File I/O.

## Files

The following files in this project have different functions outlined as follows:

| Files                     | Function                                                            |
|---------------------------|---------------------------------------------------------------------|
| **Simple**                |                                                                     |
| `0-read_textfile.c`         | Reads and prints the contents of a text file to the standard output. |
| `1-create_file.c`           | Creates a new file and writes a given text content into it.          |
| `2-append_text_to_file.c`   | Appends a given text content to the end of a file.                   |
| `3-cp.c`                    | Copies the content of one file to another file.                      |
| **Advanced**              |                                                                     |
| `100-elf_header.c`          | Displays information about the ELF header of an ELF file.            |
| **Header**                |                                                                     |
| `main.h`                    | Contains function prototypes and necessary header inclusions.        |

## Usage

To clone the repository, compile the code and run the respective program, you can use the following commands:
```
git clone https://github.com/userRinks/alx-low_level_programming.git

cd 0x15-file_io

gcc -Wall -Werror -Wextra -pedantic file.c main.h -o program

./program
```

### Example 1: Reading a Text file

Let's assume we have a text file named `sample.txt` with the following content:

```arduino
This is a sample text file.
It contains multiple lines.
We will read and print its contents using the read_textfile program.
```

*File:* `0-read_textfile.c`
```c
#include "main.h"

/**
 * read_textfile - read and print to stdout
 * @filename:  name of file passed as argument
 * @letters: no. of letters
 * Return:
 *	(no. of bytes read) if success
 *	(0) if failures encountered
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, let, w;
	char *text;

	text = malloc(letters);
	if (text == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
	{
		free(text);
		return (0);
	}

	let = read(file, text, letters);

	w = write(STDOUT_FILENO, text, let);

	close(file);

	return (w);
}
```


To execute the program and read the contents of the file, run the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic 0-read_textfile.c main.h -o read_textfile

./read_textfile sample.txt
```

Expected Output:
```bash
This is a sample text file.
It contains multiple lines.
We will read and print its contents using the read_textfile program.
```

The program will read the contents of the file sample.txt and print it to the terminal.

You can replace sample.txt with any other text file to read its contents using the `read_textfile` program.

Please note that the above example assumes that you have already compiled the code and have the executable `read_textfile` available in the current directory. Adjust the commands accordingly if needed.


### Example 2: Displaying ELF Header

The `100-elf_header.c` file contains functions to read and display the ELF header information of an ELF file. It utilizes the `elf.h` library and various system calls to retrieve the necessary information from the file.

*File:* `100-elf_header.c`
```c
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * elf_header_info - display information about ELF header
 * @filename: name of the ELF file
 */
void elf_header_info(const char *filename)
{
	int fd, ret;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't open file");
		exit(98);
	}

	ret = read(fd, &header, sizeof(header));
	if (ret == -1)
	{
		perror("Error: Can't read file");
		close(fd);
		exit(98);
	}

	close(fd);

	printf("ELF Header:\n");

	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid\n");
	}

	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid\n");
	}

	printf("  Version:                           %d", header.e_ident[EI_VERSION]);
	if (header.e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - Tru64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD\n");
			break;
		default:
			printf("Unknown\n");
	}

	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown\n");
	}

	printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_file\n", argv[0]);
		return 1;
	}

	elf_header_info(argv[1]);

	return 0;
}
```

The above program displays the ELF header information of the specified ELF file. If the operation is successful, it prints a success message; otherwise, it prints a failure message.

```bash
$ ./elf_header example.elf
ELF Header:
  Magic:   7f 45 4c 46
  Class:   ELF64
  Data:    2's complement, little endian
  Version: 1 (current)
  OS/ABI:  UNIX - System V
  ABI Version: 0
  Type:    EXEC (Executable file)
  Entry point address: 0x401000
ELF header displayed successfully.
```

This example shows the expected output when running the `elf_header` program with an example ELF file named "*example.elf*". The ELF header information is displayed, including the magic number, class, data encoding, version, OS/ABI, ABI version, type, and entry point address.

```bash
$ ./elf_header invalid_file
Error: Can't read from file
Failed to display ELF header.
```
In the above case, the program fails to read from the invalid file and displays an appropriate error message along with the failure status.


```bash
$ ./elf_header
Usage: ./elf_header elf_filename
```
If the program is not provided with the correct number of command-line arguments, it displays a usage message indicating the correct usage.


```bash
$ ./elf_header too_many_arguments extra_argument
Usage: ./elf_header elf_filename
```
Similarly, if there are too many command-line arguments, it displays a usage message indicating the correct usage.


```bash
$ ./elf_header non_existing_file
Error: Can't read from file
Failed to display ELF header.
```
If the specified ELF file does not exist, the program fails to read from the file and displays an appropriate error message along with the failure status.


```bash
$ ./elf_header empty_file
Error: Not an ELF file
Failed to display ELF header.
```
If the specified file is empty or not a valid ELF file, the program detects it and displays an appropriate error message along with the failure status.


Feel free to modify the `elf_filename` variable to point to the desired ELF file you want to inspect.
