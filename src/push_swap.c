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
	create_stack_a(argv, &a);
	if (is_split)
		free_split(argv);
	sort_stacks(&a, &b);
	free_stack(a);
	return (0);
}
