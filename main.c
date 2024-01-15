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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	stack_len;

	if (argc < 2)
		return (0);
	stack_len = argc - 2;
	stack_b = fill_lst(argc, argv);
	stack_a = fill_lst(argc, argv);
	/* check stack_a output */
	// print_lst(stack_a);
	// printf("\n");
	int j = len(stack_a);
	printf("%d", j);
	printf("\n");
	print_lst(stack_a);
	printf("\n");
	/* check quicksort output */
	// printf("output: ");
	// printf("\n");
	// quicksort(stack_a, 0, stack_len);
	// print_lst(stack_a);
	// printf("\n");

	/* check micro_sort output */
	// micro_sort(&stack_a);
	// print_lst(stack_a);
	// printf("\n");

	/* -- get_cost -- */
	quicksort(stack_b, 0, stack_len);
	//get_cost(stack_a, stack_b);
	do_cheapest_move(&stack_a, &stack_b);
	print_lst(stack_a);
		printf("\n");
		print_lst(stack_b);
	/* ---- */
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}