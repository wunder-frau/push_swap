#include "push_swap.h"

static int	min(const int lhs, const int rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

/**
 * Count moves to get an element `node` to the top its stack
 */
static int count_moves(t_node *head, t_node *node)
{
	int	lhs_count;
	int	rhs_count;

	lhs_count = distance(head, node);
	rhs_count = distance(node, back(head));
	rhs_count++;
	return (min(lhs_count, rhs_count));
}

/**
 * Find a node containing closest index.
 */
t_node	*find_closest(t_node *head, const int index)
{
	int	closest_ind;
	t_node	*node;

	closest_ind = INT_MAX;
	node = head;
	while (node)
	{
		if (index < node->index && node->index < closest_ind)
			closest_ind = node->index;
		node = node->next;
	}
	if (closest_ind != INT_MAX)
		return (at_ind(head, closest_ind));
	return (find_min(head));
}

/**
 * Find element in the stack B which is closest to the stack B front
 * and for which it takes the least actions count to move it to its
 * neighbour in the stack A.
 */
t_node  *find_optimal(t_node *stack_a, t_node *stack_b)
{
	t_node *node;
	t_node *optimal;
	int min_delta;
	int delta;
	t_node *closest;

	min_delta = INT_MAX;
	node = stack_b;
	optimal = stack_b;
	while (node)
	{
		closest = find_closest(stack_a, node->index);
		delta = count_moves(stack_b, node) + count_moves(stack_a, closest);
		if (delta < min_delta)
		{
			min_delta = delta;
			optimal = node;
		}
		node = node->next;
	}
	return (optimal);
}