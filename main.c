#include "push_swap.h"

void printNode(t_node *node)
{
	// printf("(%d,%d)->", node->index, node->value);
	printf("(%d)", node->value);
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

int main()
{
	t_node *head = ft_newnode(3);
	ft_pushback(head, 1);
	ft_pushback(head, 4);
	ft_pushback(head, 0);
	ft_pushback(head, 2);
	ft_pushback(head, 5);

	printf("input: ");
	printList(head);
	printf("\n");

	printf("output: ");
	ft_quicksort(head, 0, 5);
	printList(head);
	printf("\n");
	return 0;
}