#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array and prints the array
 * @array: The array of integers
 * @size: The size of the array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, size_t size, int i, int j)
{
	if (i != j)
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * partition - Partitions the array using the Lomuto scheme
 * @array: The array of integers
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, size, i, j);
		}
	}
	swap(array, size, i + 1, high);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies quick sort
 * @array: The array of integers
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quick sort
 * @array: The array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

