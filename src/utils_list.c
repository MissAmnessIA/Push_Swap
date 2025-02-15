#include "../inc/push_swap.h"

void	free_stack(t_stack *head)
{
	t_stack	*temp;

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
		last = get_last_node(*head);
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

void	target_on_top(t_stack **head, t_stack *target, char c_head)
{
	if (target->mid == 0)
	{
		while ((*head) != target)
			rotate(head, NULL, c_head);
	}
	else if (target->mid == 1)
	{
		while ((*head) != target)
			rrotate(head, NULL, c_head);
	}
}

void	cheapest_on_top(t_stack **head, char c_head)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*head);
	if (cheapest->mid == 0)
	{
		while ((*head) != cheapest)
			rotate(head, NULL, c_head);
	}
	else if (cheapest->mid == 1)
	{
		while ((*head) != cheapest)
			rrotate(head, NULL, c_head);
	}
}
