#include "push_swap.h"

/**
 * Move exactly count values from stack A to stack B by using pb action,
 * i.e. this also reverts the elements order in the new stack.
 */
void	move_n(t_node **stack_a, t_node **stack_b, int count)
{
	while (count > 0 && *stack_a)
	{
		pb(stack_b, stack_a);
		count--;
	}
}