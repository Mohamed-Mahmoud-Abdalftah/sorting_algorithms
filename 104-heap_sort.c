#include "sort.h"

/**
* stupify - recurrssive heapfiy function
* @array: Array to sort
* @heap: size of heap data
* @i: index
* @size: size of array
*/

void stupify(int *array, int heap, int i, int size)
{
	int large = i, l = 2 * i + 1, r = 2 * i + 2, t;

	if (l < heap && array[l] > array[large])
		large = l;
	if (r < heap && array[r] > array[large])
		large = r;
	if (large != i)
	{
		t = array[i], array[i] = array[large], array[large] = t;
		print_array(array, size);
		stupify(array, heap, large, size);
	}
}

/**
* heap_sort - Sorts array with heap sort algo
* @array: array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		stupify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		stupify(array, i, 0, size);
	}

}
