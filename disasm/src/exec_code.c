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

static int		codage(fd_in)
{
	unsigned char		reading;

	read(fd_in, &reading, 1);
	return (reading);
}

static int		opcode(fd_in, fd_out)
{
	unsigned char		reading;
	int					ret;

	ret = read(fd_in, &reading, 1);
	ft_printf("%i\n", reading);
	ft_printf("name: %s\n", g_op_tab[reading - 1].name);
	write(fd_out, g_op_tab[reading - 1].name, ft_strlen(g_op_tab[reading - 1].name));
	write(fd_out, " ", 1);
	return (reading - 1);
}

void			exec_code(int fd_in, int fd_out, int size)
{
	int			op;
	int			cod;

	while (1)
	{
		ft_printf("loop\n");
	cod = 0;
	op = opcode(fd_in, fd_out);
	if (g_op_tab[op].codage_octal)
		cod = codage(fd_in);
	arguments(fd_in, fd_out, cod, g_op_tab[op].number_of_arguments, op);
	size = 0;
}
}
