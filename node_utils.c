#include "push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int tmp;

	if (a == NULL || b == NULL)
		return;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	swap_indices(t_node *a, t_node *b)
{
	int tmp;

	if (a == NULL || b == NULL)
		return;
	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

/**
 * Generates self-existing new node, i.e. head node.
 */
t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}
