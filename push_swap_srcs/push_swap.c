#include "../include/push_swap.h"

static void free_struct(t_swap *swap)
{
	free(swap->stack_a);
	free(swap->stack_b);
	free(swap->uns_mas);
}

static void	initialize_swap(t_swap *swap)
{
	int i;

	i = 0;
	while (i < num_of_covers(swap))
		swap->uns_mas[i++] = 0;
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
	swap->top_b = swap->len;
	swap->max = 0;          // минимальное число для сортировки
	swap->min = 0;          // максимальное число для сортировки// минимальный элемент в стеке А, который не трогаем
	swap->temp = 2;
	swap->len_min = 0;      // расстояние до вершины стека минимального элемента
	swap->len_max = 0;      //  расстояние до вершины стека максимального элемента
    swap->unsorted = 0;
    swap->way = -1;         // направление сортировки (вверх == -1, вниз == 1)
	swap->sorted = 0;
}

static	int	mem_allocation(t_swap *swap)
{
	int	i;

	i = 0;

	if(!(swap->stack_a = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->stack_b = (int *)malloc(sizeof(int) * swap->len)))
		return (-1);
	if(!(swap->uns_mas = (int *)malloc(sizeof(int) * num_of_covers(swap))))
		return (-1);
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_swap	*swap;
	int 	var;
	int 	i;
	int 	j;

	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
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
	algorithm_sort(swap);
	free_struct(swap);
	free(swap);
}
