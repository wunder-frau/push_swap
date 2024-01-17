#include "push_swap.h"

void	push_all_to_b(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;
	int	pushed;
	int	i;

	stack_len = len(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_len > 6 && i < stack_len && pushed < stack_len / 2)
	{
		if ((*stack_a)->index <= stack_len / 2)
		{
			pb(stack_b, *stack_a);
			pop_front(stack_a);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_len - pushed > 3)
	{
		pb(stack_b, *stack_a);
		pop_front(stack_a);
		pushed++;
	}
}