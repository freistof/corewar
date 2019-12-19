/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fits_in_int.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 11:40:22 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 18:11:41 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

static int	recursive_check(char *str, int x, int len)
{
	char check_str[12];

	if (str[0] == '-')
		ft_strcpy(check_str, ft_itoa(INT32_MIN));
	else
		ft_strcpy(check_str, ft_itoa(INT32_MAX));
	if (x >= len)
		return (1);
	else if (x == 0 && str[x] == '-')
		return (recursive_check(str, x + 1, len));
	else if (str[x] < check_str[x])
		return (1);
	else if (str[x] > check_str[x])
		return (0);
	return (recursive_check(str, x + 1, len));
}

int			ft_fits_in_int(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len > 11 || (len == 11 && str[0] != '-'))
		return (0);
	if (len == 10 || (len == 11 && str[0] == '-'))
	{
		if (recursive_check(str, 0, len) == 0)
			return (0);
	}
	return (1);
}
