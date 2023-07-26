#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 *
 * @ptr1: first ptr
 * @ptr2: second ptr
 */
void swap(int *ptr1, int *ptr2 )
{
        int temp;

        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
}

/**
 * selection_sort - sorting an array of integers by selection
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
    int i, j;
    
    for(i = 0; i < size - 1; i++)
    {
        int min = i;

        for(j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(array + i, array + min);
            print_array(array, size);
        }
    }
}
