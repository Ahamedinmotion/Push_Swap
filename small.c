#include "push_swap.h"

static void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return ;
	}
	while (size > 3)
	{
		if ((*a)->index <= 1)
		{
			pb(a, b);
			size--;
		}
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->next && (*a)->index > (*a)->next->index)
			sa(a);
	}
}

