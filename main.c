#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	stack_len;

	if (argc <= 2)
		return (0);
	stack_a = fill_list(argc, argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	quicksort_indices(stack_a, 0, stack_len - 1);
	move_n(&stack_a, &stack_b, stack_len - 3);
	micro_sort(&stack_a);
	while(stack_b)
		push_swap(&stack_a, &stack_b);
	if (find_min(stack_a) != stack_a)
		to_front_a(&stack_a, find_min(stack_a));
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}