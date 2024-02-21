#include "sort.h"

/**
 * partitioner: splits the array into 2 arrays
 *
 * @array: The array will be splitted
 *
 * @low: The lower bound of the array
 *
 * @high: The higher bound of the array
 *
 * @size: Size of the array
 *
 * Return: The index of pivot
*/

size_t partitioner(int *array, size_t low, size_t high, size_t size)
{
	size_t x, y, pivot;

	pivot = high;
	x = low;

	for (y = x; y < high; y++)
	{
		if ((array)[y] <= (array)[pivot])
		{
			if (x != y)
			{
				swap_elements(array, x, y);
				print_array(array, size);
			}
			x += 1;
		}
	}
	if (x != y)
	{
		swap_elements(array, x, y);
		print_array(array, size);
	}
	return (x);
}

/**
 * sort_it - sorts an array in ascending order
 *
 * @low: The lower bound of the partitioned array
 *
 * @high: The higher bound of the partitioned array
 *
 * @size: The size of the partitioned array
 *
 * Return: void
 */

void sort_it(int *array, size_t low, size_t high, size_t size)
{
    size_t x;

	if (low < high && *array)
	{
		x = partitioner(array, low, high, size);

		if (x - low > 1)
			sort_it(array, low, x - 1, size);

		if (high - x > 1)
			sort_it(array, x + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array will be sorted
 *
 * @size: The size of an array
 *
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
    if (size < 2 || !array)
        return;

    sort_it(array, 0, size - 1, size);
}
