#include "../include/push_swap.h"

void	sa(t_swap *sw_a)
{
	int		i;
	int 	temp;

	i = sw_a->top_a;
	if (sw_a->len - sw_a->top_a <= 1)
		return ;
	temp = sw_a->stack_a[i + 1];
	sw_a->stack_a[i + 1] = sw_a->stack_a[i];
	sw_a->stack_a[i] = temp;
	sw_a->score++;
	ft_printf("sa\n");
//    print_stacks(sw_a);
}

void	sb(t_swap *sw_b)
{
	int		i;
	int 	temp;

	if (sw_b->len - sw_b->top_b <= 1)
		return ;
	i = sw_b->top_b;
	temp = sw_b->stack_b[i + 1];
	sw_b->stack_b[i + 1] = sw_b->stack_b[i];
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	ft_printf("sb\n");
//    print_stacks(sw_b);
}

void	ss(t_swap *swap) // ИСПРАВИТЬ!!!
{
	int		i;
	int 	temp;

	if (swap->len - swap->top_a <= 1)
		return ;
	if (swap->len - swap->top_b <= 1)
		return ;
	i = 0;
	temp = swap->stack_a[i + 1];
	swap->stack_a[i + 1] = swap->stack_a[i];
	swap->stack_a[i] = temp;
	temp = swap->stack_b[i + 1];
	swap->stack_b[i + 1] = swap->stack_b[i];
	swap->stack_b[i] = temp;
	swap->score++;
	ft_printf("ss\n");
//    print_stacks(swap);
}

void	pa(t_swap *swap)
{
	if (swap->len - swap->top_b == 0)
		return ;
	swap->top_a--;
	swap->stack_a[swap->top_a] = swap->stack_b[swap->top_b];
	swap->score++;
	swap->top_b++;
	ft_printf("pa\n");
//    print_stacks(swap);
}

void	pb(t_swap *swap)
{
	if (swap->len - swap->top_a <= 0)
		return ;
	swap->stack_b[swap->top_b - 1] = swap->stack_a[swap->top_a];
	swap->score++;
	swap->top_a++;
	swap->top_b--;
	ft_printf("pb\n");
//    print_stacks(swap);
}

void	ra(t_swap *sw_a)
{
	int 	i;
	int 	temp;

	i = sw_a->top_a;
	temp = sw_a->stack_a[i];
	while (sw_a->len - 1 > i)
	{
		sw_a->stack_a[i] = sw_a->stack_a[i + 1];
		i++;
	}
	sw_a->stack_a[i] = temp;
	sw_a->score++;
	ft_printf("ra\n");
//    print_stacks(sw_a);
}

void	rb(t_swap *sw_b)
{
	int 	i;
	int 	temp;

	i = sw_b->top_b;
	temp = sw_b->stack_b[i];

	while (sw_b->len - 1 > i)
	{
		sw_b->stack_b[i] = sw_b->stack_b[i + 1];
		i++;
	}
	sw_b->stack_b[i] = temp;
	sw_b->score++;
	ft_printf("rb\n");
//    print_stacks(sw_b);
}

void	rr(t_swap *swap) // ПЕРЕДЕЛАТЬ!!!
{
	int 	i;
	int     j;
	int 	temp1;
	int     temp2;

	i = swap->top_a;
	j = swap->top_b;
	temp1 = swap->stack_a[i];
	temp2 = swap->stack_b[j];
	while (swap->len - 1 > i)
	{
        swap->stack_a[i] = swap->stack_a[i + 1];
		i++;
	}
	while (swap->len - 1 > j)
	{
		swap->stack_b[j] = swap->stack_b[j + 1];
		j++;
	}
    swap->stack_a[i] = temp1;
	swap->stack_b[j] = temp2;
	swap->score++;
	ft_printf("rr\n");
//    print_stacks(swap);
}

void	rra(t_swap *sw_a) // ПЕРЕДЕЛАТЬ!!!
{
	int i;
	int temp;

	i = 1;
	temp = sw_a->stack_a[sw_a->len - 1];
	while (sw_a->len - sw_a->top_a > i)
	{
		sw_a->stack_a[sw_a->len - i] = sw_a->stack_a[sw_a->len - i - 1];
		i++;
	}
	sw_a->stack_a[sw_a->len - i] = temp;
	sw_a->score++;
	ft_printf("rra\n");
//    print_stacks(sw_a);
}

void	rrb(t_swap *sw_b)
{
	int i;
	int temp;

	i = 1;
	temp = sw_b->stack_b[sw_b->len - 1];
	while (sw_b->len - sw_b->top_b > i)
	{
		sw_b->stack_b[sw_b->len - i] = sw_b->stack_b[sw_b->len - i - 1];
		i++;
	}
	sw_b->stack_b[sw_b->top_b] = temp;
	sw_b->score++;
	ft_printf("rrb\n");
//    print_stacks(sw_b);
}

void	rrr(t_swap *sw_a, t_swap *sw_b) // ПЕРЕДЕЛАТЬ!!!
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
//    print_stacks(sw_a);
}
