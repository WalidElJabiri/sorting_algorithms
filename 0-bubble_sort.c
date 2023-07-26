#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"
/**
 * swap - swap two integers
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
 * bubble_sort - sort integers
 *
 * @array: the array to be stored
 * @size: the size of the arr
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] >  array[j + 1])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
			}
		}
	}
}
