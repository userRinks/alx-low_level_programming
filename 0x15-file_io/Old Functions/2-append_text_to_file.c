#include "main.h"

/**
 * append_text_to_file - read and add into file
 * @filename:  name of file passed as argument
 * @text_content: content of file
 * Return:
 *      ( 1) if success
 *      (-1) if fail
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, result = -1, text_len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[text_len] != '\0')
			text_len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		result = write(fd, text_content, text_len);
		if (result == -1)
		{
			result = -1;
		}
	}
	else
	{
		result = 1;
	}

	close(fd);
	return (result);
}
