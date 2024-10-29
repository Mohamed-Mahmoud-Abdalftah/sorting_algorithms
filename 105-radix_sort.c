#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum number in an array.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Sorts the array by the current digit place.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The digit place (1, 10, 100, etc.)
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	/* Store count of occurrences */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so it contains actual position of the digit */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array back to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * Radix sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Apply counting sort for each digit place */
	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_digit(array, size, exp);
}

