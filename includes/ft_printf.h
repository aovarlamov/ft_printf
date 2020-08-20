/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:55:06 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/31 10:38:34 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <inttypes.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_param
{
	int				flag_m;
	int				flag_p;
	int				flag_s;
	int				flag_h;
	int				flag_n;
	size_t			width;
	int				precis;
	char			*modif;
	char			conver;
}					t_param;

int					ft_printf(const char *format, ...);
int					prf_parser(const char *str, va_list ap);
int					prf_check_param(const char *str, int *i);
int					prf_chk_flag(char c);
int					prf_chk_digit(char c);
int					prf_chk_precision(char c);
int					prf_chk_modifier(char c);
int					prf_chk_conversion(char c);
int					prf_writer(const char *str, int count, va_list ap);
t_param				*ft_newparam(const char *str, int count);
int					param_flag_minus(const char *str, int count);
int					param_flag_plus(const char *str, int count);
int					param_flag_space(const char *str, int count);
int					param_flag_hash(const char *str, int count);
int					param_flag_null(const char *str, int count);
int					param_width(const char *str, int count);
int					param_precision(const char *str, int count);
char				*param_modifier(const char *str, int count);
char				param_conversion(const char *str, int count);
int					prf_putparam(t_param *param, va_list ap);
int					prf_putstr(const char *str, int count);
int					print_c(t_param *param, va_list ap);
int					print_c_null(t_param *param, size_t len, char *x);
int					print_s(t_param *param, va_list ap);
int					print_s_null(t_param *param, char *x);
int					print_p(t_param *param, va_list ap);
int					print_d_i(t_param *param, va_list ap);
int					print_d_i_changer(t_param *param, char *x, intmax_t n);
int					print_u(t_param *param, va_list ap);
int					print_u_changer(t_param *param, char *x);
int					print_o(t_param *param, va_list ap);
int					print_o_changer(t_param *param, char *x, uintmax_t n);
int					print_x(t_param *param, va_list ap);
int					print_x_changer(t_param *param, char *x, uintmax_t n);
int					print_bx(t_param *param, va_list ap);
int					print_bx_changer(t_param *param, char *x, uintmax_t n);
int					print_proc(t_param *param);
int					print_f(t_param *param, va_list ap);
int					print_f_changer(t_param *param, char *x);
char				*precision_change(char *x, t_param *param, size_t *len);
char				*precision_change_work(char *x, t_param *param,
					size_t *len);
char				*width_change(char *x, t_param *param, size_t *len);
char				*width_change_left(char *str, char *x, int j);
char				*width_change_right(char *str, char *x, int j,
					t_param *param);
char				*ft_add_h(char *x, t_param *param, size_t *len);
char				*ft_add_0(char *x, t_param *param, size_t *len);
char				*ft_add_point(char *x, t_param *param, size_t *len);
char				*flag_plus_wr(char *x, t_param *param, size_t *len);
char				*flag_space_wr(char *x, t_param *param, size_t *len);
char				*ft_itoa(intmax_t n);
char				*ft_strnchr(const char *str, int to_find, int n);
char				*ft_itoa_unsigned(unsigned long long int n);
char				*ft_itoa_base(unsigned long long value, int base);
char				*ft_itoa_base_low(unsigned long long value, int base);
void				ft_delparam(t_param **param);
char				*ft_ftoa_prf(long double nb, t_param *param);
char				*ft_ftoa_0(uintmax_t ad, int len);
char				*ft_ftoa_m1(long double nb);
uintmax_t			ft_ftoa_ad(long double float_part, uintmax_t *before_dot,
					int len);
char				*ft_ftoa_write(uintmax_t before_dot, uintmax_t after_dot,
					int m, t_param *param);

#endif
