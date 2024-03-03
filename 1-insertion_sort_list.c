#include "sort.h"

/**
 * 
 * 
 * 
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *temp;
    int num;

    temp = list;

    while (temp != NULL)
    {
        num = temp->next->n;
        if (temp->n > temp->next->n)
        {
            temp->next->n = temp->n;
            temp = temp->prev;
        }
        temp ->n = num;
    }
}