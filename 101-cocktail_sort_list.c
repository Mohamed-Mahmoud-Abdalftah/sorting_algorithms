#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    else
        *list = right;

    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;
    right->next = left;
    left->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker Sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start, *end, *current;

    if (!list || !*list)
        return;

    start = *list;
    end = NULL;

    do {
        swapped = 0;
        current = start;

        while (current->next != end)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->next;
        }
        end = current;

        if (!swapped)
            break;

        swapped = 0;
        current = end->prev;

        while (current != start->prev)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->prev;
        }
        start = current->next;

    } while (swapped);
}

