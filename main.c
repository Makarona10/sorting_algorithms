#include "sort.h"

listint_t *add_nodeint_end(listint_t **head, const int n) {
    listint_t *new_node, *last_node;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
    } else {

        last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }

        new_node->prev = last_node;
        last_node->next = new_node;
    }

    return new_node;
}

int main()
{
    listint_t *head;
    add_nodeint_end(&head, 12);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 7);
    add_nodeint_end(&head, 14);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 78);
    print_list(head);
    insertion_sort_list(&head);
    return 0;
}