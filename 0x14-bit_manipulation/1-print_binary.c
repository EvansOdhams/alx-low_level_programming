#include "main.h"

/**
* print_binary - prints the binary representation of a number
* @n: the number to print in binary
*
* Return: void
*/
void print_binary(unsigned long int n)
{
/* Set the mask to the least significant bit (LSB) of n */
unsigned long int mask = 1;

/* Find the most significant bit (MSB) of n */
while (mask < n)
mask = (mask << 1) | 1;

/* print the binary representation of n */
while (mask)
{
if (n & mask) /* check if the mask bit is set in n */
_putchar('1'); /* print 1 if set */
else
_putchar('0'); /* print 0 if not set */
mask = mask >> 1; /* shift the mask to the right */
}
}

