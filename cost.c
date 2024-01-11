#include "push_swap.h"

// static void	get_position(t_node **stack)
// {
// 	t_node	*tmp;
// 	int		i;

// 	tmp = *stack;
// 	i = 0;
// 	while (tmp)
// 	{
// 		tmp->pos = i;
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

void	get_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_b;
	int	len_b;
	int pos;

	len_b = ft_len(stack_b);
	pos = 0;
	while (pos < len_b)
	{
		node_b = ft_atpos(stack_b, pos);
		node_b->cost_b = node_b->pos;
		if (pos > len_b / 2) 
			node_b->cost_b = (len_b - pos) * -1;
		node_b->cost_a = node_b->target_pos;
		if (node_b->target_pos > ft_len(stack_a) / 2)
			node_b->cost_a = (ft_len(stack_a) - node_b->target_pos) * -1;
		pos++;
	}
}