#include "push_swap.h"

static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	validate_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		nb_zeros += is_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}