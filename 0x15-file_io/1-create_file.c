#include "main.h"

/**
 * create_file- read and print to stdout
 * @filename:  name of file passed as argument
 * @text_content: content
 * Return:
 *      ( 1) if success
 *      (-1) if fail
 */

int create_file(const char *filename, char *text_content)
{
	mode_t mode;
	ssize_t bytes_written;
	size_t length;
	int flags, fd;

	if (!filename)
	{
		return (-1);
	}

	mode = S_IRUSR | S_IWUSR;
	flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, mode);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content)
	{
		length = 0;
		while (text_content[length] != '\0')
		{
			length++;
		}

		bytes_written = write(fd, text_content, length);
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
