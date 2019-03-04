#include "push_swap.h"

void	sa(t_swap *sw_a)
{
	int		i;
	int 	temp;

	i = 0;
	if (!sw_a->a_check[i + 1])
		return ;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
	sw_a->score++;
	ft_printf("sa\n");
}

void	sb(t_swap *sw_b)
{
	int		i;
	int 	temp;

	if (!(sw_b->b_check))
		return ;
	i = 0;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	ft_printf("sb\n");
}

void	ss(t_swap *sw_a, t_swap *sw_b)
{
	int		i;
	int 	temp;

	if (!(sw_a->a_check))
		return ;
	if (!(sw_b->b_check))
		return ;
	i = 0;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
	sw_a->score++;
	ft_printf("ss\n");
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
	sw_a->score++;
	ft_printf("pa\n");
}

void	pb(t_swap *sw_a, t_swap *sw_b)
{
	int	i;

	if (!(sw_a->a_check))
		return ;
	i = 0;
	sw_b->stack_b[i] = sw_a->stack_a[i];
	sw_b->b_check[i] = 1;
	sw_a->a_check[i] = 0;
	sw_a->score++;
	ft_printf("pb\n");
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
	sw_a->score++;
	ft_printf("ra\n");
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
	sw_b->score++;
	ft_printf("rb\n");
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
	sw_a->score++;
	ft_printf("rr\n");
}

void	rra(t_swap *sw_a)
{
	int i;
	int temp;

	i = 1;
	temp = sw_a->stack_a[sw_a->len - 1];
	while (sw_a->len > i)
	{
		sw_a->stack_a[sw_a->len - i] = sw_a->stack_a[sw_a->len - i - 1];
		i++;
	}
	sw_a->stack_a[sw_a->len - i] = temp;
	sw_a->score++;
	ft_printf("rra\n");
}

void	rrb(t_swap *sw_b)
{
	int i;
	int temp;

	i = 1;
	temp = sw_b->stack_b[sw_b->len - 1];
	while (sw_b->len > i)
	{
		sw_b->stack_b[sw_b->len - i] = sw_b->stack_a[sw_b->len - i - 1];
		i++;
	}
	sw_b->stack_b[sw_b->len - i] = temp;
	sw_b->score++;
	ft_printf("rrb\n");
}

void	rrr(t_swap *sw_a, t_swap *sw_b)
{
	int i;
	int temp;

	i = 1;
	temp = sw_a->stack_a[sw_a->len - 1];
	while (sw_a->len > i)
	{
		sw_a->stack_a[sw_a->len - i] = sw_a->stack_a[sw_a->len - i - 1];
		i++;
	}
	sw_a->stack_a[sw_a->len - i] = temp;
	i = 1;
	temp = sw_b->stack_b[sw_b->len - 1];
	while (sw_b->len > i)
	{
		sw_b->stack_b[sw_b->len - i] = sw_b->stack_a[sw_b->len - i - 1];
		i++;
	}
	sw_b->stack_b[sw_b->len - i] = temp;
	sw_a->score++;
	ft_printf("rrr\n");
}
