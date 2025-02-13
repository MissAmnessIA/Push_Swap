#include "../inc/push_swap.h"

void	free_errors(t_stack *head)
{
	if(head)
		free_stack(head);
	ft_printf("Wrong format...*-*\n");
	exit(1);
}

bool	is_sorted(t_stack *head)
{
	t_stack *next;

	while (head->next)
	{
		next = head->next;
		if (next->n < head->n)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ncompare_m(int i, int j)
{
	if (i > j)
		return (i);
	else
		return(j);
}