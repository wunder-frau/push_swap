#include "push_swap.h"

void printNode(t_node *node)
{
	printf("(%d,%d)->", node->index, node->value);
	// printf("(%d)", node->value);
}

void printList(t_node *node)
{
	while (node != NULL)
	{
		printNode(node);
		node = node->next;
	}
	// printf("NULL");
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

int	main(int argc, char **argv)
{
	t_node	stack_a;
	int	stack_b;

	int	stack_len;
	if (argc < 2)
		return (NULL);
	//TO DO stack int function
	//stack_a = ;
	stack_b = 0;
	//TO DO free_stack function
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}