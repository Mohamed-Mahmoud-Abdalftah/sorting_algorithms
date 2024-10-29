#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers in an array
 * @array: array of integers
 * @a: first integer index
 * @b: second integer index
 */
void swap(int *array, int a, int b)
{
	int temp;

	if (array[a] > array[b])
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;

		printf("Swap: %d <-> %d\n", array[a], array[b]);
	}
}

/**
 * bitonic_merge - merges a bitonic sequence
 * @array: array of integers
 * @low: starting index
 * @cnt: number of elements to consider
 * @dir: direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int low, int cnt, int dir)
{
	int k, i;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = low; i < low + k; i++)
		{
			swap(array, i, i + k);
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - recursively sorts a bitonic sequence
 * @array: array of integers
 * @low: starting index
 * @cnt: number of elements to consider
 * @dir: direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		bitonic_sort_recursive(array, low, k, 1); /* Sort in ascending order */
		bitonic_sort_recursive(array, low + k, k, 0); /* Sort in descending order */
		bitonic_merge(array, low, cnt, dir);
	}
}

/**
 * bitonic_sort - sorts an array of integers using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

