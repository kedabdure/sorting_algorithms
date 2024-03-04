#include "sort.h"

/**
 * 
 * 
 * 
 * 
*/

int partition(int *array, int start, int end, size_t size)
{
    int tmp;
    int piv = array[start];
    int left = start, right = end;

    while (left < right)
    {
        while (array[left] <= piv)
            left++;

        while (array[right] > piv)
            right--;

        if (left < right)
        {
            tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
            print_array(array, size);
        }

    }

    tmp = array[start];
    array[start] = array[right];
    array[right] = tmp;
    print_array(array, size);

    return right;
}

/**
 * 
 * 
 * 
 * 
*/
void sort_algorithm(int *array, int start, int end, size_t size)
{
    size_t loc;
    if (start < end)
    {
        loc = partition(array, start, end, size);
        sort_algorithm(array, start, loc - 1, size);
        sort_algorithm(array, loc + 1, end, size);
    }
}

/**
 * 
 * 
 * 
 * 
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;
    sort_algorithm(array, 0, size - 1, size);
}
