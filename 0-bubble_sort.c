#include "sort.h"

/**
 * bubble_sort - Sorts array of ints in ascending order using Bubble Sort
 * @array: array that will be sorted
 * @size: size of the array to be sorted
 *
 * Description: Prints the array after each swap.
 **/

void bubble_sort(int *array, size_t size)
{
	int n;
	size_t x, y;

	if (size < 2)
		return;
	for (y = 0; y < size - 1; y++)
	{
		for (x = 0; x < size - y - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				n = array[x];
				array[x] = array[x + 1];
				array[x + 1] = n;
				print_array(array, size);
			}
		}
	}
}
