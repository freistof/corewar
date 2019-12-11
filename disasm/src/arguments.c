/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 19:40:58 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 19:40:58 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"
extern t_op g_op_tab[17];

static int		extract_bit(int n, int k, int p)
{
	if (p == 0)
		p = 1;
	else if (p == 1)
		p = 3;
	else if (p == 2)
		p = 5;
    return (((1 << k) - 1) & (n >> (p - 1))); 
}

static void		write_register(int fd_in, int fd_out)
{
	unsigned char		reading;
	char				*number;

	read(fd_in, &reading, 1);
	write(fd_out, "r", 1);
	number = ft_itoa(reading);
	write(fd_out, number, ft_strlen(number));
}

static void		write_indirect(int fd_in, int fd_out)
{
	unsigned short		reading;

	read(fd_in, &reading, 2);
	reading = swap_bits_two_byte(reading);
	write(fd_out, &reading, 1);
}

static void		write_direct(int fd_in, int fd_out, int opcode)
{
	unsigned int		reading;
	unsigned short		readshort;
	char				*number;
	int					size;

	if (g_op_tab[opcode].label_size)
		size = 2;
	else
		size = 4;
	if (size == 2)
	{
		read(fd_in, &reading, size);
		reading = swap_bits_two_byte(reading);
		number = ft_itoa(reading);
	}
	else
	{
		read(fd_in, &readshort, size);
		readshort = swap_bits(readshort);
		number = ft_itoa(readshort);
	}
	write(fd_out, "%", 1);
	write(fd_out, number, ft_strlen(number));
}

void			arguments(int fd_in, int fd_out, int codage, int arg_count, int opcode)
{
	int			i;
	int			type;

	i = 0;
	ft_printf("codage: %i\n", codage);
	while (i < arg_count)
	{
		if (codage)
			type = extract_bit(codage, 2, i);
		else
			type = 2;
		ft_printf("type: %i\n", type);
		if (type == 0)
			write_register(fd_in, fd_out);
		if (type == 1)
			write_indirect(fd_in, fd_out);
		if (type == 2)
			write_direct(fd_in, fd_out, opcode);
		if (i < arg_count - 1)
			write(fd_out, ",", 1);
		i++;
	}
	write(fd_out, "\n", 1);
}
