/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byte_to_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 14:07:05 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/12 13:46:41 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int				args_to_int(unsigned char arg1, unsigned char arg2, \
unsigned char arg3)
{
	int rtn;

	rtn = arg1 << 6;
	rtn += arg2 << 4;
	rtn += arg3 << 2;
	return (rtn);
}

int				byte_to_int(unsigned char *board, int position)
{
	int		rtn;

	rtn = (unsigned char)board[position % MEM_SIZE] << 24;
	rtn += (unsigned char)board[(position + 1) % MEM_SIZE] << 16;
	rtn += (unsigned char)board[(position + 2) % MEM_SIZE] << 8;
	rtn += (unsigned char)board[(position + 3) % MEM_SIZE];
	return (rtn);
}

unsigned char	*int_to_byte(int value)
{
	unsigned char *byte;

	byte = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 8);
	byte[0] = (value >> 24) & 255;
	byte[1] = (value >> 16) & 255;
	byte[2] = (value >> 8) & 255;
	byte[3] = value & 255;
	return (byte);
}

int				byte_to_hex(unsigned char *board, int position)
{
	int	rtn;

	rtn = (unsigned char)board[(position) % MEM_SIZE] << 8;
	rtn += (unsigned char)board[(position + 1) % MEM_SIZE];
	return (rtn);
}
