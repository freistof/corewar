/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_direct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:01:58 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:01:58 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		save_direct(char *argument, t_list *item, int argno)
{
	if (ft_isdigit(argument[0]) || argument[0] == '-')
		(((t_op *)(item->content))->argvalues[argno]).value = ft_atoi(argument);
	else
	{
		argument += 1;
		(((t_op *)(item->content))->argvalues[argno]).label = \
		ft_strdup(argument);
	}
	if (((t_op *)(item->content))->label_size)
		((t_op *)(item->content))->size += 2;
	else
		((t_op *)(item->content))->size += 4;
}

int			check_direct(char *argument)
{
	return (check_indirect(argument));
}
