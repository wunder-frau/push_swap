#include "push_swap.h"

void	get_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_b;
	int		len_a;
	int		len_b;
	int 	pos;

	len_a = len(stack_a);
	len_b = len(stack_b);
	pos = 0;
	while (pos < len_b)
	{
		node_b = at_pos(stack_b, pos);
		if (pos > len_b / 2)
			node_b->cost_b = (len_b - pos) * -1;
		node_b->cost_a = node_b->index;
		if (node_b->index > len_a / 2)
			node_b->cost_a = (len_a - node_b->index) * -1;
		pos++;
	}
}

static int nb_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}

void	do_cheapest_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	//get_cost(*stack_a, *stack_b);
	move(stack_a, stack_b, cost_a, cost_b);
}