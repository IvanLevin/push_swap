/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:06:30 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/20 18:17:03 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define CAP 100000
# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdio.h>

typedef struct	s_swap
{
	int			*stack_a;
	int			*stack_b;
	int			cap[CAP];
	int			cap_len;
	int			len;
	int			pivot;
	int			score;
	int			top_b;
	int			len_b;
	int			top_a;
	int			len_a;
	int			check_a;
	int			check;
	int			rec;
	int			swap_len;
	int			flag;
	int			check_len;

}				t_swap;

int				check_valid(int argc, char **argv);
int				check_valid_num(int argc, char **argv);
void			push_swap(int argc, char **argv);
void			algorithm_sort(t_swap *swap);
void			sort_min(t_swap *swap);
void			sort_insert(t_swap *swap);
int				swap_pivot(t_swap *swap);
int				swap_quick_sort (t_swap *swap);
int				check_sort(t_swap *swap);
void			sort_print(t_swap *swap);
void			quick_sort(t_swap *swap);
void			sort_stack_b(t_swap *swap);
void			new_pivot_a(t_swap *swap);
void			pivot_a(t_swap *swap);
void			pivot_b(t_swap *swap);
void			pivot_b_test(t_swap *swap);
int				check_min_elem(t_swap *swap);
void			swap_stack_a(t_swap *swap);
void			sort_stack_a(t_swap *swap);
void			put_stack_b(t_swap *swap);
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
