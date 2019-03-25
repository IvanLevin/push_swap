#include "../../inc/push_swap.h"

void			initialize_check(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->len)
	{
		swap->stack_a[i] = 0;
		swap->stack_b[i] = 0;
		i++;
	}
	i = 0;
	while (i < 100000)
		swap->cap[i++] = 0;
}

int rule_checking(t_swap *swap, char *line)
{
	if (ft_strequ(line, "pa"))
		pa(swap);
	else if (ft_strequ(line, "pb"))
		pb(swap);
//	else if (ft_strequ(line, "rra"))
//		rra(swap);
//	else if (ft_strequ(line, "rrb"))
//		rrb(swap);
	else if (ft_strequ(line, "sb"))
		sb(swap);
	else if (ft_strequ(line, "ra"))
		ra(swap);
//	else if (ft_strequ(line, "rb"))
//		rb(swap);
//	else if (ft_strequ(line, "ss"))
//		ss(swap);
//	else if (ft_strequ(line, "rrr"))
//		rrr(swap, swap);
//	else if (ft_strequ(line, "rr"))
//		rr(swap, swap);
	else if (ft_strequ(line, "sa"))
		sa(swap);
	else
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_swap *swap;
	char *line;

	swap = NULL;
	initialize_check(swap);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break;
		if (!(rule_checking(swap, line)))
		{


		}
	}

//	if (check_valid(argc, argv) == -1)
//	{
//		ft_putendl("\e[0;31mError");
//		return (-1);
//	}
//	if (check_valid_num(argc, argv) == -1)
//	{
//		ft_putendl("\e[0;31mError");
//		return (-1);
//	}
	return (0);
}


