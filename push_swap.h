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
# include <unistd.h>
// # include <limits.h>

typedef struct s_node
{
	int		index;
	int		value;
	int		cost_a;
	int		cost_b;
	struct	s_node *next;
} t_node;

/* node_utils.c */
void	swap_values(t_node *a, t_node *b);
void	swap_indices(t_node *a, t_node *b);
t_node	*new_node(int value);
int		distance(t_node *first, t_node *last);
void	incr_indices(t_node *tail);
void	decr_indices(t_node *tail);
void	insert(t_node *prev, t_node *curr);
t_node	*at_ind(t_node *head, int index);
t_node	*at_pos(t_node *head, int pos);
void	put_str(char *str);
t_node	*back(t_node *node);
int		len(t_node *head);
void	push_front(t_node **head, int value);
void	push_back(t_node *head, int value);
void	reverse_rotate(t_node **head);
void	forward_rotate(t_node **head);

/* quicksort.c */
int		partition(t_node *head, int start, int end);
void	quicksort(t_node *head, int start, int end);

/* actions.c */
void sa(t_node *stack_a);
void sb(t_node *stack_b);
void ss(t_node *stack_a, t_node *stack_b);
void pa(t_node **stack_a, t_node *stack_b);
void pb(t_node **stack_b, t_node *stack_a);
void ra(t_node **stack_a);
void rb(t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

/* stack init */
t_node  *fillstack(int argc, char **argv);

/* utils.c */
int			is_digit(char c);
long int	at_indoi(const char *str);
void		free_stack(t_node **stack);

/* micro_sort.c */
void	micro_sort(t_node **stack);

/* cost.c */
void	get_cost(t_node *stack_a, t_node *stack_b);

#endif
