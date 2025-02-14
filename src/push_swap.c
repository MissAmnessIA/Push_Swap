#include "../inc/push_swap.h"

int main (int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Wrong format...*-*\n");
		return (1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if(!argv[1])
	{
		free(argv[0]);
		free(argv[1]);
		return (0);
	}
	else
		argv++;
	create_stack_a(argv, &a);
	sort_stacks(&a, &b);

	print_stack(a, 'a');
	print_stack(b, 'b');


	free_stack(b);
	free_stack(a);
	return (0);
}