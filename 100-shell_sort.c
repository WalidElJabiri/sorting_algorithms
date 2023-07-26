#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * gap - get the max gap
 *
 * @size: the size of the array
 *
 * Return: the max g
 */
size_t gap(size_t size)
{
	size_t g = 1;

	while (g < size)
	{
		g = g * 3 + 1;
	}
	if (g >= size)
	{
		g = (g - 1) / 3;
	}
	return (g);
}

/**
 * shell_sort - sorts an array of integers by shell sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t g = 0, i, j;
	int tmp;

	g = gap(size);
	while (g > 0)
	{
		for (i = g; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= g && array[j - g] > tmp; j -= g)
			{
				array[j] = array[j - g];
			}
			array[j] = tmp;
		}
		print_array(array, size);
		g = (g - 1) / 3;
	}
}
