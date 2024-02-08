/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:52:39 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/07 15:52:44 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sign(char c)
{
	return (c == '+' || c == '-');
}

bool	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == 0)
		return (false);
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0')
		return (false);
	return (true);
}

bool	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (false);
	return (true);
}

t_node	*fill_list(int count, char **nums)
{
	t_node	*head;
	int		nb;
	int		i;

	head = new_node(ft_atoi(nums[0]));
	if (head->value == -1)
		handle_error(NULL, NULL);
	nb = 0;
	i = 1;
	while (i < count)
	{
		nb = ft_atoi(nums[i]);
		if (nb == -1)
			handle_error(NULL, NULL);
		push_back(head, nb);
		if (!is_unique(head, back(head)))
			handle_error(&head, NULL);
		i++;
	}
	set_indices(head);
	return (head);
}
