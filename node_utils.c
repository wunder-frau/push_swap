#include "push_swap.h"

void	ft_swap(t_node *a, t_node *b)
{
	int tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

/**
 * Inserts node at any position after prev node.
 * Iteration is required to update indices.
 */
t_node	*ft_newnode(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

/**
 * Increment each index after the node.
 */
void	ft_incrind(t_node *tail)
{
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

/**
 * Decrement the 'index' field of each node 
 * in the linked list, starting from the 
 * provided tail node, by 1.
 */
void	ft_decrind(t_node *tail)
{
	while (tail)
	{
		(tail->index)--;
		tail = tail->next;
	}
}

/**
 * Inserts node at any position after prev node.
 * Iteration is used to update indices.
 */
void	ft_insert(t_node *prev, t_node *curr)
{
	if (prev == NULL || curr == NULL)
		return;
	curr->next = prev->next;
	prev->next = curr;
	curr->index = prev->index;
	ft_incrind(prev->next);
}

void	ft_putstr(char *str)
{
    int i;
    i = 0;
    
    while(str[i])
    	write(1, &str[i++], 1);    
}

/**
 * Returns node at position.
 */
t_node	*ft_at(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

/**
 * Get the last element.
 */
t_node *ft_last(t_node *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}

/** 
 * Inserts a new node with the given value
 * at the front of the linked list and 
 * increments the indices of subsequent nodes. 
 */

void	ft_pushfront(t_node **head, int value)
{
	t_node *new;

	new = ft_newnode(value);
	if (head || new)
		new->next = *head;
	*head = new;
	ft_incrind(new->next);
}

/**
 * Create node at the end with a value.
 */
void	ft_pushback(t_node *head, int value)
{
	ft_insert(ft_last(head), ft_newnode(value));
}

/**
 * Shift up all elements of linked list a by 1.
 * The first element becomes the last one.
 */
void	ft_revrotate(t_node **head)
{
	t_node	*last;

	last = ft_last(*head);
	if(*head == NULL || last == *head)
		return ;
	ft_at(*head, last->index - 1)->next = NULL;
	last->next = *head;

	*head = last;
	(*head)->index = 0;
	ft_incrind((*head)->next);
}


/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
*/
void	ft_rotate(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	int	last_ind;

	if (*head == NULL || (*head)->next == NULL)
		return ;

	temp = *head;
	*head = (*head)->next;
	last = ft_last(*head);
	last_ind = last->index;
	temp->next = NULL;
	last->next = temp;

	ft_decrind(*head);
	ft_last(*head)->index = last_ind;
}