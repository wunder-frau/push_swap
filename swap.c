/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:56:45 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/30 14:56:49 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
    int temp;

    if (stack == NULL || stack->next == NULL)
        return ;
    temp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = temp;
    temp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = temp;
    /* check */
	printf("swap\n");
}

