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

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}	t_node;

/* actions/pa_pb.c */
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);

/* actions/ra_rb_rr.c */
void	rotate_front(t_node **head);
void	rotate_back(t_node **head);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

/* actions/rra_rrb_rrr.c */
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/* actions/sa_sb_ss.c */
void	sa(t_node *stack_a);
void	sb(t_node *stack_b);
void	ss(t_node *stack_a, t_node *stack_b);

/* sort/quicksort.c */
void	quicksort_indices(t_node *head, int start, int end);

/* sort/micro_sort.c */
void	micro_sort(t_node **stack);

/* sort/find_optimal.c */
t_node	*find_optimal(t_node *stack_a, t_node *stack_b);
t_node	*find_closest(t_node *head, const int index);

/* sort/to_front.c */
void	to_front_a(t_node **stack_a, t_node *node);
void	to_front_b(t_node **stack_b, t_node *node);
void	to_front_ab(t_node **stack_a, t_node **stack_b, t_node *node);

/* stack_helpers.c */
void	move_n(t_node **stack_a, t_node **stack_b, const int count);
void	push_swap(t_node **stack_a, t_node **stack_b);

/* utils/distance_utils.c */
t_node	*find_max(t_node *head);
t_node	*find_min(t_node *head);
int		distance(t_node *first, t_node *last);
int		len(t_node *head);

/* utils/io_utils.c */
bool	is_sign(char c);
bool	is_number(char *argv);
bool	is_zero(char *argv);
t_node	*fill_list(int count, char **nums);

/* utils/list_utils.c */
bool	is_unique(t_node *head, t_node *unique);
bool	is_sorted(t_node *head);
void	push_front(t_node **head, int value);
void	push_back(t_node *head, int value);

/* utils/node_utils.c */
void	swap_values(t_node *a, t_node *b);
void	swap_indices(t_node *a, t_node *b);
t_node	*new_node(int value);
void	insert(t_node *prev, t_node *curr);
t_node	*back(t_node *node);

/* utils/position_utils.c */
t_node	*at_ind(t_node *head, int index);
t_node	*at_pos(t_node *head, int pos);
void	set_indices(t_node *head);

/* utils/validation_utis.c */
void	handle_error(t_node **stack_a, t_node **stack_b);
void	free_list(t_node **head);
void	free_argv(char **argv);
bool	is_valid(int argc, char **argv);

#endif