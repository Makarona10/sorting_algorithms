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
    listint_t *head;
    add_nodeint(&head, 9);
    add_nodeint(&head, 14);
    add_nodeint(&head, 12);
    add_nodeint(&head, -1);
    add_nodeint(&head, 3);
    add_nodeint(&head, 2);
    insertion_sort_list(&head);
    return 0;
}