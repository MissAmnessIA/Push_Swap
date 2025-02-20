#include "../inc/push_swap.h"

void	free_errors(t_stack *head, char **argv, int is_split)
{
	if (head)
		free_stack(head);
	if (is_split)
		free_split(argv);
	ft_printf("Wrong format...*-*\n");
	exit(1);
}

bool	is_sorted(t_stack *head)
{
	t_stack	*next;

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

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
