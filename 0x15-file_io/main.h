#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
/*Prototype for a function that creates a file.*/
int create_file(const char *filename, char *text_content);
/*Prototype for a function that appends text at the end of a file.*/
int append_text_to_file(const char *filename, char *text_content);
#endif /* MAIN_H */
