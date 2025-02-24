/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:47:33 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/22 17:47:36 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	is_empty(char **argv)
{
	int i;
	int j;
	int	is_n;

	i = 0;
	j = 0;
	while (argv[i])
	{
		is_n = 1;
		while (argv[i][j])
		{
			if (!argv[i][j])
				return (1);
			if (ft_isdigit(argv[i][j]))
				is_n = 1;
			j++;
		}
		if (is_n == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		is_split;

	a = NULL;
	b = NULL;
	is_split = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Wrong format...*-*\n");
		return (1);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		is_split = 1;
	}
	else
		argv++;
	if (is_empty(argv))
		free_errors(NULL, argv, is_split);
	create_stack_a(argv, &a, is_split);
	if (is_split)
		free_split(argv);
	sort_stacks(&a, &b);
	free_stack(a);
	return (0);
}
