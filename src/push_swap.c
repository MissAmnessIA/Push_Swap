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
	char	**args;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (-1);
	args = check_args(argv, argc);
	create_stack_a(&a, args);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	if (!a)
		ft_error("Error");
	sort_stacks(&a, &b);
	free_stack(a);
	return (0);
}
