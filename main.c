#include "push_swap.h"

void printNode(t_node *node, int pos)
{
	printf("{(%d),[%d], %d, %d, %d}->\n", pos, node->index, node->cost_b, node->cost_a, node->value);
	//printf("(%d)", node->value);
	//printf("\n");
}

void printList(t_node *head)
{
	t_node *node;

	node = head;
	while (node != NULL)
	{
		printNode(node, ft_distance(head, node));
		node = node->next;
	}
	printf("NULL");
}

// int main()
// {
// 	t_node *head = ft_newnode(3);
// 	ft_pushback(head, 1);
// 	ft_pushback(head, 4);
// 	ft_pushback(head, 0);
// 	ft_pushback(head, 2);
// 	ft_pushback(head, 5);

// 	printf("input: ");
// 	printList(head);
// 	printf("\n");

// 	printf("output: ");
// 	ft_quicksort(head, 0, 6);
// 	//ft_revrotate(&head);
// 	printList(head);
// 	//ra(&head);
// 	printf("\n");
// 	return 0;
// }

static void print_stack(t_node *stack) {
    while (stack != NULL) {
		printf("num: %d\n", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	stack_len;

	if (argc < 2)
		return (0);
	stack_len = argc - 2;
	stack_b = ft_fillstack(argc, argv);
	stack_a = ft_fillstack(argc, argv);
	/* check stack_a output */
//	printList(stack_a);
	//printf("\n");
	/* check quicksort output */
	// printf("output: ");
	// printf("\n");
	// ft_quicksort(stack_a, 0, stack_len);
	// printList(stack_a);
	// printf("\n");

	/* check micro_sort output */
	// micro_sort(&stack_a);
	// printList(stack_a);
	// printf("\n");

	/* -- get_cost -- */
	get_cost(&stack_a, &stack_b);
	printList(stack_a);
	/* ---- */
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}