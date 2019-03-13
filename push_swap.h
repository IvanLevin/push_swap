//
// Created by Germaine Kshlerin on 2019-02-26.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define CAP 12
# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdio.h>


typedef struct s_swap
{
	int			*stack_a;
	int 		*stack_b;
	int 		cap[CAP];
	int 		cap_len;
	int 		top_a;
	int 		top_b;
	int 		len;
	int 		len_a;
	int 		len_b;
	int 		pivot;
	int 		score;


}				t_swap;

int				check_valid(int argc, char **argv);
int				check_valid_num(int argc, char **argv);
void			push_swap(int argc, char **argv);
void			algorithm_sort(t_swap *swap);
void			sort_min(t_swap *swap);
void			sort_insert(t_swap *swap);
int 			swap_pivot(t_swap *swap);
int 			swap_quick_sort (t_swap *swap);
int				check_sort(t_swap *swap);
void			sort_print(t_swap *swap);
void			rrr(t_swap *sw_a, t_swap *sw_b);
void			ss(t_swap *swap);
void			pb(t_swap *swap);
void			pa(t_swap *swap);
void			rr(t_swap *sw_a, t_swap *sw_b);
void			rra(t_swap *sw_a);
void			rrb(t_swap *sw_b);
void			sb(t_swap *sw_b);
void			ra(t_swap *sw_a);
void			rb(t_swap *sw_b);
void			sa(t_swap *sw);

#endif
