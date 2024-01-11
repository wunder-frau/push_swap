#include "push_swap.h"

int	ft_partition(t_node *head, int start, int end)
{
	int pivot;
	int i;
	int j;

	pivot = ft_atind(head, end)->value;
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (ft_atind(head, j)->value < pivot)
		{
			i++;
			ft_swap_indices(ft_atind(head, i), ft_atind(head, j));
		}
		j++;
	}
	ft_swap_indices(ft_atind(head, i + 1), ft_atind(head, end));
	return (i + 1);
}

/**
 * Initializes arrays for elements less and greater than the pivot, 
 * then recursively sorts subarrays.
 */
void	ft_quicksort(t_node *head, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = ft_partition(head, start, end);
		ft_quicksort(head, start, pivot - 1);
		ft_quicksort(head, pivot + 1, end);
	}
}