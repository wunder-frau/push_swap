#include "push_swap.h"

void print_node(t_node *node)
{
	// printf("{[%d], %d}->\n", node->index, node->value);
	 printf("{[%d], %d}->\n", node->index, node->value);
	//printf("%d->", node->index);
}

void	print_list(t_node *head)
{
	t_node *node;

	node = head;
	while (node != NULL)
	{
		// printf("%d: ", distance(head, node));
		print_node(node);
		node = node->next;
	}
	// printf("NULL\n");
}