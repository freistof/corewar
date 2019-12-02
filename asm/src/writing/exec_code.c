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
	int			i;
	unsigned char		codage;
	unsigned char		swapped;

	i = 0;
	codage = 0;
	while (i < 3)
	{
		ft_printf("%i ", encode_byte[i]);
		if (encode_byte[i] != 0)
			codage |= 1 << (encode_byte[i]);
		i++;
	}
	ft_printf("\n%i\n", (int)codage);
	swapped = ((codage>>6)&0x03) |
			((codage<<2)&0x0f) |
			((codage>>2)&0x3f) |
			((codage<<6)&0xff);
	ft_printf("\n%i\n", (int)swapped);
	write(fd, &swapped, 1);
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
