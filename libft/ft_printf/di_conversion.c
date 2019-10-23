/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   di_conversion.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 09:19:37 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 14:21:05 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_exception(t_printf *conv)
{
	if (conv->precision < conv->retnew || conv->retnew == 0 \
		|| conv->letter == 'c' || (ft_strchr("sS", conv->letter) \
			&& conv->precision > conv->retnew))
		return (1);
	return (0);
}

char	*ft_make_space_plus(char *str, t_printf *conv)
{
	char	*ret;

	if (conv->plus == 1)
		ret = ft_strnjoin("+", str, 1, conv->retnew);
	else
		ret = ft_strnjoin(" ", str, 1, conv->retnew);
	conv->retnew++;
	free(str);
	return (ret);
}

char	*di_conversion(void *input, t_printf *conv)
{
	char	*ret;

	if (conv->l == 1 || conv->letter == 'D')
		ret = ft_itoa_base((long)input, 10, 0);
	else if (conv->l == 2)
		ret = ft_itoa_base((long long)input, 10, 0);
	else if (conv->j == 1)
		ret = ft_itoa_base((intmax_t)input, 10, 0);
	else if (conv->z == 1)
		ret = ft_itoa_base((size_t)input, 10, 0);
	else if (conv->h == 1)
		ret = ft_itoa_base((short)input, 10, 0);
	else if (conv->h == 2 && !conv->l)
		ret = ft_itoa_base((signed char)input, 10, 0);
	else
		ret = ft_itoa_base((int)input, 10, 0);
	conv->retnew = ft_strlen(ret);
	if ((conv->plus == 1 || conv->space == 1) && ft_strchr(ret, '-') == NULL)
		ret = ft_make_space_plus(ret, conv);
	return (ret);
}
