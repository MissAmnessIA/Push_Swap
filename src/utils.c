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

long	ft_atol(const char *nptr)
{
	long long	i;
	int			neg;

	i = 0;
	neg = 1;
	if ((unsigned char)*nptr == '-' || (unsigned char)*nptr == '+')
	{
		if ((unsigned char)*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while ((unsigned char)*nptr)
	{
		i += ((unsigned char)*nptr - 48);
		i *= 10;
		nptr++;
	}
	return (i / 10 * neg);
}

//utils tests

void	print_stack(t_stack *head, char c)
{
	ft_printf("Stack %c:\n", c);
	while (head)
	{
		ft_printf("%i\n", head->n);
		head = head->next;
	}
}