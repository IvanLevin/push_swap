//
// Created by Germaine Kshlerin on 2019-02-26.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_swap
{
	char        **cmds;
	int         temp_cmd;
	int			*stack_a;
	int 		*stack_b;
    int         *uns_mas;
	int 		top_a;
	int 		top_b;
	int 		len;
	int 		pivot;
	int 		score;
    int         min;
    int         max;
    int         temp;
    int         unsorted;
    int         sorted;
	int         checker;
	int         flag;
	int         flag_v;
}				t_swap;

int 		    mem_allocation(t_swap *swap);
int				check_valid(int argc, char **argv);
int				check_valid_num(int argc, char **argv);
void			push_swap(int argc, char **argv);
void			algorithm_sort(t_swap *swap);
void			sort_min(t_swap *swap);
void			sort_insert(t_swap *swap);
int 			swap_pivot(t_swap *swap);
int 			swap_quick_sort (t_swap *swap);
int				check_sort(t_swap *swap);
void			rrr(t_swap *sw_a, t_swap *sw_b);
void			ss(t_swap *swap);
void			pb(t_swap *swap);
void			pa(t_swap *swap);
void			rr(t_swap *swap);
void			rra(t_swap *sw_a);
void			rrb(t_swap *sw_b);
void			sb(t_swap *sw_b);
void			ra(t_swap *sw_a);
void			rb(t_swap *sw_b);
void			sa(t_swap *sw);
int             check_splitted(t_swap *swap);
void            print_stacks(t_swap *swap);
void            new_pivot(t_swap *swap);
int             split_stacks_tob(t_swap *swap);
void            split_stacks_toa(t_swap *swap);
int             split_stacks_toa2(t_swap *swap);
int          	num_of_covers(t_swap *swap);
void            new_pivot_b(t_swap *swap);
void            new_pivot_a(t_swap *swap);
int             check_sorted(t_swap *swap);
void            sort_a(t_swap *swap);
void            split_stack_b(t_swap *swap);
void            sort_toa(t_swap *swap);
void            put_b(t_swap *swap);
int             b_del(t_swap *swap);
void            sort_toa2(t_swap *swap);
void            find_max_min(t_swap *swap);
t_swap			*push_check(int argc, char **argv);
void			free_struct_check(t_swap *swap);
void			sort_toa3(t_swap *swap);
int				check_elems_down(t_swap *swap, int i);
void			split_stacks_toa_add(t_swap *swap);
void			free_struct(t_swap *swap);

#endif
