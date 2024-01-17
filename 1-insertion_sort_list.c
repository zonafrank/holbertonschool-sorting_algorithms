#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *temp;

	if (list == NULL)
		return;

	current = (*list);

	while ((current = current->next) != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			previous = temp->prev;

			temp->prev = previous->prev;
			previous->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = previous;

			if (previous->prev != NULL)
				previous->prev->next = temp;
			else
				*list = temp;

			temp->next = previous;
			previous->prev = temp;

			print_list(*list);
		}
	}
}
