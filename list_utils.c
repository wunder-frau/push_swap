#include "push_swap.h"

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

/**
 * Finds and returns a node in a linked list at a specific position
 */
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
 * Set indices according to each node position.
 */
void	set_indices(t_node *head)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
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
 * Get the max element.
 */
/*t_node	*max(t_node *head)
{
	t_node	*max;
	t_node	*node;

	max = head;
	node = head;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}*/

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
 * Get length.
 */
int	len(t_node *head)
{
	if (!head)
		return (0);
	return (distance(head, back(head)) + 1);
}

/**
 * Inserts node at any position after prev node. Invalidates indices.
 */
void	insert(t_node *prev, t_node *curr)
{
	if (prev == NULL || curr == NULL)
		return;
	curr->next = prev->next;
	prev->next = curr;
}

/**
 * Create a node at the front with a value. Invalidates indices.
 */
void	push_front(t_node **head, int value)
{
	t_node *new;

	new = new_node(value);
	if (head || new)
		new->next = *head;
	*head = new;
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
 * Get the element before last by using (len(*head) - 2).
 */
void	rotate_front(t_node **head)
{
	t_node	*last;

	last = back(*head);
	if(*head == NULL || last == *head)
		return ;
	// at_pos(*head, last->index - 1)->next = NULL;
	at_pos(*head, len(*head) - 2)->next = NULL;
	last->next = *head;
	*head = last;
}

/**
 * Move first element to the end.
 */
void	rotate_back(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	// int		last_ind;

	if (*head == NULL || (*head)->next == NULL)
		return ;

	temp = *head;
	*head = (*head)->next;
	last = back(*head);
	temp->next = NULL;
	last->next = temp;
}

/**
 *  Delete the front element.
 */
void	pop_front(t_node **head)
{
	t_node	*front;
	
	if (*head == NULL)
		return ;
	front = *head;
	*head = (*head)->next;
	free(front);
}

void	free_list(t_node **head)
{
	t_node	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}