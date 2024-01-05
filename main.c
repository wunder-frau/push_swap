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
	// ft_insert(head, ft_newnode(1));
	// ft_insert(head->next, ft_newnode(4));
	// ft_insert(head->next->next, ft_newnode(0));
	// ft_insert(head->next->next->next, ft_newnode(2));
	// ft_insert(head->next->next->next->next, ft_newnode(5));
	// printList(head);

	ft_pushback(head, 1);
	ft_pushback(head, 4);
	ft_pushback(head, 0);
	ft_pushback(head, 2);
	ft_pushback(head, 5);

	printf("input: ");
	printList(head);
	printf("\n");

	printf("output: ");
	ft_quicksort(head, 0, 3);
	printList(head);
	printf("\n");
	return 0;
}