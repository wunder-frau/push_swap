#include "push_swap.h"

/**
 * Move `count` lowest values from stack A to stack B.
 * This reverts the elements order in the stack B due to usage of `pb`.
 */
void	move_n(t_node **stack_a, t_node **stack_b, int count)
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
 * Move element with the highest index to the front by rotating the stack.
 * Rotates using the `rb` action if the initial element position is closer
 * to front, othervise reverse rotates using `rrb`.
 */
void	max_to_front(t_node **stack_b)
{
	t_node *max;
	int	rb_count;
	int	rrb_count;

	max = at_ind(*stack_b, len(*stack_b) - 1);
	rb_count = distance(*stack_b, max);
	rrb_count = distance(max, back(*stack_b));
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