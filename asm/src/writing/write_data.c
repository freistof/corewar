/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:06:25 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 14:06:26 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_data(t_list *list)
{
	int			fd;

	fd = open("42.cor", O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd == -1)
		error("Could not create file\n");
	ft_printf("fd: %i\n", fd);
	write_magic(fd);
	write_name(fd, list);
	// write_comment();
	// write_null();
	// write_size();
	// write_comment();
	// write_null();
	// write_exec_code();
	while (list)
	{
		if (list->content_size == sizeof(t_op))
			; //ft_printf("instruction: %i\n", (((t_op *)(list->content))->opcode));
		list = list->next;
	}
}
