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
extern t_op g_op_tab[17];

void		print_list(t_list **list)
{
	t_list *item;
	t_list *temp;
	int i;

	item = *list;
	i = 0;
	while (item != NULL)
	{
		if (item->content_size != 0)
		{
			if (i < 2)
				ft_printf("name/comment: %s\n", item->content);
			else if (item->content_size == 48)
				ft_printf("content: %s\n", (char *)(((t_op *)(item->content))->name));
			else
				ft_printf("label: %s\n", item->content);
		}
		temp = item;
		item = item->next;
		free (temp->content);
		free (temp);
		i++;
	}
	ft_printf("list_items: %i\n", i);
}
