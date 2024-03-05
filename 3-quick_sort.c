#include "sort.h"

/**
 * partition - partitions the array around a pivot
 * @array: array to partition
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot after partitioning
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int left = start;
	int right, tmp;

	for (right = start; right < end; right++)
	{
		if (array[right] <= pivot)
		{
			if (left != right)
			{
				tmp = array[right];
				array[right] = array[left];
				array[left] = tmp;
				print_array(array, size);
			}
			left++;
		}
	}

	if (array[left] != array[end])
	{
		tmp = array[left];
		array[left] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (left);
}

/**
 * sort_algorithm - sorts the array using quick sort algorithm
 * @array: array to sort
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
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
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_algorithm(array, 0, size - 1, size);
}
