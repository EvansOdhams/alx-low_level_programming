#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current, *prev;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

current = *head;
prev = NULL;

for (i = 0; i < index; i++)
{
if (current == NULL)
return (-1);
prev = current;
current = current->next;
}

if (current == NULL)
return (-1);

if (prev == NULL)
*head = current->next;
else
prev->next = current->next;

if (current->next != NULL)
current->next->prev = prev;

free(current);

return (1);
}
