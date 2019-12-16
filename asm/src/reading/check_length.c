/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 19:25:57 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/16 19:25:57 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				check_length(int type, char *string)
{
	if (type == 5)
	{
		if (ft_strlen(string) > PROG_NAME_LENGTH)
			error("Name length incorrect: error");
	}
	else
	{
		if (ft_strlen(string) > COMMENT_LENGTH)
			error("Comment length incorrect: error");
	}
}
