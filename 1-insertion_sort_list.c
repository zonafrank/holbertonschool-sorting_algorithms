#include "sort.h"

/**
 * sortedInsert - inserts a node in sorted order into a linked list
 * @list: linked list to insert the node into
 * @listNode: node to insert into tht list
 * Return: void
 */
void sortedInsert(listint_t **list, listint_t *listNode)
{
	listint_t *current;

	if (*list == NULL)
	{
		*list = listNode;
	}
	else if ((*list)->n >= listNode->n)
	{
		listNode->next = *list;
		listNode->next->prev = listNode;
		*list = listNode;
	}
	else
	{
		current = *list;
		while (current->next != NULL &&
			   current->next->n < listNode->n)
		{
			current = current->next;
		}

		listNode->next = current->next;
		if (current->next != NULL)
		{
			listNode->next->prev = listNode;
		}
		current->next = listNode;
		listNode->prev = current;
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: ointer to the head of theh list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->prev = current->next = NULL;
		sortedInsert(&sorted, current);
		current = next;
	}

	*list = sorted;
}
