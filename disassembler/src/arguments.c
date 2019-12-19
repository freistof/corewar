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

static int		write_register(int fd_in, int fd_out)
{
	char				reading;
	char				*number;
	int					ret;

	ret = read(fd_in, &reading, 1);
	if (ret <= 0)
		exit(1);
	write(fd_out, "r", 1);
	number = ft_itoa(reading);
	write(fd_out, number, ft_strlen(number));
	free(number);
	return (1);
}

static int		write_indirect(int fd_in, int fd_out)
{
	short		reading;
	char		*number;
	int			ret;

	ret = read(fd_in, &reading, 2);
	if (ret <= 0)
		exit(1);
	reading = swap_bits_two_byte(reading);
	number = ft_itoa(reading);
	write(fd_out, number, ft_strlen(number));
	free(number);
	return (2);
}

static void		get_direct_number(int fd_in, int size, char **number)
{
	int			ret;
	int			reading;
	int			readshort;

	if (size == 4)
	{
		ret = read(fd_in, &reading, size);
		if (ret <= 0)
			exit(1);
		reading = swap_bits(reading);
		*number = ft_itoa(reading);
	}
	else
	{
		ret = read(fd_in, &readshort, size);
		if (ret <= 0)
			exit(1);
		readshort = swap_bits_two_byte(readshort);
		*number = ft_itoa(readshort);
	}
}

static int		write_direct(int fd_in, int fd_out, int opcode)
{
	char				*number;
	int					size;

	if (g_op_tab[opcode].label_size)
		size = 2;
	else
		size = 4;
	get_direct_number(fd_in, size, &number);
	write(fd_out, "%", 1);
	write(fd_out, number, ft_strlen(number));
	free(number);
	return (size);
}

void			arguments(int fd_in, int fd_out, t_data *data)
{
	int			i;
	int			type;
	int			arg_count;

	i = 0;
	arg_count = g_op_tab[data->opcode].number_of_arguments;
	while (i < arg_count)
	{
		if (data->codage)
			type = extract_bit(data->codage, 2, i);
		else
			type = 2;
		if (type == 0)
			exit(1);
		if (type == 1)
			data->i += write_register(fd_in, fd_out);
		if (type == 3)
			data->i += write_indirect(fd_in, fd_out);
		if (type == 2)
			data->i += write_direct(fd_in, fd_out, data->opcode);
		if (i < arg_count - 1)
			write(fd_out, ",", 1);
		i++;
	}
	write(fd_out, "\n", 1);
}
