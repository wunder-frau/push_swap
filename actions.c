#include "push_swap.h"

void sa(t_node *stack_a)
{
	ft_swap(stack_a, stack_a->next);
}

void sb(t_node *stack_b)
{
	ft_swap(stack_b, stack_b->next);
}

void ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_node **stack_a, t_node *stack_b)
{
	if (stack_b == NULL)
		return ;
	ft_pushfront(stack_a, stack_b->value);
}

void pb(t_node **stack_b, t_node *stack_a)
{
	if (stack_a == NULL)
		return ;
	ft_pushfront(stack_b, stack_a->value);
}

void ra(t_node **stack_a)
{
	ft_rotate(stack_a);
}

void rb(t_node **stack_b)
{
	ft_rotate(stack_b);
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void rra(t_node **stack_a)
{
	ft_revrotate(stack_a);
}

void rrb(t_node **stack_b)
{
	ft_revrotate(stack_b);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}