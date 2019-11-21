/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 12:06:15 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/20 12:06:15 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void		print_list(t_list **list)
{
	t_list *item;
	t_list *temp;
	item = *list;

	while (item != NULL)
	{
		ft_printf("content: %s\n", item->content);
		temp = item;
		item = item->next;
		free (temp->content);
		free (temp);

	}
}