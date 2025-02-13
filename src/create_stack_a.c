#include "../inc/push_swap.h"
bool	is_digit_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
	}
	return (1);
}

bool	is_dup(t_stack *head, int n)
{
	while (head)
	{
		if (head->n == n)
			return (1);
		head = head->next;
	}
	return (0);
}

void	create_stack_a(char **argv, t_stack **a)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		if (!is_digit_str(argv[i]))
			free_errors(*a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(*a);
		if(is_dup(*a, n))
			free_errors(*a);
		add_last(a, n);
		i++;
	}
}