#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
* main - Entry point
*
* Return: Exit status
*/
int main(void)
{
hash_table_t *ht;

ht = hash_table_create(1024);
hash_table_set(ht, "y", "0");
hash_table_print(ht);
hash_table_print_rev(ht);
hash_table_delete(ht);

return (EXIT_SUCCESS);
}
