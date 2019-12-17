/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_to_board.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 15:47:03 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/17 14:39:24 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	new_mod(int value)
{
	int rtn;

	rtn = value % MEM_SIZE;
	if (rtn < 0)
		rtn += MEM_SIZE;
	return (rtn);
}

void	write_to_board(unsigned char *board, int cur_pos, int position, \
unsigned char *byte)
{

	position += cur_pos;
	board[new_mod(position)] = byte[0];
	board[new_mod(position + 1)] = byte[1];
	board[new_mod(position + 2)] = byte[2];
	board[new_mod(position + 3)] = byte[3];
}
