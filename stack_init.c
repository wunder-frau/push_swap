#include "push_swap.h"

t_node  *ft_fillstack(int argc, char **argv)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;

	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
printf("Parsed value: %ld\n", nb);

		if (i == 1){
			stack_a = ft_newnode((int)nb);
			printf("(%d)", ft_newnode((int)nb)->value);
			printf("Parsed value l: %ld\n", nb);
		}
		else
		{
			ft_pushback(stack_a, nb);
			printf("Parsed value k: %ld\n", nb);
		}
		i++;
	}
	return (stack_a);
}