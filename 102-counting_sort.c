#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 **/
void counting_sort(int *array, size_t size)
{
    int *count_array, *new_array, max_value, i;

    if (size < 2)
        return;

    max_value = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    count_array = malloc(sizeof(int) * (max_value + 1));
    if (count_array == NULL)
        return;

    for (i = 0; i <= max_value; i++)
        count_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_array[array[i]]++;

    printf("0");
    for (i = 1; i <= max_value; i++)
    {
        count_array[i] += count_array[i - 1];
        printf(", %d", count_array[i]);
    }
    printf("\n");

    new_array = malloc(sizeof(int) * size);
    if (new_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = size - 1; i >= 0; i--)
    {
        new_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = new_array[i];

    free(count_array);
    free(new_array);
}
