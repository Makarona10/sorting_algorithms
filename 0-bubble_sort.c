#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array that will be sorted
 *
 * @size: The size of an array
 *
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int tmp;
	bool flag;

	if (size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		flag = false;
		for (y = 0; y < (size - x - 1); y++)
		{
			if (array[y] > array[y + 1])
			{
				flag = true;
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
			}
		}
		if (flag == false)
			return;
		print_array(array, size);
	}
}
