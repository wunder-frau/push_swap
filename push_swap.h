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
	struct	s_node *next;
} t_node;

/* node_utils.c */
void		swap_values(t_node *a, t_node *b);
void		swap_indices(t_node *a, t_node *b);
t_node		*new_node(int value);

/* list_utils.c */
t_node		*at_ind(t_node *head, int index);
t_node		*at_pos(t_node *head, int pos);
t_node		*back(t_node *node);
t_node		*find_max(t_node *head);
t_node		*find_min(t_node *head);
void		set_indices(t_node *head);
int			distance(t_node *first, t_node *last);
int			len(t_node *head);
void		insert(t_node *prev, t_node *curr);
void		push_front(t_node **head, int value);
void		push_back(t_node *head, int value);
void		rotate_front(t_node **head);
void		rotate_back(t_node **head);
void		pop_front(t_node **head);
void		free_list(t_node **head);

/* quicksort_indices.c */
void		quicksort_indices(t_node *head, int start, int end);

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
t_node		*fill_list(int argc, char **argv);

/* stack_helpers.c */
void		move_nmin(t_node **stack_a, t_node **stack_b, int count);
void		to_front_a(t_node **stack_a, t_node *node);
void		to_front_b(t_node **stack_b, t_node *node);
void 		micro_sort(t_node **stack);
t_node		*find_closest(t_node *head, int index);

#endif