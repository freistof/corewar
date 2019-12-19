/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:23:03 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/14 16:23:05 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_returner(unsigned long long result, int is_negative)
{
	if (result > 1844674407370955161 && is_negative == -1)
		return (0);
	if (result > 1844674407370955161)
		return (-1);
	return (result * is_negative);
}

static int		negative(int *i, char *str)
{
	if (str[*i] == '-')
		return (-1);
	else if (str[*i] == '+')
		return (1);
	else
	{
		*i -= 1;
		return (1);
	}
}

int				ft_atoi(const char *str)
{
	int					i;
	int					is_negative;
	unsigned long long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	is_negative = negative(&i, (char *)str);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result == 1844674407370955161 && str[i] > '5')
		{
			result = -1;
			break ;
		}
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (ft_atoi_returner(result, is_negative));
}
