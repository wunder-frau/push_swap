#include "push_swap.h"

t_node *ft_fillstack(int argc, char **argv)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;

	while (i < argc)
	{
		nb = ft_atindoi(argv[i]);
		if (i == 1)
			stack_a = ft_newnode((int)nb);
		else
			ft_pushback(stack_a, (int)nb);
		i++;
	}
	return (stack_a);
}