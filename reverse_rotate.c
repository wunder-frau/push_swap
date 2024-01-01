/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:49:52 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/31 11:50:19 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack *tail;
	t_stack *prev_to_tail;

	tail = get_lstlast(*stack);
	prev_to_tail = get_penultimate(*stack);
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	prev_to_tail->next = NULL;
	/* check */
	printf("rev_rotate\n");
}
