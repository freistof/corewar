/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_indirect.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:02:05 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:02:05 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		save_indirect(char *argument, t_list *item, int argno)
{
	if (ft_isdigit(argument[0]) || argument[0] == '-')
		(((t_op *)(item->content))->argvalues[argno]).value = ft_atoi(argument);
	else
	{
		argument += 1;
		(((t_op *)(item->content))->argvalues[argno]).label = \
		ft_strdup(argument);
	}
	((t_op *)(item->content))->size += 2;
}

int			check_indirect(char *argument)
{
	if (argument[0] == ':')
	{
		if (!label_string(argument + 1, LABEL_CHARS))
			return (false);
	}
	else
	{
		if (!digit_string(argument))
			return (false);
	}
	return (true);
}
