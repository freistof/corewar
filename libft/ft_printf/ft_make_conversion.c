/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_conversion.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 08:35:07 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 11:45:52 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_del_two(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

static int		check_exception(t_printf *conv, char *str)
{
	if ((ft_strchr("pP", conv->letter)) && conv->precision < conv->retnew)
		return (1);
	if (ft_strchr("sScC", conv->letter))
		return (1);
	if (!ft_strequ(str, "0") && ft_strchr("di", conv->letter) \
							&& conv->precision == 0)
		return (1);
	return (0);
}

void			ft_make_f_conversion(t_printf *conv, double input)
{
	char	*str;
	char	*temp;

	if (conv->big_l)
		str = f_conversion(input, conv);
	else if (conv->l)
		str = f_conversion((double)input, conv);
	else
		str = f_conversion(input, conv);
	if (conv->fieldwidth)
		str = make_padding(str, conv);
	temp = ft_strnjoin(conv->result, str, conv->ret, conv->retnew);
	free(conv->result);
	free(str);
	conv->result = temp;
	conv->ret += conv->retnew;
}

void			ft_make_conversion(t_printf *conv, void *input)
{
	char	*str;
	char	*temp;

	if (conv->letter == 'c' || conv->letter == 'C')
		str = c_conversion((unsigned char)input, conv);
	if (conv->letter == 's' || conv->letter == 'S')
		str = s_conversion(input, conv);
	if (conv->letter == 'p')
		str = p_conversion((unsigned long)input, conv, 0);
	if (ft_strchr("DdIi", conv->letter))
		str = di_conversion(input, conv);
	if (conv->letter == 'o' || conv->letter == 'O')
		str = o_conversion(input, conv);
	if (conv->letter == 'u' || conv->letter == 'U')
		str = u_conversion(input, conv);
	if (conv->letter == 'x' || conv->letter == 'X')
		str = x_conversion((uintmax_t *)input, conv, 0);
	if (conv->precision >= 0 && !check_exception(conv, str))
		str = make_precision(str, conv);
	if (conv->fieldwidth)
		str = make_padding(str, conv);
	temp = ft_strnjoin(conv->result, str, conv->ret, conv->retnew);
	ft_del_two(str, conv->result);
	conv->result = temp;
	conv->ret += conv->retnew;
}

void			ft_no_conversion(t_printf *conv, char c)
{
	char	*str;
	char	*temp;

	str = c_conversion((unsigned char)c, conv);
	str = make_padding(str, conv);
	temp = ft_strnjoin(conv->result, str, conv->ret, conv->retnew);
	free(str);
	free(conv->result);
	conv->result = temp;
	conv->ret += conv->retnew;
}
