/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 14:44:27 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/19 14:44:27 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_list(t_list *list)
{
	t_list	*temp;

	while (list->next)
	{
		free(list->content);
		temp = list;
		list = list->next;
		free(temp);
	}
}

