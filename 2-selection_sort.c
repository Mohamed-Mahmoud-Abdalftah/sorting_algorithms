#include "sort.h"

/**
  * selection_sort - sorting arrays
  *
  * @array: the unsorted array
  * @size: array size
  * Return: void
  */

void selection_sort(int *array, size_t size)
{
        size_t i, j, min_index;
        int tmp;

        for (i = 0; i < size - 1; i++)
        {
                min_index = i;
                for (j = i + 1; j < size; j++)
                {
                        if (array[min_index] > array[j])
                        {
                                min_index = j;
                        }
                }
                if (min_index != i)
                {
                        tmp = array[i];
                        array[i] = array[min_index];
                        array[min_index] = tmp;
                        print_array(array, size);
                }
        }
}
