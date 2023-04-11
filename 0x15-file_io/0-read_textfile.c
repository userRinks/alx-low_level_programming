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
	int fd;
	ssize_t bytes_read = 0, bytes_written = 0;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);		/* open */
	if (fd == -1)
	{
		return (0);
	}

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);		/* read */
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);					/* write to POSIX terminal */

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		return (0);
	}

	return (bytes_written);
}
