#include <stdio.h>

/**
* hash_djb2 - Hash function using the djb2 algorithm
* @str: The string to hash
*
* Return: The calculated hash value
*/
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash = 5381;
int c;

/* djb2 hash algorithm */
while ((c = *str++))
{
hash = ((hash << 5) + hash) +c; /* hash * 33 + c */
}
return (hash);
}
