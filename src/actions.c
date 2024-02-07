/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:12:05 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 15:40:31 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_a, (*stack_b)->value);
	//(*stack_a)->index = (*stack_b)->index;
	swap_indices(*stack_a, *stack_b);
	pop_front(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (stack_a == NULL)
		return ;
	push_front(stack_b, (*stack_a)->value);
	//(*stack_b)->index = (*stack_a)->index;
	swap_indices(*stack_b, *stack_a);
	pop_front(stack_a);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_node **stack_a)
{
	rotate_back(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **stack_b)
{
	rotate_back(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_back(stack_a);
	rotate_back(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_node **stack_a)
{
	rotate_front(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **stack_b)
{
	rotate_front(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_front(stack_a);
	rotate_front(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
