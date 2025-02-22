/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:45:46 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/22 17:45:53 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

bool	is_digit_str(char *str)
{
	if (!(*str == '+' || *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (0);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (0);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

bool	is_dup(t_stack *head, int n)
{
	if (stack_len(head) == 1)
		return (0);
	while (head)
	{
		if (head->n == n)
			return (1);
		head = head->next;
	}
	return (0);
}

void	create_stack_a(char **argv, t_stack **a, int is_split)
{
	int				i;
	long long int	n;

	i = 0;
	while (argv[i])
	{
		if (!is_digit_str(argv[i]))
			free_errors(*a, argv, is_split);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(*a, argv, is_split);
		if (is_dup(*a, n))
			free_errors(*a, argv, is_split);
		add_last(a, n);
		i++;
	}
}
