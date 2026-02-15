#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int		parse_args(int ac, char **av, t_node **a);

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);


void	free_stack(t_node **stack);

void	index_stack(t_node *stack);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

char	**ft_split(char const *s, char c);
void	free_split(char **split);

void	sort_small(t_node **a, t_node **b);
void	sort_chunk(t_node **a, t_node **b);

#endif
