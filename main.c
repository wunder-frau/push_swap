#include "push_swap.h"

static void print_node(t_node *node, int pos)
{
	printf("{(%d),[%d], %d, %d, %d}->\n", pos, node->index, node->cost_b, node->cost_a, node->value);
	//printf("(%d)", node->value);
	//printf("\n");
}

static void print_list(t_node *head)
{
	t_node *node;

	node = head;
	while (node != NULL)
	{
		print_node(node, distance(head, node));
		node = node->next;
	}
	printf("NULL\n");
}

/*static void	push_swap(t_node **stack_a, t_node **stack_b, int stack_len)
{
	if (stack_len == 2 && !is_sorted(*stack_a))
		sa(*stack_a);
	else if (stack_len == 3)
		micro_sort(stack_a);
	else if (stack_len > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}*/

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
	// int	stack_len;

	if (argc < 2)
		return (0);
	stack_a = fill_list(argc, argv);
	stack_b = NULL;
	// stack_len = len(stack_a);

	/* -- testing sort -- */
	// push_swap(&stack_a, &stack_b, stack_len);
	print_list(stack_a);
	move_n(&stack_a, &stack_b, len(stack_a)); // - 3);

	printf("A:\n");
	print_list(stack_a);
	print_list(stack_a);
	printf("\n");

	printf("B:\n");
	print_list(stack_b);
	printf("\n");

	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}