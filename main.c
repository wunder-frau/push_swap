/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:19:40 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 15:46:04 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Function to print the stack
static void print_stack(t_stack *stack) {
    while (stack != NULL) {
		printf("num: %d\n", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void	add_index(t_stack *stk_a, int stk_len)
{
	t_stack *ptr;
	t_stack	*highest;
	int		value;

	while (--stk_len > 0)
	{
		ptr = stk_a;
		highest = NULL;
		value = INT_MIN;
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
		}
			if (highest != NULL)
				highest->index = stk_len;
	}
}

static void print_indices(t_stack *stk_a)
{
    t_stack *ptr = stk_a;

    printf("Printing indices:\n");
    while (ptr)
    {
        printf("Node value: %d, Node index: %d\n", ptr->value, ptr->index);
        ptr = ptr->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack *stk_b;
	int		stack_len;

	if (argc < 2)
		return (0);
	stk_b = NULL;
	stk_a = fill_stk(argc, argv);
	stack_len = stk_len(stk_a);
	add_index(stk_a, stack_len + 1);

	/* check */	
	print_stack(stk_a);
	printf("Stack length: %d\n", stack_len);
	print_indices(stk_a);

	
	get_max_index(stk_a);

    // Displaying the sorted stack
    printf("Sorted Stack: ");
	printf("Stack length: %d\n", get_max_index(stk_a));
	compact_stack_sort(stk_a);
	printf("compact: %d\n", stk_a);
	/********/
	free_stack(&stk_a);
	free_stack(&stk_b);
	return (0);
}
