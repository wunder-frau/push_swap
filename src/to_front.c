#include "push_swap.h"

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
void	to_front_b(t_node **stack_b, t_node *node)
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

void	to_front_ab(t_node **stack_a, t_node **stack_b, t_node *node)
{
	t_node *closest;
	int	ra_count;
	int	rra_count;
	int	rb_count;
	int	rrb_count;

	closest = find_closest(*stack_a, node->index);
	ra_count = distance(*stack_a, closest);
	rra_count = distance(closest, back(*stack_a)) + 1;
	rb_count = distance(*stack_b, node);
	rrb_count = distance(node, back(*stack_b)) + 1;
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

