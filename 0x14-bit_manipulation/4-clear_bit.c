#include "main.h"

/**
* clear_bit - Sets the value of a bit to 0 at a given index.
* @n: A pointer to the number to modify.
* @index: The index of the bit to clear, starting from 0.
*
* Return: 1 if the operation was successful, or -1 otherwise.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
/* Check if the index is greater than the number of bits in the number */
if (index >= (sizeof(unsigned long int) * 8))
{
return (-1);
}

/* Clear the bit at the given index */
*n &= ~(1UL << index);

return (1);
}

