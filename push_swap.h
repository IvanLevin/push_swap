//
// Created by Germaine Kshlerin on 2019-02-26.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_swap
{
	int			*stack_a;
	int 		*stack_b;
	int 		*a_check;
	int 		*b_check;
	int 		len;


}				t_swap;

int				check_valid(int argc, char **argv);
int				check_valid_num(int argc, char **argv);
void			push_swap(int argc, char **argv);
void			sa(t_swap *sw);
void			sb(t_swap *sw_b);
void			ss(t_swap *sw_a, t_swap *sw_b);
void			pb(t_swap *sw_a, t_swap *sw_b);
void			pa(t_swap *sw_a, t_swap *sw_b);
void			ra(t_swap *sw_a);
void			rb(t_swap *sw_b);
void			rr(t_swap *sw_a, t_swap *sw_b);
void			rra(t_swap *sw_a);

#endif
