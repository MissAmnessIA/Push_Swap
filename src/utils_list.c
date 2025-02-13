#include "../inc/push_swap.h"

void	free_stack(t_stack *head)
{
	t_stack *temp;
	
	temp = head;
	if (head)
	{
		while (temp->next)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
}

void	add_last(t_stack **head, int n)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->n = n;
	new_node->next = NULL;
	if (!(*head))
		(*head) = new_node;
	else
	{
		last = (*head);
		last = last_node(*head);
		last->next = new_node;
	}
}

int	stack_len(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}