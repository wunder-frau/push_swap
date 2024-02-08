/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:18:02 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 17:18:05 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Returns node at position.
 */
t_node	*at_ind(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

/**
 * Finds and returns a node in a linked list at a specific position
 */
t_node	*at_pos(t_node *head, int pos)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node && i != pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}

/**
 * Set indices according to each node position.
 */
void	set_indices(t_node *head)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
