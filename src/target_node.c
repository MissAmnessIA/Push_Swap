#include "../inc/push_swap.h"

void	get_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*temp;

	while (a)
	{
		target_node = NULL;
		temp = b;
		while (temp)
		{
			if (temp->n < a->n && target_node == NULL)
				target_node = temp;
			if (temp->n < a->n && target_node->n < temp->n)
				target_node = temp;
			temp = temp->next;
		}
		if (target_node == NULL)
			target_node = get_max(b);
		a->target_node = target_node;
		a = a->next;
	}
}

void	get_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*temp;

	while (b)
	{
		target_node = NULL;
		temp = a;
		while (temp)
		{
			if (temp->n > b->n && target_node == NULL)
				target_node = temp;
			if (temp->n > b->n && target_node->n > temp->n)
				target_node = temp;
			temp = temp->next;
		}
		if (target_node == NULL)
			target_node = get_min(a);
		b->target_node = target_node;
		b = b->next;
	}
}
