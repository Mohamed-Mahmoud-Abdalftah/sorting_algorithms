#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point for the quick sort program
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    print_array(array, n); /* Print the original array */
    printf("\n");

    quick_sort_hoare(array, n); /* Sort the array using quick sort */

    printf("Sorted array:\n");
    print_array(array, n); /* Print the sorted array */
    return (0);
}
