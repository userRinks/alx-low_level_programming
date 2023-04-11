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
	ssize_t rcount, wcount;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}
	rcount = read(fd, buffer, letters);
	if (rcount == -1)
		return (0);

	wcount = write(STDOUT_FILENO, buffer, rcount);
	if (wcount == -1 || rcount != wcount)
		return (0);
	free(buffer);

	close(fd);
	return (wcount);
}
