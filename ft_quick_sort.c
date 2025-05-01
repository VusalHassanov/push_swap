#include "ft_push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	median(int *arr, int size)
{
	int	first;
	int	last;
	int	mid;

	if (size < 3)
		return (arr[0]);
	first = arr[0];
	last = arr[size - 1];
	mid = arr[size / 2];
	if ((first <= last && first >= mid) || (first >= last && first <= mid))
		return (first);
	if ((last >= first && last <= mid) || (last <= first && last >= mid))
		return (last);
	return (mid);
}

int	partition(int *arr, int first, int last)
{
	int	pivot_value;
	int	pivot_index;
	int	i;
	int	j;

	pivot_value = median(&arr[first], last - first + 1);
	pivot_index = first;
	while (arr[pivot_index] != pivot_value)
		pivot_index++;
	swap(&arr[pivot_index], &arr[last]);
	i = first;
	j = first;
	while (j < last)
	{
		j++;
		if (arr[j] < pivot_value)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[last]);
	return (i);
}

void quick_sort(int *arr, int first, int last){
	int pivot_index;

	if(first < last){
		pivot_index = partition(arr, first, last);
		quick_sort(arr, first, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, last);
	}
}
