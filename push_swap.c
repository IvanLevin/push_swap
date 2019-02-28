#include "push_swap.h"

static	int	mem_allocation(t_swap *swap, int argc)
{
	int	i;

	i = 0;
	if(!(swap->stack_a = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	if(!(swap->stack_b = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	if(!(swap->a_check = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	if(!(swap->b_check = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	while (argc - 1 > i)
		swap->a_check[i++] = 1;
	i = 0;
	while (argc - 1 > i)
		swap->b_check[i++] = 0;
	ft_bzero(swap->stack_b, (size_t)argc - 1);
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
	if (mem_allocation(swap, argc) == -1)
		return ;
	i = 1;
	j = 0;
	while (argv[i])
	{
		var = ft_atoi(argv[i++]);
		swap->stack_a[j++] = var;
	}
	int b = 0;
	while (b < j)
		printf("%d ", swap->stack_a[b++]);

}
