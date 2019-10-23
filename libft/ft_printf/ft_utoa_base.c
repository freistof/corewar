/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 11:09:51 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/03/31 15:50:02 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_udigits_base(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / (unsigned long long)base;
		i++;
	}
	return (i);
}

char	*ft_utoa_base(unsigned long long n, int base, int capital)
{
	char	*tab;
	char	*ret;
	int		l;

	if (base > 16 || base < 2 || n == 0)
		return (ft_strdup("0"));
	l = ft_udigits_base(n, base);
	tab = "0123456789abcdef";
	ret = (char*)ft_memalloc(sizeof(char) * l + 1);
	ret[l] = '\0';
	while (l > 0)
	{
		ret[l - 1] = tab[n % (unsigned long long)base];
		n = n / base;
		l--;
	}
	return (ft_capital(ret, capital));
}

int		ft_uimdigits_base(uintmax_t n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_uimtoa_base(uintmax_t n, int base, int capital)
{
	char					*tab;
	char					*ret;
	unsigned long long		l;

	if (base > 16 || base < 2 || n == 0)
		return (ft_strdup("0"));
	l = ft_uimdigits_base((uintmax_t)n, base);
	tab = "0123456789abcdef";
	ret = (char*)ft_memalloc(sizeof(char) * l + 1);
	ret[l] = '\0';
	while (l > (unsigned long long)0)
	{
		ret[l - 1] = tab[n % base];
		n = n / base;
		l--;
	}
	return (ft_capital(ret, capital));
}
