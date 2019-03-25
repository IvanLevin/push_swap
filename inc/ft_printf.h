/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:36:08 by gkshleri          #+#    #+#             */
/*   Updated: 2019/03/25 15:15:32 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PLUS '+'
# define MINUS '-'
# define SPACE ' '
# define LATTICE '#'
# define ZERO '0'
# include "../lib/ft_printf/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_lists
{
	int			dotzero;
	int			zeros;
	int			spaces;
	int			base;
	int			sharp;
	int			len;
	int			minus;
	int			zero;
	char		flag[5];
	int			space;
	int			plus;
	int			width;
	int			precision;
	char		mod;
	char		spec;
	int			dot;
}				t_lists;

int				ft_printf(const char *argv, ...);
char			*parsing(char *argv, va_list ap, t_lists *list);
char			*ft_percent(char *argv, t_lists *list);
char			*ft_flag(char *argv, t_lists *list);
void			search_flag(char *argv, int len, t_lists *list);
char			*ft_width(char *argv, va_list ap, t_lists *list);
char			*ft_accuracy(char *argv, va_list ap, t_lists *list);
char			*ft_modifier(char *argv, t_lists *list);
int				data_types(char *argv, va_list ap, t_lists *list);
void			print_test(char *arr_d, t_lists *list, size_t len);
void			ft_printf_s(char *str, t_lists *list);
int				space_amount(t_lists *list, int len);
void			ft_print_free(char **str, t_lists *list, long long max);
void			ft_printf_c(t_lists *list, va_list ap);
void			d_pars(t_lists *list, char *specifier, va_list ap);
void			u_pars(t_lists *list, char *specifier, va_list ap);
void			print_d_i(t_lists *list, char *arr_d);
void			ft_printf_d_i_u(t_lists *list, char *specifier, va_list ap);
int				fill_zero(char *arr, t_lists *list, char *ap, long long max);
int				flag_width_d(t_lists *list, char *ar1,
					char *ar2, long long len);
int				pr_right_d(char *arr, char *arr2, t_lists *list);
int				pr_left_d(char *arr, char *arr2, t_lists *list);
int				d_min_left(char *arr_1, char *arr_d,
					long long len, t_lists *list);
int				d_min_right(char *arr_1, char *arr_d,
					long long len, t_lists *list);
char			*ft_itoa_long(__int128_t n);
char			*ft_itoa_base(unsigned long long int i, int base);
void			ft_printf_p(t_lists *list, long long ap);
int				fill_space_x(int space, char *tmp, int tmp_i);
void			ft_printf_x(unsigned long long n, t_lists *list);
void			ft_printf_f(t_lists *list, long double n);
int				ft_len(__int128_t n);
int				fill_zeros(int zeros, char *tmp, int tmp_i);
int				zeros_amount_x(t_lists *list, int len);
int				space_amount_x(char *str, t_lists *list, int len);
int				fill_sharp(char *tmp, int tmp_i, t_lists *list, int base);
void			ft_print_free2(char *str, t_lists *list, long long max);
int				space_amount_f(t_lists *list, int len, long minus);

#endif
