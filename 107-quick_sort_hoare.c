#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two integers in an array
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Partition the array using the Hoare partition scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size); /* Print the array after each swap */
	}
}

/**
 * quick_sort_recursive - Recursively apply quicksort
 * @array: The array to sort
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers using the
 * Hoare partition scheme
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

