#include "push_swap.h"

static	int	mem_allocation(t_swap *swap)
{
	int	i;

	i = 0;
	if(!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->a_check = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->b_check = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	while (swap->len > i)
		swap->a_check[i++] = 1;
	i = 0;
	while (swap->len > i)
		swap->b_check[i++] = 0;
	ft_bzero(swap->stack_b, (size_t)swap->len);
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
	i = 1;
	j = 0;
	while (argv[i])
	{
		var = ft_atoi(argv[i++]);
		swap->stack_a[j++] = var;
	}
	rra(swap);
	int b = 0;
	while (b < j)
		printf("%d ", swap->stack_a[b++]);

}
