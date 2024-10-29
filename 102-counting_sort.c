#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = 0, *count = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Allocate memory for the count array and initialize to 0 */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the count array to contain positions */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* Build the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	/* Copy the sorted elements back into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

