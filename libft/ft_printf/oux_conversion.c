/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oux_conversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 09:28:48 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 15:45:45 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*o_conversion(void *input, t_printf *conv)
{
	char	*ret;
	char	*tmp;

	if (conv->l == 1 || conv->letter == 'O')
		ret = ft_utoa_base((unsigned long)input, 8, 0);
	else if (conv->l == 2 || conv->z == 1)
		ret = ft_utoa_base((unsigned long long)input, 8, 0);
	else if (conv->h == 1)
		ret = ft_utoa_base((unsigned short)input, 8, 0);
	else if (conv->h == 2)
		ret = ft_utoa_base((unsigned char)input, 8, 0);
	else if (conv->j == 1)
		ret = ft_utoa_base((uintmax_t)input, 8, 0);
	else
		ret = ft_utoa_base((unsigned int)input, 8, 0);
	if (conv->alternate && input)
	{
		tmp = ft_strjoin("0", ret);
		free(ret);
		ret = tmp;
		if (conv->precision < (int)ft_strlen(ret))
			conv->precision = ft_strlen(ret);
	}
	conv->retnew = ft_strlen(ret);
	return (ret);
}

char	*u_conversion(void *input, t_printf *conv)
{
	char	*ret;

	if (conv->l == 1 || conv->letter == 'U')
		ret = ft_utoa_base((unsigned long)input, 10, 0);
	else if (conv->l == 2 || conv->z == 1)
		ret = ft_utoa_base((unsigned long long)input, 10, 0);
	else if (conv->h == 1)
		ret = ft_utoa_base((unsigned short)input, 10, 0);
	else if (conv->h == 2)
		ret = ft_utoa_base((unsigned char)input, 10, 0);
	else if (conv->j == 1)
		ret = ft_utoa_base((uintmax_t)input, 10, 0);
	else
		ret = ft_utoa_base((unsigned int)input, 10, 0);
	conv->retnew = ft_strlen(ret);
	return (ret);
}

char	*x_conversion(void *input, t_printf *conv, int capital)
{
	char	*ret;

	if (conv->letter == 'X')
		capital = 1;
	if (conv->alternate && input)
		return (p_conversion((unsigned long)input, conv, capital));
	else if (conv->h == 1)
		ret = ft_utoa_base((unsigned short)input, 16, capital);
	else if (conv->h == 2)
		ret = ft_utoa_base((unsigned char)input, 16, capital);
	else if (conv->l == 1)
		ret = ft_utoa_base((unsigned long)input, 16, capital);
	else if (conv->l == 2 || conv->z == 1)
		ret = ft_utoa_base((unsigned long long)input, 16, capital);
	else if (conv->j == 1)
		ret = ft_uimtoa_base((uintmax_t)input, 16, capital);
	else
		ret = ft_utoa_base((unsigned int)input, 16, capital);
	conv->retnew = ft_strlen(ret);
	return (ret);
}
