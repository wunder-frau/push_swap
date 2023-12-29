/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:19:40 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 14:46:43 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print the stack
static void print_stack(t_stack *stack) {
    while (stack != NULL) {
		printf("num: %d\n", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack *stk_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stk_b = NULL;
	stk_a = fill_stk(argc, argv);
	print_stack(stk_a);
	return (0);
}
