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

void	write_direct_big(t_op *instruction, int arg, int fd, t_list **head)
{
	unsigned long long argument;

	if (instruction->argvalues[arg].label)
	{
		argument = label_direct_value(instruction->argvalues[arg].label,\
			head, instruction->position);
		argument = swap_bits(argument);
		write(fd, &argument, 4);
	}
	else
	{
		argument = instruction->argvalues[arg].value;
		argument = swap_bits(argument);
		write(fd, &argument, 4);
	}
}

void	write_direct_small(t_op *instruction, int arg, int fd, t_list **head)
{
	unsigned long long s_arg;

	if (instruction->argvalues[arg].label)
	{
		s_arg = label_direct_value(instruction->argvalues[arg].label,\
			head, instruction->position);
		s_arg = swap_bits_two_byte(s_arg);
		write(fd, &s_arg, 2);
	}
	else
	{
		s_arg = (short)instruction->argvalues[arg].value;
		s_arg = swap_bits_two_byte(s_arg);
		write(fd, &s_arg, 2);
	}
}

void	write_direct(int fd, t_op *instruction, int arg, t_list **head)
{
	if (instruction->label_size)
		write_direct_small(instruction, arg, fd, head);
	else
		write_direct_big(instruction, arg, fd, head);
}

void	write_ind(int fd, t_op *instruction, int arg, t_list **head)
{
	write_direct_small(instruction, arg, fd, head);
}

void	write_register(int fd, t_op *instruction, int arg)
{
	int		argument;

	argument = instruction->argvalues[arg].value;
	write(fd, &argument, 1);
}
