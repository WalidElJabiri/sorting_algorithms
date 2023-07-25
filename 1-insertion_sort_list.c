#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorting a linked list
 *
 * @list: ptr to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (list == NULL || *list == NULL)
		return;

	a = (*list)->next;
	while (a != NULL)
	{
		b = a->next;
		while (a->prev != NULL && a->prev->n > a->n)
		{
			a->prev->next = a->next;
			if (a->next)
			{
				a->next->prev = a->prev;
			}
			a->next = a->prev;
			a->prev = a->next->prev;
			a->next->prev = a;

			if (!a->prev)
			{
				*list = a;
			}
			else
			{
				a->prev->next = a;
			}
			print_list(*list);
		}
		a = b;
	}
}
