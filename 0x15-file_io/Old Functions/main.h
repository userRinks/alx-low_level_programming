#ifndef MAIN_H
#define MAIN_H

/** Included other standard libraries just in case I forget to include them where necessary */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
