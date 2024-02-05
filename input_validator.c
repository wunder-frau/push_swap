#include "push_swap.h"

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

void	ft_free_f(char **argv)
{
	int	i;
	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
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
