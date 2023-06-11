#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* shash_table_create - Creates a new sorted hash table
* @size: The size of the hash table
*
* Return: A pointer to the created hash table, or NULL on failure
*/
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht = NULL;
unsigned long int i;

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
* shash_table_set - Adds or updates a key-value pair in the sorted hash table
* @ht: The hash table
* @key: The key string
* @value: The value corresponding to the key
*
* Return: 1 on success, 0 on failure
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *node, *prev, *new_node;

if (ht == NULL || key == NULL || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];

while (node != NULL)
{
if (strcmp(node->key, key) == 0)
{
free(node->value);
node->value = strdup(value);
return (1);
}
node = node->next;
}

new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
return (0);

new_node->key = strdup(key);
new_node->value = strdup(value);
new_node->next = ht->array[index];
ht->array[index] = new_node;

if (ht->shead == NULL || strcmp(new_node->key, ht->shead->key) < 0)
{
new_node->sprev = NULL;
new_node->snext = ht->shead;
if (ht->shead != NULL)
ht->shead->sprev = new_node;
ht->shead = new_node;
if (ht->stail == NULL)
ht->stail = new_node;
}
else
{
prev = ht->shead;
while (prev->snext != NULL && strcmp(new_node->key, prev->snext->key) >= 0)
prev = prev->snext;

new_node->sprev = prev;
new_node->snext = prev->snext;

if (prev->snext != NULL)
prev->snext->sprev = new_node;
else
ht->stail = new_node;

prev->snext = new_node;
}

return (1);
}

/**
* shash_table_get - Retrieves the value associated with a key in the sorted hash table
* @ht: The hash table
* @key: The key string
*
* Return: The value associated with the key, or NULL if not found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *node;

if (ht == NULL || key == NULL)
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];

while (node != NULL)
{
if (strcmp(node->key, key) == 0)
return (node->value);

node = node->next;
}

return (NULL);
}

/**
* shash_table_print - Prints the sorted hash table using the sorted linked list
* @ht: The hash table
*/
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
int flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->shead;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->snext;
}
printf("}\n");
}

/**
* shash_table_print_rev - Prints the sorted hash table in reverse order using the sorted linked list
* @ht: The hash table
*/
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
int flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->stail;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->sprev;
}
printf("}\n");
}

/**
* shash_table_delete - Frees the memory allocated for the sorted hash table
* @ht: The hash table
*/
void shash_table_delete(shash_table_t *ht)
{
unsigned long int i;
shash_node_t *node, *next;

if (ht == NULL)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
next = node->next;
free(node->key);
free(node->value);
free(node);
node = next;
}
}

free(ht->array);
free(ht);
}
