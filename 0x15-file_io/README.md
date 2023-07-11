# 0x15: C - File I/O

This repository contains C programs that demonstrate file input/output (I/O) operations.

## Description



## Files



| Files                     | Function                                                            |
|---------------------------|---------------------------------------------------------------------|
| **Simple**                |                                                                     |
| 0-read_textfile.c         | Reads and prints the contents of a text file to the standard output. |
| 1-create_file.c           | Creates a new file and writes a given text content into it.          |
| 2-append_text_to_file.c   | Appends a given text content to the end of a file.                   |
| 3-cp.c                    | Copies the content of one file to another file.                      |
| **Advanced**              |                                                                     |
| 100-elf_header.c          | Displays information about the ELF header of an ELF file.            |
| **Header**                |                                                                     |
| main.h                    | Contains function prototypes and necessary header inclusions.        |

## Usage

To clone the repository, compile the code and run the respective program, you can use the following commands:
```
git clone https://github.com/userRinks/alx-low_level_programming.git

cd 0x15-file_io

gcc -Wall -Werror -Wextra -pedantic file.c main.h -o program

./program
```

### Example 1: Reading a Text file

Let's assume we have a text file named sample.txt with the following content:

```arduino
This is a sample text file.
It contains multiple lines.
We will read and print its contents using the read_textfile program.
```

To execute the program and read the contents of the file, run the following command:
```bash
./read_textfile sample.txt
```

Expected Output:
```bash
This is a sample text file.
It contains multiple lines.
We will read and print its contents using the read_textfile program.
```

The program will read the contents of the file sample.txt and print it to the terminal.

You can replace sample.txt with any other text file to read its contents using the read_textfile program.

Please note that the above example assumes that you have already compiled the code and have the executable read_textfile available in the current directory. Adjust the commands accordingly if needed.
