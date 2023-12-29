/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istasheu <istasheu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:22:10 by istasheu          #+#    #+#             */
/*   Updated: 2023/12/29 10:33:27 by istasheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				is_negative;
	long long		number;

	is_negative = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			is_negative = -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = number * 10 + (*(str++) - '0');
		if (number < 0)
		{
			if (is_negative > 0)
				return (-1);
			return (0);
		}
	}
	return ((int)number * is_negative);
}

