/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 18:28:19 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/10 18:28:19 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		empty_line(char *content)
{
	int			i;

	i = 0;
	while (content[i] != '\0')
	{
		if (ft_isspace(content[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
