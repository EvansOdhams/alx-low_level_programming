#include "main.h"

/**
* Accepts a number and print out a binary.
* 'n' The number to be printed in binary.
*
* Return:(0)
*/
void print_binary(unsigned long int n)
{
int i, check = 0;

if (n == 0)
{
_putchar('0');
return;
}

for (i = 63; i >= 0; i--)
{
if ((n >> i) & 1)
{
check = 1;
_putchar('1');
}
else if (check)
_putchar('0');
}
}

