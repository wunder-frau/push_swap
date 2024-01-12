#include "push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	swap_indices(t_node *a, t_node *b)
{
	int tmp;

	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

/**
 * Generates self-existing new node, i.e. head node.
 */
t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

/**
 * Increment each index after the node.
 */
void	incr_indices(t_node *tail)
{
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

/**
 * Decrement each index after the node.
 */
void	decr_indices(t_node *tail)
{
	while (tail)
	{
		(tail->index)--;
		tail = tail->next;
	}
}

/**
 * Distance between two nodes.
 */
int	distance(t_node *first, t_node *last)
{
	int	res;

	res = 0;
	while(first && first != last)
	{
		res++;
		first = first->next;
	}
	return(res);
}

/**
 * Inserts node at any position after prev node.
 * Iteration is used to update the subsequent nodes indices.
 */
void	insert(t_node *prev, t_node *curr)
{
	if (prev == NULL || curr == NULL)
		return;
	curr->next = prev->next;
	prev->next = curr;
	curr->index = prev->index;
	incr_indices(prev->next);
}

void	put_str(char *str)
{
	int i;
	i = 0;

	while(str[i])
		write(1, &str[i++], 1);
}

/**
 * Returns node at position.
 */
t_node	*at_ind(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

t_node	*at_pos(t_node *head, int pos)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node && i != pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}

/**
 * Get the last element.
 */
t_node *back(t_node *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}

/**
 * Get length.
 */
int	len(t_node *head)
{
	if (!head)
		return (0);
	return (distance(head, back(head)) + 1);
}

/** 
 * Create a node at the front with a value.
 * Iteration is used to update the subsequent nodes indices.
 */
void	push_front(t_node **head, int value)
{
	t_node *new;

	new = new_node(value);
	if (head || new)
		new->next = *head;
	*head = new;
	incr_indices(new->next);
}

/**
 * Create node at the end with a value.
 */
void	push_back(t_node *head, int value)
{
	insert(back(head), new_node(value));
}

/**
 * Move the last element to the front.
 */
void	reverse_rotate(t_node **head)
{
	t_node	*last;

	last = back(*head);
	if(*head == NULL || last == *head)
		return ;
	at_ind(*head, last->index - 1)->next = NULL;
	last->next = *head;

	*head = last;
	(*head)->index = 0;
	incr_indices((*head)->next);
}


/**
 * Move first element to the end.
 */
void	forward_rotate(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	int		last_ind;

	if (*head == NULL || (*head)->next == NULL)
		return ;

	temp = *head;
	*head = (*head)->next;
	last = back(*head);
	last_ind = last->index;
	temp->next = NULL;
	last->next = temp;

	decr_indices(*head);
	back(*head)->index = last_ind;
}