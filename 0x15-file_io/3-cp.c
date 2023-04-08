#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
* main - Copies the content of a file to another file.
* @argc: Number of arguments passed to the program.
* @argv: Array of pointers to strings containing the arguments.
*
* Return: 0 on success, other value on failure.
*/
int main(int argc, char *argv[])
{
int file_from, file_to, read_retval, write_retval, close_retval;
char buffer[BUFFER_SIZE];

if (argc != 3)
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (file_to == -1)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

while ((read_retval = read(file_from, buffer, BUFFER_SIZE)) > 0)
{
write_retval = write(file_to, buffer, read_retval);
if (write_retval != read_retval || write_retval == -1)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
}

if (read_retval == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

close_retval = close(file_from);
if (close_retval == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

close_retval = close(file_to);
if (close_retval == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

return (0);
}

