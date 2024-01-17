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
 * partition - divides array into two partitions
 * @array: pointer to array to be sorted
 * @lo: integer on the left end
 * @hi: integer on the right end
 * @size: number of elements in the array to be sorted
 *
 * Return: the pivot index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot;
	int i, j;

	/* choose the last element as the pivot */
	pivot = array[hi];
	/* temporary pivot index (TPI) */
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		/* if current element is <= pivot */
		if (array[j] <= pivot)
		{
			/* move the TPI forward */
			i++;
			/* swap the current element with element at TPI */
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	/* move the pivot element to the correct pivot position */
	i++;
	swap(&array[i], &array[hi]);
	if (array[i] != array[hi])
		print_array(array, size);
	return (i); /* the pivot index*/
}

/**
 * quick_sorting - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: pointer to array to be sorted
 * @lo: integer on the left end
 * @hi: integer on the right end
 * @size: number of elements in the array to be sorted
 *
 * Return: void
 */
void quick_sorting(int *array, int lo, int hi, size_t size)
{
	int p;
	
	/* ensures indices are in correct order */
	if (lo >= hi || lo < 0)
	{
		return;
	}
	/* partition array and get the pivot index */
	p = partition(array, lo, hi, size);
	/* sort the two partitions */
	quick_sorting(array, lo, p - 1, size);
	quick_sorting(array, p + 1, hi, size);
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: pointer to array to be sorted
 * @size: number of elements in the array to be sorted
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sorting(array, 0, size - 1, size);
}
