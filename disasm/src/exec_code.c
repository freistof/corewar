/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_code.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:51:25 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 18:51:25 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

extern t_op g_op_tab[17];

static int		codage(int fd_in, int op)
{
	unsigned char		reading;

	if (!(g_op_tab[op].codage_octal))
		return (0);
	read(fd_in, &reading, 1);
	return (reading);
}

static int		opcode(int fd_in, int fd_out)
{
	unsigned char		reading;
	int					ret;

	ret = read(fd_in, &reading, 1);
	if (ret == -1)
		exit(1);
	write(fd_out, g_op_tab[reading - 1].name,\
		ft_strlen(g_op_tab[reading - 1].name));
	write(fd_out, " ", 1);
	return (reading - 1);
}

void			exec_code(int fd_in, int fd_out, int size)
{
	t_data		data;

	data.i = 0;
	while (data.i < size)
	{
		data.opcode = opcode(fd_in, fd_out);
		data.i++;
		data.codage = codage(fd_in, data.opcode);
		if (data.codage)
			data.i++;
		arguments(fd_in, fd_out, &data);
	}
}
