#include "main.h"

/**
* get_bit - Returns the value of a bit at a given index.
*
* @n: The number to search for the bit.
* @index: The index of the bit to return.
*
* Return: The value of the bit at index index or -1 if an error occurred.
*/
int get_bit(unsigned long int n, unsigned int index)
{
int bit;

if (index >= sizeof(unsigned long int) * 8)
return (-1);

bit = (n >> index) & 1;

return (bit);
}

