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

void	pass_a_to_b(t_stack **a, t_stack **b)
{
	push(a, b, 'b');
	if (stack_len(*a) != 3)
		push(a, b, 'b');
	while (stack_len(*a) != 3)
	{
		set_values(*a, *b);
		get_target_node_a(*a, *b);
		get_cost(*a, stack_len(*b));
		set_cheapest(*a);
		prepare_to_push(a, b);
		push(a, b, 'b');
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
	} 
}