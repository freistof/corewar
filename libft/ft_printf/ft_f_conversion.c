/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_f_conversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 13:10:44 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 15:58:52 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fix_dec(char *ret, int i)
{
	if (ret[i] == '.')
		i--;
	if (ret[i] < '9')
		ret[i]++;
	else if (ret[i] == '9' && i != 0)
	{
		ret[i] = '0';
		ft_fix_dec(ret, i - 1);
	}
}

char		*ft_get_dec(long double nbr, t_printf *conv, char *ret)
{
	int		i;
	int		k;

	i = ft_getdigits((long long)nbr) + 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	k = i;
	while (i < conv->precision + k)
	{
		nbr *= 10;
		ret[i] = (long long)nbr % 10 + '0';
		nbr -= (long long)nbr;
		i++;
	}
	if (nbr * 10 >= 5)
		ft_fix_dec(ret, i - 1);
	ret[i] = '\0';
	return (ret);
}

char		*f_conversion(long double nbr, t_printf *conv)
{
	char			*n;
	char			*ret;
	int				len;
	long long		tmp;

	len = ft_getdigits((long long)nbr);
	if (nbr < 0)
		len++;
	if (conv->precision < 0)
		conv->precision = 6;
	len += conv->precision + 1;
	ret = ft_strnew(len);
	if ((nbr - (int)nbr) * 10 > (float)5.00000000000000000 \
		&& (conv->precision <= 0 || (conv->alternate && conv->precision == 0)))
		nbr += (int)1;
	tmp = (long long)nbr;
	n = ft_itoa_base(tmp, 10, 0);
	ft_strcpy(ret, n);
	free(n);
	if ((!conv->precision && conv->alternate) || conv->precision > 0)
		ret[len - conv->precision - 1] = '.';
	if (conv->precision > 0)
		ret = ft_get_dec(nbr, conv, ret);
	conv->retnew = ft_strlen(ret);
	return (ret);
}
