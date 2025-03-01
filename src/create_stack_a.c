#include "../inc/push_swap.h"

long	ft_atol(char *nptr)
{
	long	i;
	int			neg;

	i = 0;
	neg = 1;
	while (ft_isspace ((unsigned char)*nptr))
		nptr++;
	if ((unsigned char)*nptr == '-' || (unsigned char)*nptr == '+')
	{
		if ((unsigned char)*nptr == '-')
			neg *= -1;
		nptr++;
	}
	if (!ft_isdigit((unsigned char)*nptr))
		return (INT_MAX);
	while (ft_isdigit((unsigned char)*nptr))
	{
		i += ((unsigned char)*nptr - 48);
		i *= 10;
		nptr++;
	}
	return (i / 10 * neg);

}
int	is_dup(int n, t_stack *a)
{
	while (a)
	{
		if (n == a->n)
			return (1);
		a = a->next;
	}
	return (0);
}
void	create_stack_a(t_stack **a, char **argv)
{
	int		i;
	long temp;

	i = 0;
	while (argv[i])
	{
		temp = ft_atol(argv[i]);
		if (is_dup(temp, *a) || temp > INT_MAX || temp < INT_MIN)
		{
			free_stack(*a);
			free_split(argv);
			ft_error("Wrong numbers");
		}
		add_last(a, ft_atoi(argv[i]));
		i++;
	}
	free_split(argv);
}