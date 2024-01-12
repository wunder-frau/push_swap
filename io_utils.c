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

long int	at_indoi(const char *str)
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

t_node *fill_lst(int argc, char **argv)
{
	t_node		*head;
	long int	nb;
	int			i;

	head = NULL;
	nb = 0;
	i = 1;

	while (i < argc)
	{
		nb = at_indoi(argv[i]);
		if (i == 1)
			head = new_node((int)nb);
		else
			push_back(head, (int)nb);
		i++;
	}
	return (head);
}