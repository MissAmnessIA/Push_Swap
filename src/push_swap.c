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
	else
		argv++;
	create_stack_a(argv, &a);
	sort_stacks(&a, &b);




	t_stack *temp;
	temp = a;
	ft_printf("Stack a:\n");
	while (temp)
	{
		ft_printf("%i\n", temp->n);
		temp = temp->next;
	}
	temp = b;
	ft_printf("Stack b:\n");
	while (temp)
	{
		ft_printf("%i\n", temp->n);
		temp = temp->next;
	}


	free_stack(b);
	free_stack(a);
	return (0);
}