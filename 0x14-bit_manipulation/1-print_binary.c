#include "main.h"

/**
* print_binary - prints the binary representation of a number
* @n: the number to print in binary
*
* Return: void
*/
void print_binary(unsigned long int n)
{
unsigned long int mask = 1;
unsigned int len = sizeof(unsigned long int) * 8;

/* shift mask to left until it reaches the highest 1 bit in n */
while (len--)
{
if ((n >> len) & 1)
break;
mask <<= 1;
}

/* print binary representation */
while (mask)
{
if (n & mask)
_putchar('1');
else
_putchar('0');
mask >>= 1;
}
}
