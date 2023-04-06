#ifndef BINARY_H
#define BINARY_H
#include <ctype.h>
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number as string
 *
 * Return: converted number, or 0 if b is NULL or has chars that aren't 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int my_num = 0;

if (b == NULL)
return (0);

while (*b)
{
if (!isdigit(*b) || (*b != '0' && *b != '1'))
return (0);

my_num <<= 1;
my_num += (*b++ - '0');
}

return (my_num);
}

#endif /* BINARY_H */

