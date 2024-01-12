#include "push_swap.h"

t_node *fillstack(int argc, char **argv)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;

	while (i < argc)
	{
		nb = at_indoi(argv[i]);
		if (i == 1)
			stack_a = new_node((int)nb);
		else
			push_back(stack_a, (int)nb);
		i++;
	}
	return (stack_a);
}