#include "push_swap.h"

void	ft_swap(t_node *a, t_node *b)
{
	int tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

/**
 * Inserts node at any position after prev node.
 * Iteration is required to update indices.
 */
t_node	*ft_newnode(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->value = value;
	new->next = NULL;
	return (new);
}

/**
 * Inserts node at any position after prev node.
 * Iteration is used to update indices.
 */
void	ft_insert(t_node *prev, t_node *curr)
{
	t_node	*tail;
	if (prev == NULL || curr == NULL)
		return;
	curr->next = prev->next;
	prev->next = curr;
	curr->index = prev->index;
	tail = prev->next;
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

/**
 * Returns node at posision.
 */
t_node	*ft_at(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index)
	{
		node = node->next;
	}
	return (node);
}