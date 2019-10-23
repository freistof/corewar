/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   csp_conversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 08:44:15 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 12:37:56 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_conversion(unsigned char c, t_printf *conv)
{
	char	*ret;

	ret = (char*)ft_memalloc(sizeof(char));
	*ret = c;
	conv->retnew = 1;
	return (ret);
}

char	*s_conversion(char *src, t_printf *conv)
{
	char	*dst;

	if (conv->precision == 0)
	{
		dst = ft_strdup("\0");
		return (dst);
	}
	if (src)
	{
		if (conv->precision < 1)
			dst = ft_strdup(src);
		else
			dst = ft_strsub(src, 0, conv->precision);
		conv->retnew = ft_strlen(dst);
		if (conv->letter == 'S')
			ft_capital(dst, 1);
		return (dst);
	}
	else
	{
		conv->retnew = 6;
		dst = ft_strdup("(null)");
		return (dst);
	}
}

char	*p_conversion(unsigned long n, t_printf *conv, int capital)
{
	char	*str;
	char	*ret;
	char	*tmp;

	if (capital == 0)
		tmp = ft_strdup("0x");
	else
		tmp = ft_strdup("0X");
	str = ft_itoa_base(n, 16, capital);
	ret = ft_strjoin(tmp, str);
	ft_del_two(str, tmp);
	if (n == 0 && conv->precision >= 0)
	{
		tmp = ft_strsub(ret, 0, 2);
		str = ft_strnew(conv->precision);
		ft_memset(str, '0', conv->precision);
		free(ret);
		ret = ft_strjoin(tmp, str);
		ft_del_two(str, tmp);
	}
	else if (conv->precision >= 0)
		conv->precision += 2;
	conv->retnew = ft_strlen(ret);
	return (ret);
}
