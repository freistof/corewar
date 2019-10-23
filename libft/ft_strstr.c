/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 08:30:46 by lvan-vlo      #+#    #+#                 */
/*   Updated: 2019/01/20 16:36:21 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		hc;
	int		nc;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	hc = 0;
	if (n[0] == '\0')
		return (&h[hc]);
	while (h[hc] != '\0')
	{
		nc = 0;
		while (h[hc + nc] == n[nc] && n[nc] != '\0')
		{
			nc++;
			if (n[nc] == '\0')
				return (&h[hc]);
		}
		hc++;
	}
	return (NULL);
}
