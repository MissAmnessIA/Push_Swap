/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:49:17 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/22 17:49:21 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

bool	is_sorted(t_stack *head)
{
	t_stack	*next;

	if (head)
	{
		while (head->next)
		{
			next = head->next;
			if (next->n < head->n)
				return (0);
			head = head->next;
		}
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	print_stack(t_stack *head)
{
	if (head)
	{
		while (head)
		{
			ft_printf("%i\n", head->n);
			head = head->next;
		}
	}
}
