#include "push_swap.h"

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	add_number(t_node **a, char *str)
{
	long	n;
	t_node	*node;

	if (!is_number(str))
		return (0);
	n = atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	if (has_duplicate(*a, (int)n))
		return (0);
	node = new_node((int)n);
	if (!node)
		return (0);
	add_back(a, node);
	return (1);
}

int	parse_args(int ac, char **av, t_node **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split || !split[0])
			return (0);
		j = 0;
		while (split[j])
		{
			if (!add_number(a, split[j]))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		return (1);
	}
	while (i < ac)
	{
		if (!add_number(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}
