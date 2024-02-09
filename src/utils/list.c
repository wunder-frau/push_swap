/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:53:29 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 15:54:12 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Check if the `node`'s value is unique.
 */
bool	is_unique(t_node *head, t_node *unique)
{
	t_node	*node;

	node = head;
	while (node)
	{
		if (node != unique && node->value == unique->value)
			return (false);
		node = node->next;
	}
	return (true);
}

/**
 * Check if linked list is sorted in ascending order.
*/
bool	is_sorted(t_node *head)
{
	t_node	*node;

	node = head;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

/**
 * Create a node at the front with a value. Invalidates indices.
 */
void	push_front(t_node **head, int value)
{
	t_node	*new;

	new = new_node(value);
	if (head || new)
		new->next = *head;
	*head = new;
}

/**
 * Create node at the end with a value.
 */
void	push_back(t_node *head, int value)
{
	insert(back(head), new_node(value));
}
