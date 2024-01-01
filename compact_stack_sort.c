/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compact_stack_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:06:23 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/31 14:02:32 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	int	index;

	index = stack->index;

	while(stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
} 


void	compact_stack_sort(t_stack **stack)
{
	int highest;

	highest = get_max_index(*stack);
	if ((*stack)->index == highest)
		rotate(stack);
	else if ((*stack)->next->index == highest)
		rev_rotate(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap(*stack);
}
