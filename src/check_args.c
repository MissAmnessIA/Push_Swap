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

void    is_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ' 
			&& str[i] != '-' && str[i] != '+')
            ft_error("No digit\n");
        i++;
    }
}
void    check_digits(char *str)
{
    int i;
    int find_n;

    i = 0;
    find_n = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
            find_n = 1;
        i++;
    }
    if (find_n == 0)
    {
        ft_printf("Wrong argument\n");
        exit(1);
    }
}
char    *join_args(int argc, char **argv)
{
    char *joined;
    char *temp;
    int i;

    i = 1;
    if (argc == 2)
        joined = ft_strdup(argv[1]);
    else
    {
        joined = (char *)malloc(sizeof(char *));
        while (argv[i])
        {
            temp = joined;
            joined = ft_strjoin(temp, argv[i]);
            if (temp)
                free(temp);
            temp = joined;
            joined = ft_strjoin(temp, " ");
            free(temp);
            i++;
        }
    }
    return (joined);
}
char	**check_args(char **argv, int argc)
{
	char *joined;
    char **splited;

	int i;

    i = 1;
    while (argv[i])
    {
        if (ft_strlen(argv[i]) == 0)
        {
            ft_printf("Is empty\n");
            exit(1);
        }
        is_digit(argv[i]);
        check_digits(argv[i]);
        i++;
    }
    joined = join_args(argc, argv);
    splited = ft_split(joined, ' ');
	free(joined);
	return (splited);
}
