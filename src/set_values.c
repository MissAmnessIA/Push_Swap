#include "../inc/push_swap.h"


void	set_cheapest(t_stack *head)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(head);
	while (head)
	{
		if (head == cheapest)
			head->cheapest = 1;
		else
			head->cheapest = 0;
	}
}
void	set_index(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head->index = i;
		i++;
		head = head->next;
	}
}

void	set_mid(t_stack *head)
{
	int	mid_pos;

	mid_pos = (stack_len(head) / 2) + 1;
	while (head)
	{
		if (head->index >= mid_pos)
			head->mid = 1;
		else
			head->mid  = 0;
		head = head->next;
	} 
}

void	set_cost(t_stack *node, int s_target)
{
	int	node_len;
	t_stack	t_node;

	node_len = stack_len(node);
	while (node)
	{
		t_node = node->target_node;
		if (node->mid == 0)
		{
			if (t_node->mid == 0)
				node->cost = ncompare_m(node->index, t_node->index);
			else
				node->cost = node->index + s_target - t_node->index;
		}
		else if (node->mid == 1)
		{
			if (t_node->mid == 1)
				node->cost = ncompare_m((node_len - node->index), (s_target - tnode->index));
			else
				node->cost = node_len - node->index + t_node->index; 
		}
		node = node->next;
	}
}

void	set_values(t_stack *head1, t_stack *head2)
{
	set_index(head1);
	set_index(head2);
	set_mid(head1);
	set_mid(head2);
}