/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:22 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 14:07:46 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
*  The micro_sort function is designed for sorting a subset of a stack
*  consisting of three elements. It employs basic stack manipulation
*  operations (ra, sa, and rra) to achieve a specific sorting pattern.
*  This function assumes that the stack has at least three elements.
*/
void	micro_sort(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > back(*stack)->value)
		ra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
	if ((*stack)->next->value > back(*stack)->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
}
