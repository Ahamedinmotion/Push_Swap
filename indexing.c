#include "push_swap.h"

void	index_stack(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		count;

	i = a;
	while (i)
	{
		count = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}
