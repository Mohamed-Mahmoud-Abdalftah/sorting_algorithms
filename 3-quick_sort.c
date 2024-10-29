#include "sort.h"

/**
  * partition - to partition the array
  *
  * @arr: array to be partitioned
  * @low: start index
  * @high: end index
  * @arr_size: main array size
  * Return: return new pivot
  */

int partition(int *arr, int low, int high, int arr_size)
{
	int tmp, j;

	int pivot = arr[high];
	int i  = low - 1;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, arr_size);
		}
	}
	tmp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = tmp;
	print_array(arr, arr_size);
	return (i + 1);
}

/**
  * quick_sort_recursion - recursive calls to sort
  *
  * @arr: array to be sorted
  * @low: start index
  * @high: end index
  * @size: main array size
  * Return: void
  */

void quick_sort_recursion(int *arr, int low, int high, int size)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high, size);

		quick_sort_recursion(arr, low, pivot - 1, size);
		quick_sort_recursion(arr, pivot + 1, high, size);
	}
}

/**
  * quick_sort - Entry point
  *
  * @array: unsorted array
  * @size: array lenght
  * Return: void
  */

void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
