#include "sort.h"

listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node, *last_node;

    new_node = malloc(sizeof(listint_t));
    if (!new_node) {
        return NULL;
    }

    new_node->n = n;
    new_node->next = NULL;

    if (!*head) {
        *head = new_node;
        new_node->prev = NULL; 
        return new_node;
    }

    last_node = *head;
    while (last_node->next) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->prev = last_node;

    return new_node;
}

int main()
{
    int ar[] = {6, 8, 1, 13, 7, 5};
    print_array(ar, 6);
    selection_sort(ar, 6);
    return 0;
}