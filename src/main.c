/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:54:35 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 15:56:09 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Uses `argc` to store elements count. Fills stack a.
 * Process 2 cases with 1 input value and multiple input values.
 * 1 input value: acsepts 1 string, needs to be processed by ft_split
 * and count "words" again.
 * multiple input values: doesnt consider program name in argv.
 */
static t_node	*fill(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		if (!is_valid(argc, argv))
			handle_error(NULL, NULL);
		stack_a = fill_list(argc, argv);
		free_argv(argv);
	}
	else
	{
		argv = &argv[1];
		argc--;
		if (!is_valid(argc, argv))
			handle_error(NULL, NULL);
		stack_a = fill_list(argc, argv);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = fill(argc, argv);
	stack_b = NULL;
	count = len(stack_a);
	if (count > 1 && !is_sorted(stack_a))
	{
		quicksort_indices(stack_a, 0, count - 1);
		move_n(&stack_a, &stack_b, count - 3);
		micro_sort(&stack_a);
		while (stack_b)
			push_swap(&stack_a, &stack_b);
		if (!is_sorted(stack_a))
			to_front_a(&stack_a, find_min(stack_a));
	}
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
