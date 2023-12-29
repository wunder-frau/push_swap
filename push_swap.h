/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:02:32 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 15:39:15 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		value;
	int		index;
	int		position;
	struct	s_stack *next;
} t_stack;

/* stack */

t_stack	*stack_new(int value);
t_stack *fill_stk(int argc, char **argv);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*get_stack_bottom(t_stack *stack);
int	stk_len(t_stack *stk);

/* utils */

int	ft_atoi(const char *str);

#endif
