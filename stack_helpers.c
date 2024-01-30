#include "push_swap.h"

static int	min(const int lhs, const int rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

/**
 * Find a node containing closest index.
 */
static t_node	*find_closest(t_node *head, const int index)
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
 * Find element in the stack B which is closest to the stack B front
 * and for which it takes the least actions count to move it to its
 * neighbour in the stack A.
 */
static t_node *find_optimal(t_node *stack_a, t_node *stack_b)
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

/**
 * Move the element to the front by rotating the stack A.
 * Rotates using the `ra` action if the initial element position is closer
 * to front, othervise reverse rotates using `rra`.
 */
void	to_front_a(t_node **stack_a, t_node *node)
{
	int	ra_count;
	int	rra_count;

	ra_count = distance(*stack_a, node);
	rra_count = distance(node, back(*stack_a));
	rra_count++;
	while (ra_count && rra_count)
	{
		if (rra_count < ra_count)
			rra(stack_a);
		else
			ra(stack_a);
		ra_count--;
		rra_count--;
	}
}

/**
 * Move the element to the front by rotating the stack B.
 * Rotates using the `rb` action if the initial element position is closer
 * to front, othervise reverse rotates using `rrb`.
 */
static void	to_front_b(t_node **stack_b, t_node *node)
{
	int	rb_count;
	int	rrb_count;

	rb_count = distance(*stack_b, node);
	rrb_count = distance(node, back(*stack_b));
	rrb_count++;
	while (rb_count && rrb_count)
	{
		if (rrb_count < rb_count)
			rrb(stack_b);
		else
			rb(stack_b);
		rb_count--;
		rrb_count--;
	}
}

static void	to_front_ab(t_node **stack_a, t_node **stack_b, t_node *node)
{
	t_node *closest;
	int	ra_count;
	int	rra_count;
	int	rb_count;
	int	rrb_count;

	closest = find_closest(*stack_a, node->index);
	ra_count = distance(*stack_a, closest);
	rra_count = distance(closest, back(*stack_a));
	rra_count++;
	rb_count = distance(*stack_b, node);
	rrb_count = distance(node, back(*stack_b));
	rrb_count++;
	if ((ra_count < rra_count && rb_count > rrb_count) ||
			(ra_count > rra_count && rb_count < rrb_count))
		return ;
	while (ra_count && rra_count && rb_count && rrb_count)
	{
		if (rra_count < ra_count && rrb_count < rb_count)
			rrr(stack_a, stack_b);
		else
			rr(stack_a, stack_b);
		ra_count--;
		rb_count--;
		rra_count--;
		rrb_count--;
	}
}

/**
 * Move `count` lowest values from stack A to stack B.
 * If the index is greater than `stack_init`, indicating that it is on the left
 * side of a stack, the loop rotates `ra`; otherwise, it pushes to stack B using `pb`.
 * This reverts the elements order in the stack B due to usage of `pb`.
 */
void	move_n(t_node **stack_a, t_node **stack_b, const int count)
{
	int	size_init;
	int	n;
	int	i;

	size_init = len(*stack_a);
	n = 0;
	i = 0;
	while (i < size_init && n < size_init / 2)
	{
		if ((*stack_a)->index > size_init / 2)
		{
			ra(stack_a);
		}
		else
		{
			pb(stack_b, stack_a);
			n++;
		}
		i++;
	}
	while (n < count)
	{
		pb(stack_b, stack_a);
		n++;
	}
}

/**
*  The micro_sort function is designed for sorting a subset of a stack
*  consisting of three elements. It employs basic stack manipulation
*  operations (ra, sa, and rra) to achieve a specific sorting pattern.
*  This function assumes that the stack has at least three elements.
*/
void	micro_sort(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value && (*stack)->value > back(*stack)->value)
		ra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
	if ((*stack)->next->value > back(*stack)->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
//	swap_indices(*stack, (*stack)->next);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	t_node *optimal;

	optimal = find_optimal(*stack_a, *stack_b);
	to_front_ab(stack_a, stack_b, optimal);
	to_front_b(stack_b, optimal);
	to_front_a(stack_a, find_closest(*stack_a, optimal->index));
	pa(stack_a, stack_b);
}