/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 12:21:34 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/04 12:21:34 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_size(int fd, t_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		if (list->content_size == sizeof(t_op))
			size += (((t_op *)list->content))->size;
		list = list->next;
	}
	size = swap_bits(size);
	write(fd, &size, 4);
}
