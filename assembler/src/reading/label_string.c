/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:50:22 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/05 15:50:22 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				label_string(char *argument, char *allowed_chars)
{
	int			i;

	i = 0;
	while (argument[i])
	{
		if (!ft_strchr(allowed_chars, argument[i]))
			return (false);
		i++;
	}
	return (true);
}
