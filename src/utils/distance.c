/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:13:19 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 17:13:25 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Get the max element.
 */
t_node	*find_max(t_node *head)
{
	t_node	*max;
	t_node	*node;

	max = head;
	node = head;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

/**
 * Get the min element.
 */
t_node	*find_min(t_node *head)
{
	t_node	*min;
	t_node	*node;

	min = head;
	node = head;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

/**
 * Distance between two nodes.
 */
int	distance(t_node *first, t_node *last)
{
	int	res;

	res = 0;
	while (first && first != last)
	{
		res++;
		first = first->next;
	}
	return (res);
}

/**
 * Get length.
 */
int	len(t_node *head)
{
	if (!head)
		return (0);
	return (distance(head, back(head)) + 1);
}
