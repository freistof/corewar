/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_end.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 11:45:47 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/19 11:45:47 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_end(char *content, int i, int len)
{
	remove_comments(&content[i + len + 2]);
	while (content[i + len + 2])
	{
		if (!ft_isspace(content[i + len + 2]))
			error(SYNTAX_ERROR);
		i++;
	}
}
