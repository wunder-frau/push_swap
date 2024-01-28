#include "push_swap.h"

static int	min(const int lhs, const int rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

static int	nb_abs(const int value)
{
	if (value < 0)
		return (-1 * value);
	return (value);
}

/**
 * Find a node containing higher index.
 */
static t_node	*find_closest(t_node *head, int index)
{
	int	closest;
	t_node	*node;

	closest = INT_MAX;
	node = head;
	while (node)
	{
		if (index < node->index && node->index < closest)
			closest = node->index;
		node = node->next;
	}
	if (closest != INT_MAX)
		return (at_ind(head, closest));
	else
		return (find_max(head));
}

/**
 * Count moves to get an element `node` to the top its stack
 */
static int count_moves(t_node *head, t_node *node)
{
	int	rback_count;
	int	rfront_count;
	int	moves_count;

	rback_count = distance(head, node);
	rfront_count = distance(node, back(head));
	rfront_count++;
	moves_count = min(rback_count, rfront_count);
	return (moves_count);
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
	int moves_count;
	int min_moves_count;
	t_node *closest;

	min_moves_count = INT_MAX;
	node = stack_b;
	optimal = stack_b;
	while (node)
	{
		closest = find_closest(stack_a, node->index);
		moves_count = count_moves(stack_b, node);
		// moves_count += count_moves(stack_a, closest);
		moves_count += nb_abs(closest->index - node->index);
		if (moves_count < min_moves_count)
		{
			min_moves_count = moves_count;
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
static void	to_front_a(t_node **stack_a, t_node *node)
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
	if ((ra_count < rra_count && rb_count > rrb_count) || // elems are on the different parts
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
 * This reverts the elements order in the stack B due to usage of `pb`.
 */
void	move_nmin(t_node **stack_a, t_node **stack_b, int count)
{
	int	n;

	n = count;
	while (n > 0 && *stack_a)
	{
		if ((*stack_a)->index >= count)
		{
			ra(stack_a);
			continue;
		}
		pb(stack_b, stack_a);
		n--;
	}
}

/**
*  The micro_sort function is designed for sorting a subset of a stack
*  consisting of three elements. It employs basic stack manipulation
*  operations (ra, sa, and rra) to achieve a specific sorting pattern.
*  This function assumes that the stack has at least three elements.
   Example Usage:
   - Before calling micro_sort: {(0),[0],3}->{(1),[1],1}->{(2),[2],2}->NULL
   - After calling micro_sort:  {(0),[0],3}->{(1),[1],2}->{(2),[2],1}->NULL
*/
void	micro_sort(t_node **stack)
{
	if((*stack)->value > (*stack)->next->value && (*stack)->value > back(*stack)->value)
		ra(stack);
	if((*stack)->value > (*stack)->next->value)
		sa(*stack);
	if((*stack)->next->value > back(*stack)->value)
		rra(stack);
	if((*stack)->value > (*stack)->next->value)
		sa(*stack);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	t_node *optimal;

	optimal = find_optimal(*stack_a, *stack_b);
	to_front_ab(stack_a, stack_b, optimal);
	to_front_b(stack_b, optimal);
	to_front_a(stack_a, find_closest(*stack_a, optimal->index));
	pa(stack_a, stack_b);
	if (find_min(*stack_a) != *stack_a)
		to_front_a(stack_a, find_min(*stack_a));
}