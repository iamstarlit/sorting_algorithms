#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithms.
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - 1) - i; j++)
		{
			/**
			 * If the current element is greater than
			 * the next element, swap them
			 */
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1], sizeof(int));
				print_array(array, size);
			}
		}
	}
}
