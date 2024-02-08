/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:18:36 by istasheu          #+#    #+#             */
/*   Updated: 2024/02/08 17:18:39 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Prints "Error\n" after freeing stack a and b, exits with error code 1.
 */
void	handle_error(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_list(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_list(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	free_list(t_node **head)
{
	t_node	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

bool	is_valid(int argc, char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (false);
		nb_zeros += is_zero(argv[i]);
		i++;
	}
	return (nb_zeros <= 1);
}
