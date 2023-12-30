/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:07:56 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 17:21:10 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

int	stk_len(t_stack *stk)
{
	int len;

	len = 0;

	if (!stk)
		return(0);
	while (stk != NULL)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}

void	add_index(t_stack *stk_a, int stk_len)
{
	t_stack *ptr;
	t_stack	*highest;
	int		value;

	while (stk_len > 0)
	{
		ptr = stk_a;
		highest = NULL;
		value = INT_MAX;
		while(ptr)
		{
			if (ptr->value == INT_MAX && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stk_a;
			}
			else
				ptr = ptr->next;
			if (highest != NULL)
				highest->index = stk_len;
		}
	}
}

t_stack	*stack_new(int value)
{
	t_stack	*new;
	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->next = NULL;
	return (new);
}
