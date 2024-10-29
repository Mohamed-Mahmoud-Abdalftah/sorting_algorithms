#include "sort.h"

/**
 * shell_sort - sort an array using shell_sort algorithm
 * @array: an array to be sorted
 * @size: the size of the array
 * Return: NULL
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int g = 1, y, x;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;

	while (g > 0)
	{
		for (y = g; y < size; y++)
		{
			temp = array[y];
			x = y;
			while (x >= g && array[x - g] > temp)
			{
				array[x] = array[x - g];
				x -= g;
			}
			array[x] = temp;
		}
		print_array(array, size);
		g /= 3;
	}
}
