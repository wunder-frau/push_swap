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
# include <limits.h>

typedef struct s_node
{
	int		index;
	int		value;
	int		cost_a;
	int		cost_b;
	struct	s_node *next;
} t_node;

/* node_utils.c */
void		swap_values(t_node *a, t_node *b);
void		swap_indices(t_node *a, t_node *b);
t_node		*new_node(int value);
void		free_lst(t_node **head);
int			distance(t_node *first, t_node *last);
void		incr_indices(t_node *tail);
void		decr_indices(t_node *tail);
void		insert(t_node *prev, t_node *curr);
t_node		*at_ind(t_node *head, int index);
t_node		*at_pos(t_node *head, int pos);
t_node		*back(t_node *node);
int			len(t_node *head);
void		push_front(t_node **head, int value);
void		push_back(t_node *head, int value);
void		rotate_front(t_node **head);
void		rotate_back(t_node **head);
void		pop_front(t_node **head);

/* quicksort.c */
int			partition(t_node *head, int start, int end);
void		quicksort(t_node *head, int start, int end);

/* actions.c */
void		sa(t_node *stack_a);
void		sb(t_node *stack_b);
void		ss(t_node *stack_a, t_node *stack_b);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_b, t_node **stack_a);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);

/* io_utils.c */
void		put_str(char *str);
int			is_digit(char c);
long int	ft_atoi(const char *str);
t_node		*fill_lst(int argc, char **argv);

/* micro_sort.c */
void		micro_sort(t_node **stack);

/* cost.c */
void		get_cost(t_node *stack_a, t_node *stack_b);
void		do_cheapest_move(t_node **stack_a, t_node **stack_b);

/* sort.c */
void		push_all_to_b(t_node **stack_a, t_node **stack_b);
void		shift_stack(t_node **stack_a);
void	sort(t_node **stack_a, t_node **stack_b);

/* move.c */
void	move(t_node **a, t_node **b, int cost_a, int cost_b);


int	is_sorted(t_node *stack);
#endif