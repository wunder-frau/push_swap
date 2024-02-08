/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:50:17 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 13:50:28 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node *stack_a)
{
	swap_values(stack_a, stack_a->next);
	swap_indices(stack_a, stack_a->next);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node *stack_b)
{
	swap_values(stack_b, stack_b->next);
	swap_indices(stack_b, stack_b->next);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	swap_values(stack_a, stack_a->next);
	swap_indices(stack_a, stack_a->next);
	swap_values(stack_b, stack_b->next);
	swap_indices(stack_b, stack_b->next);
	ft_putstr_fd("ss\n", 1);
}
