#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: A list to be sorted
 *
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *mover;

    for (current = *list; current; current = current->next)
    {
        while (current->n > current->next->n && current->next)
        {
            mover = current->next;
			current->next = mover->next;
			mover->prev = current->prev;

			if (current->prev)
				current->prev->next = mover;

			if (mover->next)
				mover->next->prev = current;

			current->prev = mover;
			mover->next = current;

			if (mover->prev)
				current = mover->prev;
			else
				*list = mover;
            print_list(*list);
        }
    }
}
