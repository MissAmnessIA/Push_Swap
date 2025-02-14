#include "../inc/push_swap.h"

t_stack *get_max(t_stack *head)
{
	int		n;
	t_stack	*max;

	max = NULL;
	n = INT_MIN;
	while(head)
	{
		if (n < head->n)
		{
			n = head->n;
			max  = head;
		}
		head = head->next;
	}
	return (max);
}

t_stack *get_min(t_stack *head)
{
	int		n;
	t_stack	*min;

	min = NULL;
	n = INT_MAX;
	while(head)
	{
		if (n > head->n)
		{
			n = head->n;
			min  = head;
		}
		head = head->next;
	}
	return (min);
}

t_stack	*get_cheapest(t_stack *head)
{
	t_stack	*cheapest;

	cheapest = head;
	if (!head)
		return NULL;
	if (stack_len(head) == 1)
		return (head);
	else
	{
		while (head)
		{
			if (cheapest->cost > head->cost)
				cheapest = head;
			head = head->next;
		}
	}
	return (cheapest);
}

t_stack	*get_last_node(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
