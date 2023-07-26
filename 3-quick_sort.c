#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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
 * partition - select a pivot in the array
 *
 * @array: the array to be sorted
 * @low: the low index of the partition
 * @high: the high index of the partition
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array + i,array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		swap(array + i,array + hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * r_quick_sort - partition the array, then sort
 *
 * @array: the array to be sorted
 * @low: the low index of the partition
 * @high: the high index of the partition
 * @size: size of the array
 */
void r_quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		r_quick_sort(array, low, pivot - 1, size);
		r_quick_sort(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - sort an array of integers by quicksort
 *
 * @array: the array to be surted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t high = (size - 1);

	if (!array || size < 2)
		return;

	r_quick_sort(array, low, high, size);
}
