#include "push_swap.h"

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
 * Find a node containing higher index.
 */
t_node	*find_closest(t_node *head, int index)
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

/*static int	min(const int lhs, const int rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}*/

/**
 * Count moves to get an element `node` to the top its stack
 */
/*static int count_moves(t_node *head, t_node *node)
{
	int	r_count;
	int	rr_count;
	int	moves_count;

	r_count = distance(head, node);
	rr_count = distance(node, back(head));
	rr_count++;
	moves_count = min(r_count, rr_count);
	return (moves_count);
}*/

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

/**
*  The micro_sort function is designed for sorting a subset of a stack
*  consisting of three elements. It employs basic stack manipulation
*  operations (ra, sa, and rra) to achieve a specific sorting pattern.
*  This function assumes that the stack has at least three elements.
   Example Usage:
   - Before calling micro_sort: {(0),[0],3}->{(1),[1],1}->{(2),[2],2}->NULL
   - After calling micro_sort:  {(0),[0],3}->{(1),[1],2}->{(2),[2],1}->NULL
*/
void micro_sort(t_node **stack)
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