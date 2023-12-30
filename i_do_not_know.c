/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_do_not_know.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:16:01 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 11:46:45 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *fill_stk(int argc, char **argv)
{
	t_stack		*stk_a;
	long int	nb;
	int			i;

	stk_a = NULL;
	nb = 0;
	i = 1;

	while (argc > i)
	{
		nb = ft_atoi(argv[i]);
		if (i == 1)
			stk_a = stack_new((int)nb);
		else
			add_stack_back(&stk_a, stack_new((int)nb));
		i++;
	}
	return (stk_a);
}
