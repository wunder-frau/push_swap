#include "push_swap.h"

static void print_node(t_node *node, int pos)
{
	printf("{(%d),[%d], %d, %d, %d}->\n", pos, node->index, node->cost_b, node->cost_a, node->value);
	//printf("(%d)", node->value);
	//printf("\n");
}

static void print_lst(t_node *head)
{
	t_node *node;

	node = head;
	while (node != NULL)
	{
		print_node(node, distance(head, node));
		node = node->next;
	}
	printf("NULL");
}

static void	push_swap(t_node **stack_a, t_node **stack_b, int stack_len)
{
	if (stack_len == 2 && !is_sorted(*stack_a))
		sa(*stack_a);
	else if (stack_len == 3)
		micro_sort(stack_a);
	else if (stack_len > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	stack_len;
	// int	stack_len_a;
	// int	stack_len_b;

	if (argc < 2)
		return (0);
	// stack_len = argc - 2;
	stack_a = fill_lst(argc, argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	/* check stack_a output */
	// print_lst(stack_a);
	// printf("--->stack a\n");
	// print_lst(stack_b);
	// printf("--->stack b\n");
	//int j = len(stack_a);
	// printf("%d", j);
	//printf("\n");
//	print_lst(stack_a);
	// printf("\n");
	// push_all_to_b(&stack_a, &stack_b);
	// print_lst(stack_a);
	// printf("\n");
	// printf("--->remained in A\n");
	// printf("\n");
	// print_lst(stack_b);
	// printf("\n");
	// printf("--->pushed in B\n");
	// printf("\n");
	// printf("\n");


	/* check quicksort output */
	// printf("output: ");
	// printf("\n");
	// stack_len_a = len(stack_a);
	// quicksort(stack_a, 0, stack_len_a);
	// print_lst(stack_a);
	// printf("\n");
	// stack_len_b = len(stack_b);
	// quicksort(stack_b, 0, stack_len_b);
	// print_lst(stack_b);


	/* -- testing sort -- */
	push_swap(&stack_a, &stack_b, stack_len);
	printf("--->sort\n");
	print_lst(stack_a);
	printf("\n");
	printf("\n");
	print_lst(stack_b);
	/* -- testing sort -- */


	/* check micro_sort output */
	// micro_sort(&stack_a);
	// print_lst(stack_a);
	// printf("\n");

	/* -- get_cost -- */
	// quicksort(stack_b, 0, stack_len);
	// get_cost(stack_a, stack_b);
	// do_cheapest_move(&stack_a, &stack_b);
	// print_lst(stack_a);
	// 	printf("\n");
	// 			print_lst(stack_b);
		//print_lst(stack_b);
	/* ---- */
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}