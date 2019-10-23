/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 15:15:35 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/18 15:16:02 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
