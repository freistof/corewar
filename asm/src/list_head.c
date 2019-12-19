/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_head.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 14:42:49 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/19 14:42:49 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list			*list_head(t_list *list)
{
	static t_list *head;

	if (!head)
		head = list;
	return (head);
}
