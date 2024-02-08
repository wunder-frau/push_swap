/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:48 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 13:49:01 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Move the last element to the front.
 * Get the element before last by using (len(*head) - 2).
 */
void	rotate_front(t_node **head)
{
	t_node	*last;

	last = back(*head);
	if (*head == NULL || last == *head)
		return ;
	at_pos(*head, len(*head) - 2)->next = NULL;
	last->next = *head;
	*head = last;
}

/**
 * Move first element to the end.
 */
void	rotate_back(t_node **head)
{
	t_node	*last;
	t_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	last = back(*head);
	temp->next = NULL;
	last->next = temp;
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
