/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:45:38 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 13:46:28 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_a, (*stack_b)->value);
	(*stack_a)->index = (*stack_b)->index;
	pop_front(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (stack_a == NULL)
		return ;
	push_front(stack_b, (*stack_a)->value);
	(*stack_b)->index = (*stack_a)->index;
	pop_front(stack_a);
	ft_putstr_fd("pb\n", 1);
}
