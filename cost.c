#include "push_swap.h"

void	get_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_b;
	int		len_a;
	int		len_b;
	int 	pos;

	len_a = ft_len(stack_a);
	len_b = ft_len(stack_b);
	pos = 0;
	while (pos < len_b)
	{
		node_b = ft_atpos(stack_b, pos);
		if (pos > len_b / 2)
			node_b->cost_b = (len_b - pos) * -1;
		if (node_b->target_pos > len_a / 2)
			node_b->target_pos = (len_a - node_b->target_pos) * -1;
		pos++;
	}
}