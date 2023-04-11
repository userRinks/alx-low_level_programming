#include "main.h"
#include <errno.h>

#define BUF_SIZE 1024

int open_file(char *file_path, int flags, mode_t mode);
void copy_file(char *file_from, char *file_to, int *fd_from, int *fd_to);
void close_file(int fd, char *file_path);
void error(char *message, char *file_path);
void error_exit(char *message);

/**
 * main - copy content of file into other file
 * @argc: argument count (no. of arguments)
 * @argv: argument vector (1st, 2nd or 3rd argument)
 * Return: (0) or code (97-100)
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		error_exit("Usage: cp file_from file_to");
	}
	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2],
			O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	copy_file(argv[1], argv[2], &fd_from, &fd_to);
	return (0);
}

/**
 * open_file - open file
 * @file_path: file path
 * @flags: flags
 * @mode: permissions
 * Return: fd
 */
int open_file(char *file_path, int flags, mode_t mode)
{
	int fd;

	fd = open(file_path, flags, mode);
	if (fd == -1)
	{
		error("Error: Can't open file ", file_path);
	}
	return (fd);
}

#define BUFFER_SIZE 1024
/**
 * copy_file - function to copy file
 * @file_from: first argument
 * @file_to: second argument
 * @fd_from: from argument 1
 * @fd_to: to argument 2
 */

void copy_file(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	char buffer[BUFFER_SIZE] = {0};
	ssize_t bytes_read, bytes_written;
	int fd_from_val = *fd_from;
	int fd_to_val = *fd_to;

	while ((bytes_read = read(fd_from_val, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to_val, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			error("Error: Can't write to ", file_to);
		}
	}
	close_file(fd_from_val, file_from);
	close_file(fd_to_val, file_to);
}

/**
 * close_file - close file
 * @fd: int that opens files
 * @file_path: file path
 */
void close_file(int fd, char *file_path)
{
	if (close(fd) == -1)
	{
		error("Error: Can't close fd ", file_path);
	}
}

/**
 * error_exit - print error message
 * @message: message
 */
void error_exit(char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(EXIT_FAILURE);
}


/**
 * error - print error message
 * @message: code
 * @file_path: file path
 */
void error(char *message, char *file_path)
{
	dprintf(STDERR_FILENO, "%s%s\n", message, file_path);
	if (file_path[0] != '\0')
	{
		dprintf(STDERR_FILENO, "%s\n", file_path);
	}
	perror("");
	exit(EXIT_FAILURE);
}
