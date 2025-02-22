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
	create_stack_a(argv, &a, is_split);
	if (is_split)
		free_split(argv);
	sort_stacks(&a, &b);
	free_stack(a);
	return (0);
}
