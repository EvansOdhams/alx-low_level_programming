#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* shash_table_create - Creates a sorted hash table
* @size: Size of the array
*
* Return: Pointer to the newly created hash table, NULL on failure
*/
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

if (size == 0)
return (NULL);

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
* shash_table_node_create - Creates a sorted hash table node
* @key: Key string
* @value: Value string
*
* Return: Pointer to the newly created node, NULL on failure
*/
shash_node_t *shash_table_node_create(const char *key, const char *value)
{
shash_node_t *node;

node = malloc(sizeof(shash_node_t));
if (node == NULL)
return (NULL);

node->key = strdup(key);
node->value = strdup(value);
node->next = NULL;
node->sprev = NULL;
node->snext = NULL;

return (node);
}

/**
* shash_table_set - Adds an element to a sorted hash table
* @ht: Pointer to the hash table
* @key: Key string
* @value: Value string
*
* Return: 1 on success, 0 on failure
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *new_node, *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
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

new_node = shash_table_node_create(key, value);
if (new_node == NULL)
return (0);

new_node->next = ht->array[index];
ht->array[index] = new_node;

if (ht->shead == NULL)
{
ht->shead = new_node;
ht->stail = new_node;
}
else
insert_sorted_node(ht, new_node);

return (1);
}

/**
* shash_table_get - Retrieves a value associated with a key in a sorted hash table
* @ht: Pointer to the hash table
* @key: Key string
*
* Return: Value associated with the key, NULL if key is not found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
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
* shash_table_print - Prints a sorted hash table in key/value order
* @ht: Pointer to the hash table
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
* shash_table_print_rev - Prints a sorted hash table in reverse key/value order
* @ht: Pointer to the hash table
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
* shash_table_delete - Deletes a sorted hash table
* @ht: Pointer to the hash table
*/
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *temp;
unsigned long int i;

if (ht == NULL)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
temp = node;
node = node->next;
free(temp->key);
free(temp->value);
free(temp);
}
}

free(ht->array);
free(ht);
}
