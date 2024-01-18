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

void	shift_stack(t_node **stack_a)
{
	int	lowest_pos;
	int	stack_len;

	stack_len = len(*stack_a);
	lowest_pos = back(*stack_a)->value;
	if (lowest_pos > stack_len / 2)
	{
		while (lowest_pos < stack_len)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = len(*stack_a);
	push_all_to_b(stack_a, stack_b);
	micro_sort(stack_a);
	while (*stack_b)
	{
		//quicksort(*stack_a, 0, stack_len);
		get_cost(*stack_a, *stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	// if (!is_sorted(*stack_a))
 	shift_stack(stack_a);
}