#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	if (is_sorted(*a))
		return ;
	if((*a)->n < (*a)->next->n
	&& (*a)->n < (*a)->next->next->n)
		swap(a, NULL, 'a');
	else if ((*a)->n > (*a)->next->n
	&& (*a)->n < (*a)->next->next->n)
		swap(a, NULL, 'a');
	else if ((*a)->n > (*a)->next->n
	&& (*a)->next->next->n < (*a)->next->n)
		swap(a, NULL, 'a');
	if (!is_sorted(*a) && (*a)->next->n < (*a)->next->next->n)
		rotate(a, NULL, 'a');
	else if (!is_sorted(*a) && (*a)->next->n > (*a)->next->next->n)
		rrotate(a, NULL, 'a');
}

void	prepare_to_push(t_stack **head, t_stack **target, char ch, char ct)
{
	t_stack *cheapest;
	t_stack *target_node;

	cheapest = get_cheapest(*head);
	target_node = cheapest->target_node;
	if (cheapest->mid == 0 && target_node->mid == 0)
	{
		while ((*head) != cheapest && (*target) != target_node)
			rotate(head, target, 'c');
	}
	else if (cheapest->mid == 1 && target_node->mid == 1)
	{
		while ((*head) != cheapest && (*target) != target_node)
			rrotate(head, target, 'c');
	}
	if ((*head) != cheapest)
		cheapest_on_top(head, ch);
	if ((*target) != target_node)
		target_on_top(target, target_node, ct);
}
void	pass_a_to_b(t_stack **a, t_stack **b)
{
	push(a, b, 'b');
	if (stack_len(*a) != 3)
		push(a, b, 'b');
	while (stack_len(*a) != 3)
	{
		set_values(*a, *b);
		get_target_node_a(*a, *b);
		set_cost(*a, *b);
		set_cheapest(*a);
		prepare_to_push(a, b, 'a', 'b');
		push(a, b, 'b');
	}
}

void pass_b_to_a(t_stack **a, t_stack **b)
{
	while (stack_len(*b) != 0)
	{
		set_values(*a, *b);
		get_target_node_b(*a, *b);
		set_cost(*b, *a);
		set_cheapest(*b);
		prepare_to_push(b, a, 'b', 'a');
		push(b, a, 'a');
	}
}
void	sort_stacks(t_stack **a, t_stack **b)
{
	if(is_sorted(*a))
		return ;
	if (stack_len(*a) == 2)
		swap(a,NULL, 'a');
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
	{
		pass_a_to_b(a, b);
		sort_three(a);
		pass_b_to_a(a, b);
		set_values(*a, *b);
		min_on_top(a);
	} 
}