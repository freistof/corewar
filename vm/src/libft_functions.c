/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:40:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 15:59:14 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_is_string_numbers(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!ft_isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}

long		ft_long_atoi(const char *str)
{
	int		x;
	long	result;
	long	pn;

	pn = 1;
	result = 0;
	x = 0;
	while (str[x] == '\f' || str[x] == '\v' || str[x] == '\r' || str\
	[x] == '\t' || str[x] == '\n' || str[x] == ' ')
		x++;
	if (str[x] == '-')
	{
		pn = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (str[x] - 48);
		x++;
	}
	return (result * pn);
}

static int	recursive_check(char *str, int x, int len)
{
	char check_str[19];

	if (str[0] == '-')
		ft_strcpy(check_str, MIN_LONG_STR);
	else
		ft_strcpy(check_str, MAX_LONG_STR);
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

int			ft_fits_in_long(char *str)
{
	if (ft_strlen(str) > 19 || (ft_strlen(str) == 19 && str[0] != '-'))
		return (0);
	if (ft_strlen(str) == 18 || (ft_strlen(str) == 19 && str[0] == '-'))
	{
		if (recursive_check(str, 0, ft_strlen(str)) == 0)
			return (0);
	}
	return (1);
}
