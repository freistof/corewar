/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_comment_length.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:10:32 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 14:55:17 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char		*trim_comment(char *comment)
{
	char *rtn;

	if (ft_strlen(comment) > 48)
	{
		rtn = ft_strsub(comment, 0, 48);
		ft_memcpy(&rtn[45], "...", 3);
		return (rtn);
	}
	else
		rtn = ft_strdup(comment);
	return (rtn);
}
