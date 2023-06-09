#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
* create_new_node - Creates a new hash_node_t and initializes it
* @key: The key for the new node
* @value: The value for the new node
*
* Return: The newly created node, or NULL on failure
*/
hash_node_t *create_new_node(const char *key, const char *value)
{
hash_node_t *new_node = malloc(sizeof(hash_node_t));

if (new_node == NULL)
return (NULL);

new_node->key = strdup(key);
new_node->value = strdup(value);
new_node->next = NULL;

return (new_node);
}

/**
* hash_table_set - Adds or updates an element in the hash table
* @ht: The hash table to modify
* @key: The key to add or update
* @value: The value associated with the key
*
* Return: 1 if successful, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *new_node, *temp;

if (ht == NULL || key == NULL || *key == '\0')
return (0);

index = key_index((unsigned char *)key, ht->size);

temp = ht->array[index];
while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
{
free(temp->value);
temp->value = strdup(value);
return (1);
}
temp = temp->next;
}

new_node = create_new_node(key, value);
if (new_node == NULL)
return (0);

new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
