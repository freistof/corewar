/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:52:35 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/01/30 15:08:22 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlchr(char *s, char c, size_t len)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}
