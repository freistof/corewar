/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 10:39:14 by fblom          #+#    #+#                */
/*   Updated: 2019/04/05 11:20:00 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_capital(char *ret, int capital)
{
	int i;

	i = 0;
	if (capital == 1)
	{
		while (ret[i] != '\0')
		{
			if (ret[i] >= 'a' && ret[i] <= 'f')
				ret[i] -= 32;
			i++;
		}
	}
	return (ret);
}

int		ft_digits_base(long long n, int base)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / (long long)base;
		i++;
	}
	return (i);
}

int		ft_make_neg(char *ret)
{
	ret[0] = '-';
	return (-1);
}

char	*ft_itoa_base(long long n, int base, int capital)
{
	char	*tab;
	char	*ret;
	int		l;
	int		neg;

	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	neg = 0;
	if (base > 16 || base < 2 || n == 0)
		return (ft_strdup("0"));
	l = ft_digits_base(n, base);
	tab = "0123456789abcdef";
	ret = ft_strnew(l);
	if (n < 0)
	{
		n *= ft_make_neg(ret);
		neg++;
	}
	while (l > neg)
	{
		ret[l - 1] = tab[n % (long long)base];
		n = n / base;
		l--;
	}
	return (ft_capital(ret, capital));
}
