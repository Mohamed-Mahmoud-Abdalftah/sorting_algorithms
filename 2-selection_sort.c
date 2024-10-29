#include "sort.h"

/**
 * locate_min - locating the minimum from the current
 * index in the array
 * @array: the array to be searched
 * @index: starting index of the search
 * @size: the size of the array
 * Return: index of the minimum value found in the array segment
 * from the given index to the end. Returns -1 if the minimum
 * value is already at the given index.
 */

int locate_min(int *array, int index, size_t size)
{
	int minimum, idx_minimum;
	int y;

	minimum = array[index];
	idx_minimum = index;
	for (y = index; y < (int)size; y++)
	{
		if (array[y] < minimum)
		{
			minimum = array[y];
			idx_minimum = y;
		}
	}
	if (idx_minimum == index)
		return (-1);
	return (idx_minimum);
}

/**
 * selection_sort - implementation of selection sort algorthmn
 * @array: array to sort type int
 * @size: the size of the given array
 *
 * Return: void sorted array
 */

void selection_sort(int *array, size_t size)
{
	int y;
	int minimum, tmp;

	for (y = 0; y < (int)size; y++)
	{
		minimum = locate_min(array, y, size);
		if (minimum != -1)
		{
			tmp = array[y];
			array[y] = array[minimum];
			array[minimum] = tmp;
			print_array(array, size);
		}
	}
}
