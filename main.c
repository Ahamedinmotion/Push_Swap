#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	if (!is_sorted(a))
	{
		index_stack(a);
		if (stack_size(a) <= 5)
			sort_small(&a, &b);
		else
			sort_chunk(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
