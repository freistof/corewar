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

void		print_list(t_list *item)
{
	t_list *temp;
	int	items;

	items = 0;
	while (item != NULL)
	{
		if (item->content_size == sizeof(t_op))
		{
			ft_printf("instruction: %s\n", (((t_op *)(item->content))->name));
			ft_printf("arg1: %i\n", (((t_op *)(item->content))->argtypes[0]));
			ft_printf("arg2: %i\n", (((t_op *)(item->content))->argtypes[1]));
			ft_printf("arg2: %i\n", (((t_op *)(item->content))->argtypes[2]));
			if ((((t_op *)(item->content))->argvalues[0].label))
			{
				ft_printf("value1: %s\n", (((t_op *)(item->content))->argvalues[0].label));
				free((((t_op *)(item->content))->argvalues[0].label));
			}
			else
				ft_printf("value1: %i\n", (((t_op *)(item->content))->argvalues[0].value));
			if ((((t_op *)(item->content))->argvalues[1].label))
			{
				ft_printf("value2: %s\n", (((t_op *)(item->content))->argvalues[1].label));
				free((((t_op *)(item->content))->argvalues[1].label));
			}
			else
				ft_printf("value2: %i\n", (((t_op *)(item->content))->argvalues[1].value));
			if ((((t_op *)(item->content))->argvalues[2].label))
			{
				ft_printf("value3: %s\n", (((t_op *)(item->content))->argvalues[2].label));
				free((((t_op *)(item->content))->argvalues[2].label));
			}
			else
				ft_printf("value3: %i\n", (((t_op *)(item->content))->argvalues[2].value));

		}
		else
		{
			if (item->content)
				ft_printf("label: %s\n", (((t_op *)item->content)));
		}
		temp = item;
		item = item->next;
		// free (temp->content);
		// free (temp);
		items++;
		ft_printf("\n");
	}
	ft_printf("items: %i\n", items);
}
