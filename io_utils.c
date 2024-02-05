#include "push_swap.h"

void	put_str(char *str)
{
	int i;
	i = 0;

	while(str[i])
		write(1, &str[i++], 1);
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')	
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

static long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

t_node *fill_list(int count, char **nums)
{
	t_node		*head;
	long 		nb;
	int			i;
	long		nb_fill;

	nb_fill = ft_atoi(nums[0]);
	if (nb_fill > INT_MAX || nb_fill < INT_MIN)
		handle_error(NULL, NULL);
	head = new_node(nb_fill);
	nb = 0;
	if (!validate_input(nums))
		handle_error(NULL, NULL);
	i = 1;
	while (i < count)
	{
		nb = ft_atoi(nums[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			handle_error(&head, NULL); // ?
		push_back(head, (int)nb);
		if (!is_unique(head, back(head)))
			handle_error(&head, NULL);
		i++;
	}
	set_indices(head);
	return (head);
}
