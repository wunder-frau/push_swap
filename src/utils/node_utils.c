/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:58:44 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 15:58:50 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	swap_indices(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

/**
 * Generates self-existing new node, i.e. head node.
 */
t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

/**
 * Inserts node at any position after prev node. Invalidates indices.
 */
void	insert(t_node *prev, t_node *curr)
{
	if (prev == NULL || curr == NULL)
		return ;
	curr->next = prev->next;
	prev->next = curr;
}

/**
 * Get the last element.
 */
t_node	*back(t_node *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}
