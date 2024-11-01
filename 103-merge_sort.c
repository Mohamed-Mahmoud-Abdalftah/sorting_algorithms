#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (x = front, y = mid; x < mid && y < back; z++)
		buff[z] = (subarr[x] < subarr[y]) ? subarr[x++] : subarr[j++];
	for (; x < mid; x++)
		buff[z++] = subarr[x];
	for (; y < back; y++)
		buff[z++] = subarr[y];
	for (x = front, z = 0; x < back; x++)
		subarr[x] = buff[z++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implement the merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t m;

	if (back - front > 1)
	{
		m = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, m);
		merge_sort_recursive(subarr, buff, m, back);
		merge_subarr(subarr, buff, front, m, back);
	}
}

/**
 * merge_sort - sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	merge_sort_recursive(array, b, 0, size);

	free(b);
}
