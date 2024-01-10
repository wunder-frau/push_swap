#include "push_swap.h"

/**
*  The micro_sort function is designed for sorting a subset of a stack
*  consisting of three elements. It employs basic stack manipulation
*  operations (ra, sa, and rra) to achieve a specific sorting pattern.
*  This function assumes that the stack has at least three elements.
   Example Usage:
   - Before calling micro_sort: {(0),[0],3}->{(1),[1],1}->{(2),[2],2}->NULL
   - After calling micro_sort:  {(0),[0],3}->{(1),[1],2}->{(2),[2],1}->NULL
*/
void micro_sort(t_node **stack)
{
	if((*stack)->value > (*stack)->next->value && (*stack)->value > ft_last(*stack)->value)
		ra(stack);
	if((*stack)->value > (*stack)->next->value)
		sa(*stack);
	if((*stack)->next->value > ft_last(*stack)->value)
		rra(stack);
	if((*stack)->value > (*stack)->next->value)
		sa(*stack);
}