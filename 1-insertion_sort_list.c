#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while ((current = current->next) != NULL)
	{
		/*check if current is in right order*/
		if (current->n < current->prev->n)
		{
			temp = current;
			/* detach temp from the list*/
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			previous = current->prev;
			while (previous != NULL && previous->n > temp->n)
				previous = previous->prev;

			if (previous == NULL)
			{
				(*list)->prev = temp;
				temp->next = (*list);
				temp->prev = NULL;
				*list = temp;
			}
			else
			{
				temp->next = previous->next;
				previous->next->prev = temp;

				previous->next = temp;
				temp->prev = previous;
			}
			print_list(*list);
		}
	}
}
