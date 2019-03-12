#include "push_swap.h"

static void free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
}

static void	initialize_swap(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->len)
	{
		swap->stack_a[i] = 0;
		swap->stack_b[i] = 0;
		i++;
	}
	swap->pivot = 0;
	swap->score = 0;
	swap->top_a = 0;
	swap->len_a = swap->len;
	swap->len_b = 0;
	swap->top_b = swap->len;
}

static	int	mem_allocation(t_swap *swap)
{
	int	i;

	i = 0;
	if(!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_swap	*swap;
	int 	var;
	int 	i;
	int 	j;

	if(!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return ;
	swap->len = argc - 1;
	if (mem_allocation(swap) == -1)
		return ;
	initialize_swap(swap);
	i = 1;
	j = 0;
	while (argv[i])
	{
		var = ft_atoi(argv[i++]);
		swap->stack_a[j++] = var;
	}
	i = 0;
	algorithm_sort(swap);
	free_struct(swap);
}
