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


}				t_swap;

int				check_valid(int argc, char **argv);
int				check_valid_num(int argc, char **argv);
void			push_swap(int argc, char **argv);
void			sa(t_swap *swap);
void			sb(t_swap *swap_b);
void			ss(t_swap *swap_a, t_swap *swap_b);
void			pb(t_swap *swap_a, t_swap *swap_b);


#endif
