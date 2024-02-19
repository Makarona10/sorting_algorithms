#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: The array will be sorted
 *
 * @size: The size of an array
 *
 * Return: void
*/

void swap_elements(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void selection_sort(int *array, size_t size)
{
    size_t i, j;
    int min, minIdx;
    bool flag;

    if (size < 2)
		return;

    for (i = 0; i < size; i++)
    {
        flag = false;
        min = array[i];
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIdx = j;
                flag = true;
            }
        }
        if (flag)
        {
            swap_elements(array, i, minIdx);
            print_array(array, size);
        }    
    }
}