#include "../inc/push_swap.h"

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_num(char *num)
{
	int i;

	i = 0;
	if(num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	temp;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error("Error");
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (!is_num(args[i]))
			ft_error("Error");
		temp = ft_atoi(args[i]);
		if (ft_contains(temp, args, i))
			ft_error("Error");
		if (temp < INT_MIN || temp > INT_MAX)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		free_split(args);
}
