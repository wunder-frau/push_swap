#include "push_swap.h"
// ?
void	put_str(char *str)
{
	int i;
	i = 0;

	while(str[i])
		write(1, &str[i++], 1);
}

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static bool	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == 0)
		return (false);
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0')
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

static bool	is_zero(char *argv)
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

t_node *fill_list(int count, char **nums)
{
	t_node	*head;
	int		nb;
	int		i;

	head = new_node(ft_atoi(nums[0]));
	if (!head)
		handle_error(NULL, NULL); // ?
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

/**
 * Prints "Error\n" after freeing stack a and b, exits with error code 1.
 */
void	handle_error(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_list(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_list(stack_b);
	write(2, "Error\n", 6);
		exit (1);
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