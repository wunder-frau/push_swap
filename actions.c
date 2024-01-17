#include "push_swap.h"

void sa(t_node *stack_a)
{
	swap_values(stack_a, stack_a->next);
	put_str("sa\n");
}

void sb(t_node *stack_b)
{
	swap_values(stack_b, stack_b->next);
	put_str("sb\n");
}

void ss(t_node *stack_a, t_node *stack_b)
{
	swap_values(stack_a, stack_a->next);
	swap_values(stack_b, stack_b->next);
	put_str("ss\n");
}

void pa(t_node **stack_a, t_node *stack_b)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_a, stack_b->value);
	put_str("pa\n");
}

void pb(t_node **stack_b, t_node *stack_a)
{
	if (stack_a == NULL)
		return ;
	push_front(stack_b, stack_a->value);
	put_str("pb\n");
}

void ra(t_node **stack_a)
{
	rotate_back(stack_a);
	put_str("ra\n");
}

void rb(t_node **stack_b)
{
	rotate_back(stack_b);
	put_str("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b)
{
	rotate_back(stack_a);
	rotate_back(stack_b);
	put_str("rr\n");
}

void rra(t_node **stack_a)
{
	rotate_front(stack_a);
	put_str("rra\n");
}

void rrb(t_node **stack_b)
{
	rotate_front(stack_b);
	put_str("rrb\n");
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_front(stack_a);
	rotate_front(stack_b);
	put_str("rrr\n");
}