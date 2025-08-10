#include "sort.h"

/**
 * insertion_sort_list - insertion sort
 * @list: Double ptr to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && current->n < prev->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);

			prev = current->prev;
		}
		current = current->next;
	}
}
