#include "push_swap.h"

void	sa(t_swap *sw_a)
{
	int		i;
	int 	temp;

	i = 0;
	if (!sw_a->stack_a[i + 1])
		return ;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
}

void	sb(t_swap *sw_b)
{
	int		i;
	int 	temp;

	if (!(sw_b->stack_b))
		return ;
	i = 0;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
}

void	ss(t_swap *sw_a, t_swap *sw_b)
{
	int		i;
	int 	temp;

	if (!(sw_a->stack_a))
		return ;
	if (!(sw_b->stack_b))
		return ;
	i = 0;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
}

void	pa(t_swap *sw_a, t_swap *sw_b)
{
	int i;

	i = 0;
	if (sw_b->b_check[i] == 0)
		return ;
	sw_a->stack_a[i] = sw_b->stack_b[i];
	sw_a->a_check[i] = 1;
	sw_b->b_check[i] = 0;
}

void	pb(t_swap *sw_a, t_swap *sw_b)
{
	int	i;

	if (!(sw_a->stack_a))
		return ;
	i = 0;
	sw_b->stack_b[i] = sw_a->stack_a[i];
	sw_b->b_check[i] = 1;
	sw_a->a_check[i] = 0;
}

void	ra(t_swap *sw_a)
{
	int 	i;
	int 	temp;

	i = 0;
	temp = sw_a->stack_a[i];

	while (sw_a->len - 1 > i)
	{
		sw_a->stack_a[i] = sw_a->stack_a[i + 1];
		i++;
	}
	sw_a->stack_a[i] = temp;
}

void	rb(t_swap *sw_b)
{
	int 	i;
	int 	temp;

	i = 0;
	temp = sw_b->stack_b[i];

	while (sw_b->len - 1 > i)
	{
		sw_b->stack_b[i] = sw_b->stack_b[i + 1];
		i++;
	}
	sw_b->stack_b[i] = temp;
}

void	rr(t_swap *sw_a, t_swap *sw_b)
{
	int 	i;
	int 	temp;

	i = 0;
	temp = sw_b->stack_b[i];

	while (sw_b->len - 1 > i)
	{
		sw_b->stack_b[i] = sw_b->stack_b[i + 1];
		i++;
	}
	sw_b->stack_b[i] = temp;
	i = 0;
	temp = sw_a->stack_a[i];
	while (sw_a->len - 1 > i)
	{
		sw_a->stack_a[i] = sw_a->stack_a[i + 1];
		i++;
	}
	sw_a->stack_a[i] = temp;
}

//void	rra(t_swap *sw_a)
//{
//	int 	i;
//	int 	temp;
//
//	i = 0;
//	temp = sw_a->stack_a[i];
//	sw_a->stack_a[i++] = sw_a->stack_a[sw_a->len - 1];
//	sw_a->stack_a[i] = temp;
////	while (sw_a->len - 1 > i)
////	{
////		sw_a->stack_a[i] =
////
////	}
//}