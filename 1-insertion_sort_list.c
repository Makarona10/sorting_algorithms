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
    listint_t *iter, *key, *mover;

    iter = *list;
    mover = *list;

    while (iter->next != NULL)
    {
        while (mover->prev->n > iter->n || mover->prev != NULL)
        {
            mover->prev->next = mover->next;
            mover->next = mover->prev;
            mover->prev = mover->prev->prev;
            mover->next->prev = mover;
            print_list(*list);
        }
        iter = iter->next;
        mover = iter;
    }
}