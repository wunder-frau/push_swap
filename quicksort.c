#include "push_swap.h"

/**
 * Lomuto partition scheme.
 * Sort (a portion of an) list's indices preserving nodes positions and their values.
 */
int	partition(t_node *head, int start, int end)
{
	int pivot;
	int i;
	int j;

	pivot = at_ind(head, end)->value;
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (at_ind(head, j)->value < pivot)
		{
			i++;
			swap_indices(at_ind(head, i), at_ind(head, j));
		}
		j++;
	}
	swap_indices(at_ind(head, i + 1), at_ind(head, end));
	return (i + 1);
}

/**
 * Quicksort indices but preserve nodes positisions and their values.
 */
void	quicksort(t_node *head, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(head, start, end);
		quicksort(head, start, pivot - 1);
		quicksort(head, pivot + 1, end);
	}
}