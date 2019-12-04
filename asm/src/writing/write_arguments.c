/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_arguments.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 10:34:57 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/04 10:34:57 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_direct(int fd, t_op *instruction, int arg)
{
	int		argument;
	short	s_arg;

	if (instruction->label_size)
	{
		if (instruction->argvalues[arg].value)
		{
			s_arg = instruction->argvalues[arg].value;

			write(fd, &s_arg, 2);
		}
		else
			write(fd, "\0\0", 2);
	}
	else
	{
		if (instruction->argvalues[arg].value)
		{
			argument = instruction->argvalues[arg].value;
			argument = swap_bits(argument);
			write(fd, &argument, 4);
		}
		else
			write(fd, "\0\0", 4);
	}
}

void		write_indirect(int fd, t_op *instruction, int arg)
{
	int		argument;

	if (instruction->argvalues[arg].value)
	{
		argument = instruction->argvalues[arg].value;
		argument = swap_bits(argument);
		write(fd, &argument, 2);
	}
	else
		write(fd, "\0\0", 2);	
}

void		write_register(int fd, t_op *instruction, int arg)
{
	int		argument;

	argument = instruction->argvalues[arg].value;
	argument = swap_bits(argument);
	write(fd, &argument, 1);	
}