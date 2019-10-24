/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 07:53:23 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 14:20:11 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define CONVERSIONS "cCsSpdDiIoOuUxX"
# define FLAGS "hlLjz +-#.0123456789z"

typedef struct	s_printf
{
	char		letter;
	int			fieldwidth;
	int			zero;
	int			minus;
	int			space;
	int			plus;
	int			alternate;
	int			precision;
	int			l;
	int			big_l;
	int			h;
	int			j;
	int			z;
	char		*result;
	int			ret;
	int			retnew;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		*init_conv(void);
int				ft_add_result(char c, t_printf *conv, int p);
int				clean_result(t_printf *conv);

char			*ft_strnjoin(char *s1, char *s2, int l1, int l2);

char			*ft_itoa_base(long long n, int base, int capital);
int				ft_digits_base(long long n, int base);
char			*ft_capital(char *ret, int capital);

char			*ft_utoa_base(unsigned long long n, int base, int capital);
int				ft_udigits_base(unsigned long long n, int base);
char			*ft_uimtoa_base(uintmax_t n, int base, int capital);
int				ft_uimdigits_base(uintmax_t n, int base);

int				conversionist(char *form, int i, t_printf *c, va_list args);
t_printf		*set_to_zero(t_printf *conv);
int				ft_set_flags(char *flags, t_printf *conv, int i);
int				ft_set_flags2(char *flags, t_printf *conv);

void			ft_make_conversion(t_printf *conv, void *input);
void			ft_make_f_conversion(t_printf *conv, double input);
void			ft_no_conversion(t_printf *conv, char c);

char			*c_conversion(unsigned char c, t_printf *conv);
char			*s_conversion(char *src, t_printf *conv);
char			*p_conversion(unsigned long n, t_printf *conv, int capital);

char			*di_conversion(void *input, t_printf *conv);
char			*ft_make_space_plus(char *str, t_printf *conv);

char			*o_conversion(void *input, t_printf *conv);
char			*u_conversion(void *input, t_printf *conv);
char			*x_conversion(void *input, t_printf *conv, int capital);

char			*f_conversion(long double number, t_printf *conv);
char			*ft_get_dec(long double nbr, t_printf *conv, char *ret);
void			ft_fix_dec(char *ret, int i);

char			*make_precision(char *str, t_printf *conv);
char			*make_padding(char *str, t_printf *conv);
void			ft_fix_precision(char *news, t_printf *conv);
void			ft_fix_padding(char *news, t_printf *conv);

void			ft_del_two(char *s1, char *s2);
int				prec_exception(t_printf *conv);

#endif
