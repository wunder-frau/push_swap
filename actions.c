#include "push_swap.h"

void sa(t_node *stack_a)
{
	ft_swap(stack_a, stack_a->next);
	ft_putstr("sa\n");
}

void sb(t_node *stack_b)
{
	ft_swap(stack_b, stack_b->next);
	ft_putstr("sb\n");
}

void ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr("ss\n");
}

void pa(t_node **stack_a, t_node *stack_b)
{
	if (stack_b == NULL)
		return ;
	ft_pushfront(stack_a, stack_b->value);
	ft_putstr("pa\n");
}

void pb(t_node **stack_b, t_node *stack_a)
{
	if (stack_a == NULL)
		return ;
	ft_pushfront(stack_b, stack_a->value);
	ft_putstr("pb\n");
}

void ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra\n");
}

void rb(t_node **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
}

void rra(t_node **stack_a)
{
	ft_revrotate(stack_a);
	ft_putstr("rra\n");
}

void rrb(t_node **stack_b)
{
	ft_revrotate(stack_b);
	ft_putstr("rrb\n");
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr("rrr\n");
}