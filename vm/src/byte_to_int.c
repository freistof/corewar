/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byte_to_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 14:07:05 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/14 17:15:06 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		args_to_int(unsigned char arg1, unsigned char arg2, unsigned char arg3)
{
	int rtn;

	rtn = arg1 << 6;
	rtn += arg2 << 4;
	rtn += arg3 << 2;
	return (rtn);
}

int		byte_to_int(unsigned char *board, int position)
{
	int		rtn;
	
	rtn = (unsigned char)board[position % MEM_SIZE] << 24;
	rtn += (unsigned char)board[(position + 1) % MEM_SIZE] << 16;
	rtn += (unsigned char)board[(position + 2) % MEM_SIZE] << 8;
	rtn += (unsigned char)board[(position + 3) % MEM_SIZE];
	return (rtn);
}
