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
# include <stdlib.h>
/*
# include <unistd.h>
# include <limits.h>
void sa(t_node *stack_a)
{
	ft_swap(stack_a, stack_a->next);
}
void sb(t_node *stack_b)
{
	ft_swap(stack_b, stack_b->next);
}
void ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
*/

typedef struct s_node
{
	int		index;
	int		value;
	struct	s_node *next;
} t_node;

/* node_utils.c */
void	ft_swap(t_node *a, t_node *b);
t_node	*ft_newnode(int value);
void	ft_insert(t_node *prev, t_node *curr);
t_node	*ft_at(t_node *head, int index);
t_node	*ft_last(t_node *node);
void	ft_pushback(t_node *head, int value);

/* quicksort.c */
int		ft_partition(t_node *head, int start, int end);
void	ft_quicksort(t_node *head, int start, int end);

#endif
