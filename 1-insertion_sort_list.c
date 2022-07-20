#include "sort.h"
/**
 * insertion_sort_list - a funcrtion that sorts doubly linked list
 * @list: address to the head of the list
 *
 * Return: NULL
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	if(list == NULL || *list == NULL)
		return;
	temp = (*list)->next;
	while(temp)
	{
		while(temp->prev && (temp->n < temp->prev->n))
		{
			temp->prev->next = temp->next;
			if(temp->next)
				temp->next->prev =temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if(temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = temp->next;
	}
}
