#include "hash_tables.h"
#include <stdlib.h>

/**
* hash_table_create - Creates a hash table
* @size: The size of the hash table
*
* Return: A pointer to the newly created hash table,
*         or NULL if the creation fails
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *ht;

if (size == 0)
return (NULL);

ht = malloc(sizeof(hash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(hash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

return (ht);
}
