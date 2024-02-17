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

    current = *list;
    mover = *list;

    while (current->next != NULL)
    {
        if (current->n > current->next->n)
        {
            mover = current->next;
            current = current->prev;
            while (mover->prev->n > mover->n && mover->prev != NULL)
            {
                mover->prev->next = mover->next;
                mover->next->prev = mover->prev;
                mover->next = mover->prev;
                mover->prev = mover->prev->prev;
                mover->next->prev = mover;
                mover->prev->next = mover;
            }
            print_list(*list);
        }
        current = current->next;
    }
}