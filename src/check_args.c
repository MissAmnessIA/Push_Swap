/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:53:01 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/25 20:53:04 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	its_ok(char **args, int argc)
{
	int		i;
	long	temp;

	i = 0;
	if (argc != 2)
		i = 1;
	while (args[i])
	{
		ft_printf("%s\n", args[i]);
		if (!is_num(args[i]))
			ft_error("Error");
		temp = ft_atoi(args[i]);
		if (ft_contains(temp, args, i) || temp < INT_MIN
			|| temp > INT_MAX)
			ft_error("Error");
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error("Error");
	}
	else
		args = argv;
	its_ok(args, argc);
	if (argc == 2)
		free_split(args);
}
