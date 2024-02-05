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

bool	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (false);
	return (true);
}

static int	ft_atoi(const char *str)
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
	nb *= isneg;
	if (!(INT_MIN <= nb && nb <= INT_MAX))
		handle_error(NULL, NULL); // ?
	return (nb);
}

t_node *fill_list(int count, char **nums)
{
	t_node	*head;
	int		nb;
	int		i;

	head = new_node(ft_atoi(nums[0]));
	if (!head)
		handle_error(&head, NULL); // ?
	nb = 0;
	i = 1;
	while (i < count)
	{
		nb = ft_atoi(nums[i]);
		push_back(head, nb);
		if (!is_unique(head, back(head)))
			handle_error(&head, NULL);
		i++;
	}
	set_indices(head);
	return (head);
}
