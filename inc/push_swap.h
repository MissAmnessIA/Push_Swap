/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:53:32 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/25 20:53:36 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				n;
	int				index;
	struct s_stack	*target_node;
	int				cost;
	bool			mid;
	bool			cheapest;
	struct s_stack	*next;
}				t_stack;

//create stack_a
void	create_stack_a(t_stack **a, int argc, char **argv);

//check args
void	ft_check_args(int argc, char **argv);
int		is_num(char *num);
int		ft_contains(int num, char **argv, int i);
void	its_ok(char **args, int argv);

//sort stacks
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	pass_a_to_b(t_stack **a, t_stack **b);
void	pass_b_to_a(t_stack **a, t_stack **b);
void	prepare_to_push(t_stack **head, t_stack **target, char ch, char ct);

//set values
void	set_values(t_stack *head1, t_stack *head2);
void	set_cheapest(t_stack *head);
void	set_index(t_stack *head);
void	set_cost(t_stack *node, t_stack *target);

//target node
void	get_target_node_a(t_stack *a, t_stack *b);
void	get_target_node_b(t_stack *a, t_stack *b);

//moves
void	swap(t_stack **head, t_stack **head2, char c);
void	rotate(t_stack **head, t_stack **head2, char c);
void	rrotate(t_stack **head, t_stack **head2, char c);
void	push(t_stack **push, t_stack **get, char c);
void	min_on_top(t_stack **a);

//get nodes
t_stack	*get_max(t_stack *head);
t_stack	*get_min(t_stack *head);
t_stack	*get_cheapest(t_stack *head);
t_stack	*get_last_node(t_stack *head);

//utils
void	free_errors(t_stack *head, char **argv);
void	free_split(char **str);
bool	is_sorted(t_stack *head);
void	ft_error(char *str);

void	print_stack(t_stack *head);

//utils list
void	free_stack(t_stack *head);
void	add_last(t_stack **head, int n);
int		stack_len(t_stack *head);
void	target_on_top(t_stack **head, t_stack *target, char c_head);
void	cheapest_on_top(t_stack **head, char c_head);

#endif
