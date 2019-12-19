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

void			set_arguments(int fd, t_op *instruction, t_list **head)
{
	int			i;

	i = 0;
	while (i < instruction->number_of_arguments)
	{
		if (instruction->argtypes[i] == T_DIR)
			write_direct(fd, instruction, i, head);
		if (instruction->argtypes[i] == T_REG)
			write_register(fd, instruction, i);
		if (instruction->argtypes[i] == T_IND)
			write_ind(fd, instruction, i, head);
		i++;
	}
}

void			set_encode_byte(int fd, int *encode_byte)
{
	int			i;
	char		codage;
	int			shift;

	i = 0;
	codage = 0;
	shift = 6;
	while (i < 3)
	{
		if (encode_byte[i] != 0)
		{
			if (encode_byte[i] == 4)
				encode_byte[i] = 3;
			codage += ((encode_byte[i])) << shift;
			if (encode_byte[i] == 3)
				encode_byte[i] = 4;
		}
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
	t_list		*head;

	head = list;
	while (list)
	{
		if (list->content_size == sizeof(t_op))
		{
			set_opcode(fd, (((t_op *)list->content))->opcode);
			if ((((t_op *)list->content))->codage_octal)
				set_encode_byte(fd, (((t_op *)list->content))->argtypes);
			set_arguments(fd, list->content, &head);
		}
		list = list->next;
	}
}
