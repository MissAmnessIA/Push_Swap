#include "../inc/push_swap.h"

void	swap(t_stack **head,t_stack **head2, char c)
{
	int	temp;

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
	if (c == 'c')
		swap(head2, NULL, 's');
	ft_printf("s%c\n", c);
}

void	rotate(t_stack **head, t_stack **head2, char c)
{
	t_stack *temp;
	t_stack *last;

	temp = (*head);
	last = last_node(*head);
	(*head) = (*head)->next;
	last->next = temp;
	temp->next = NULL;
	if (c == 'c')
		rotate(head2, NULL, 'r');
	if (c == 'a' || c == 'b' || c == 'r')
		ft_printf("r%c\n", c);
}

void	rrotate(t_stack **head, t_stack **head2, char c)
{
	t_stack *temp;
	t_stack *last;

	temp = (*head);
	last = last_node(*head);
	while (temp->next->next != NULL)
		temp = temp->next;
	last->next = (*head);
	temp->next = NULL;
	(*head) = last;
	if (c == 'c')
		rrotate(head2, NULL, 'r');
	if (c == 'a' || c == 'b' || c == 'r')
		ft_printf("rr%c\n", c);
}

void	push(t_stack **push, t_stack **get, char c)
{
	t_stack *temp;

	if(!(*push))
		return ;
	temp = (*push);
	(*push) = (*push)->next;
	if (!(*get))
	{
		(*get) = temp;
		(*get)->next = NULL;
	}
	else
	{
		temp->next = (*get);
		(*get) = temp;
	}
	ft_printf("p%c\n", c);
}