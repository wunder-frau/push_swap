#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int	stack_len;
	// if (argc <= 2)
	// 	return (0);
	// if (argc == 1 || (argc == 2 && !argv[1][0]))
	// 	return (0);
	if (!validate_input(argv))
		handle_error(NULL, NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = fill_split(argc, args);
	}
	else
		stack_a = fill_list(argc, argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	//print_list(stack_a);
	quicksort_indices(stack_a, 0, stack_len - 1);
	move_n(&stack_a, &stack_b, stack_len - 3);
	micro_sort(&stack_a);
	while(stack_b)
		push_swap(&stack_a, &stack_b);
	if (find_min(stack_a) != stack_a)
		to_front_a(&stack_a, find_min(stack_a));
	print_list(stack_a);
	// else
	// 	free_list(&stack_a);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}