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

void		print_list(t_list **list)
{
	t_list *item;
	t_list *temp;
	item = *list;
	int	items;

	items = 0;
	while (item != NULL)
	{
		if (item->content_size == 48)
		{
			ft_printf("%s\n", (((t_op *)(item->content))->name));
			ft_printf("arg1: %i\n", (((t_op *)(item->content))->argtypes[0]));
			ft_printf("arg2: %i\n", (((t_op *)(item->content))->argtypes[1]));
			ft_printf("arg2: %i\n", (((t_op *)(item->content))->argtypes[2]));
		}
		temp = item;
		item = item->next;
		free (temp->content);
		free (temp);
		items++;
	}
	ft_printf("items: %i\n", items);
}
