/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:02:02 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 16:03:07 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Move `count` lowest values from stack A to stack B.
 * If the index is greater than `stack_init`, indicating
 * that it is on the left side of a stack, the loop
 * rotates `ra`; otherwise, it pushes to stack B using `pb`.
 * This reverts the elements order in the stack B due to usage of `pb`.
 */
void	move_n(t_node **stack_a, t_node **stack_b, const int count)
{
	int	half_size;
	int	n;

	half_size = len(*stack_a) / 2;
	n = 0;
	while (count > 0 && n < half_size)
	{
		if ((*stack_a)->index > half_size)
		{
			ra(stack_a);
		}
		else
		{
			pb(stack_b, stack_a);
			n++;
		}
	}
	while (n < count)
	{
		pb(stack_b, stack_a);
		n++;
	}
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	t_node	*optimal;

	optimal = find_optimal(*stack_a, *stack_b);
	to_front_ab(stack_a, stack_b, optimal);
	to_front_b(stack_b, optimal);
	to_front_a(stack_a, find_closest(*stack_a, optimal->index));
	pa(stack_a, stack_b);
}
