#include "sort.h"

/**
 * swap - helper function that swaps two array elements
 * @a: pointer to the first array element to swap
 * @b: pointer to the second array element to swap
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * find_min - find the minimum integer in the given array
 * @array: pointer to array to be searched
 * @size: number of elements in the array to be searched
 * @position: starting position in the array to be searched
 *
 * Return: the minimum integer
 */
int find_min(int *array, size_t size, int position)
{
	int min;
	size_t i;

	min = array[position]; /* initialise min as the first integer*/
	for (i = position; i < size; i++)
	{
		/* if we found a lower integer, it will be the new min */
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	(void)array;
	return (min);
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to array to be sorted
 * @size: number of elements in the array to be sorted
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	for (i = 0; i < size - 2; i++)
	{
		min = find_min(array, size, i);
		if (array[i] == min)
		{
			continue;
		}
		for (j = i; j < size; j++)
		{
			/* swap the min to the 1st position then 2nd etc */
			if (array[j] == min)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
}
