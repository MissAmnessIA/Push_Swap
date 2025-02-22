/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:47:51 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/22 17:47:55 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	set_cheapest(t_stack *head)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(head);
	if (stack_len(head) == 1)
		head->cheapest = 1;
	else
	{
		while (head)
		{
			if (head == cheapest)
				head->cheapest = 1;
			else
				head->cheapest = 0;
			head = head->next;
		}
	}
}

void	set_index(t_stack *head)
{
	int	i;
	int	mid_pos;

	mid_pos = (stack_len(head) / 2) + 1;
	i = 0;
	while (head)
	{
		if (i < mid_pos)
			head->mid = 0;
		else
			head->mid = 1;
		head->index = i;
		i++;
		head = head->next;
	}
}

void	set_cost(t_stack *node, t_stack *target)
{
	int	node_len;
	int	target_len;

	node_len = stack_len(node);
	target_len = stack_len(target);
	while (node)
	{
		node->cost = node->index;
		if (node->mid == 1)
			node->cost = node_len - node->index;
		if (node->target_node->mid == 0)
			node->cost += node->target_node->index;
		else if (node->target_node->mid == 1)
			node->cost += target_len - node->target_node->index;
		node = node->next;
	}
}

void	set_values(t_stack *head1, t_stack *head2)
{
	set_index(head1);
	set_index(head2);
}
