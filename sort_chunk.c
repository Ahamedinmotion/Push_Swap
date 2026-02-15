#include "push_swap.h"

static int	get_max_index(t_node *b)
{
	int	max;

	if (!b)
		return (-1);
	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static int	get_pos(t_node *b, int index)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == index)
			return (i);
		i++;
		b = b->next;
	}
	return (0);
}

void	sort_chunk(t_node **a, t_node **b)
{
	int	size;
	int	chunk;
	int	i;

	size = stack_size(*a);
	chunk = (size <= 100) ? 15 : 30;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
	{
		i = get_max_index(*b);
		if (get_pos(*b, i) <= stack_size(*b) / 2)
			while ((*b)->index != i)
				rb(b);
		else
			while ((*b)->index != i)
				rrb(b);
		pa(a, b);
	}
}
