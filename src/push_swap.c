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

void	create_stack_a(t_stack **a, int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		add_last(a, ft_atoi(args[i]));
		i++;
	}
	if (argc == 2)
		free_split(args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	a = NULL;
	b = NULL;
	create_stack_a(&a, argc, argv);
	if (is_sorted(a))
	{
		free_stack(a);
		ft_printf("Hola");
		return (0);
	}
	if (!a)
	{
		ft_error("Error");
		free_stack(a);
		return (0);
	}
	sort_stacks(&a, &b);
	print_stack(a);
	free_stack(a);
	return (0);
}
