/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_code.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:17:15 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 17:17:15 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			set_encode_byte(int fd, int *encode_byte)
{
	int	i;
	unsigned char codage;
	int	shift;

	i = 0;
	codage = 0;
	shift = 6;
	while (i < 3)
	{
		if (encode_byte[i] != 0)
			codage |= (encode_byte[i]) << shift;
		i++;
		shift -= 2;
	}
	write(fd, &codage, 1);
}

void			set_opcode(int fd, int opcode)
{
	write(fd, &opcode, 1);
}

void			write_exec_code(int fd, t_list *list)
{
	while (list)
	{
		if (list->content_size == sizeof(t_op))
		{
			set_opcode(fd, (((t_op *)list->content))->opcode);
			if ((((t_op *)list->content))->codage_octal)
				set_encode_byte(fd, (((t_op *)list->content))->argtypes);
		}
		list = list->next;
	}
}
