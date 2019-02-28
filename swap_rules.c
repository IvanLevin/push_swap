#include "push_swap.h"

void	sa(t_swap *swap_a)
{
	int		i;
	int 	temp;

	i = 0;
	if (!swap_a->stack_a[i + 1])
		return ;
	temp = swap_a->stack_a[i + 1];
	swap_a->stack_a[i + 1] = swap_a->stack_a[i];
	swap_a->stack_a[i] = temp;
}

void	sb(t_swap *swap_b)
{
	int		i;
	int 	temp;

	if (!(swap_b->stack_b))
		return ;
	i = 0;
	temp = swap_b->stack_b[i + 1];
	swap_b->stack_b[i + 1] = swap_b->stack_b[i];
	swap_b->stack_b[i] = temp;
}

void	ss(t_swap *swap_a, t_swap *swap_b)
{
	int		i;
	int 	temp;

	if (!(swap_a->stack_a))
		return ;
	if (!(swap_b->stack_b))
		return ;
	i = 0;
	temp = swap_a->stack_a[i + 1];
	swap_a->stack_a[i + 1] = swap_a->stack_a[i];
	swap_a->stack_a[i] = temp;
	temp = swap_b->stack_b[i + 1];
	swap_b->stack_b[i + 1] = swap_b->stack_b[i];
	swap_b->stack_b[i] = temp;
}

void	pb(t_swap *swap_a, t_swap *swap_b)
{
	int 	i;

	if (!(swap_a->stack_a))
		return ;
	i = 0;
	swap_b->stack_b[i] = swap_a->stack_a[i];
	swap_b->b_check[i] = 1;
	swap_a->a_check[i] = 0;
}
